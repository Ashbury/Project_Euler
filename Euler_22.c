/*
** Using names.txt (Euler_22.txt), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
**
** For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
**
** What is the total of all the name scores in the file?
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

static int		get_file(char **file, size_t *len)
{
	int			fd;
	struct stat	file_stats;

	if ((fd = open("Euler_22.txt", O_RDONLY)) < 0)
	{
		dprintf(2, "Error while opening file.\n");
		return 0;
	}
	if (fstat(fd, &file_stats) < 0)
	{
		close(fd);
		dprintf(2, "Error while fstating file.\n");
		return 0;
	}
	*len = (size_t)(file_stats.st_size);
	if ((*file = mmap(0, *len, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		close(fd);
		dprintf(2, "Error while mapping the file\n");
		return 0;
	}
	close(fd);
	return 1;
}

/*
** Here, I know that names contains only uppercase characters, and I exploit this fact.
** I start my iterator to 1 and stop to len -1 to avoid quote marks.
** I use the @ because it is just before 'A' in the ascii table.
*/
static size_t	compute_name_value(char *name)
{
	size_t	len = strlen(name) - 1;
	size_t	ret = 0;
	for(size_t i = 1; i < len; i++)
	{
		ret += name[i] - '@';
	}
	return ret;
}

static void		euler_22(char *file)
{
	char	*name = strtok(file, ",");
	size_t	result = compute_name_value(name);
	size_t	i = 2;

	while ((name = strtok(NULL, ",") != NULL))
	{
		result += compute_name_value(name) * i;
		i++;
	}
	printf("Result: %zu.", result);
}

int				main(void)
{
	int		len = 0;
	char	*file;

	if (get_file(&file, &len) == 0)
		return -1;

	euler_22(file);
	return 0;
}