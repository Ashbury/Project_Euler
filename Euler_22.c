/*
** Using names.txt (Euler_22.txt), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
**
** For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
**
** What is the total of all the name scores in the file?
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

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
		ret += (size_t)(name[i] - '@');
	}
	return ret;
}

static void		euler_22(char **names, size_t nb_names)
{
	size_t	result = 0;
	size_t	i = 0;

	while (i < nb_names)
	{
		result += compute_name_value(names[i]) * (i + 1);
		i++;
	}
	printf("Result: %zu\n", result);
}

static char		*strnew(size_t size)
{
	char	*str;

	if ((str = malloc(size + 1)))
	{
		bzero(str, size + 1);
		return (str);
	}
	return (NULL);
}


static char		*strsub(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (str == NULL || len == 0)
		return (strnew(0));
	if (len && strlen(str) >= len && (ret = strnew(len)))
	{
		while (i < len && str[i])
		{
			ret[i] = str[start + i];
			i++;
		}
		ret[len] = '\0';
		return (ret);
	}
	return (NULL);
}

static void		fill(char const *str, char separator, char **result)
{
	int		start;
	size_t	pos;
	size_t	i;

	pos = 0;
	start = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] != separator)
			if (i == 0 || str[i - 1] == separator)
				start = (int)i;
		if (start != -1 && (str[i + 1] == separator || str[i + 1] == '\0'))
		{
			result[pos] = strsub(str, (unsigned int)start,
			i - (unsigned long)start + 1);
			start = -1;
			pos++;
		}
		i++;
	}
}

static char		**strsplit(char const *str, char separator)
{
	char	**result;
	size_t	count;
	size_t	i;

	if (!str)
		return (NULL);
	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] != separator)
			if (i == 0 || str[i - 1] == separator)
				count++;
		i++;
	}
	if (!(result = malloc(sizeof(*result) * (unsigned long)count)))
		return (NULL);
	fill(str, separator, result);
	result[count - 1] = NULL;
	return (result);
}

/*
** Weirdest cast problem I have encountered at the moment.
** I had to use this to be accepted by clang's -Weverything.
** Quite interesting tough. The unix man says:
** The actual arguments to this function are "pointers to
** pointers to char", but strcmp(3) arguments are "pointers
** to char", hence the following cast plus dereference.
*/
static int		compare_names(const void *n1, const void *n2)
{
	return strcmp(*(char * const *)n1, *(char * const *) n2);
}

static void		sort_names(char *names[], size_t len)
{
	qsort(names, len, sizeof(char *), compare_names);
}

static size_t	double_array_len(void **array)
{
	size_t	len = 0;
	while (array[len] != NULL)
		len++;
	return len;
}

int				main(void)
{
	char	*file;
	size_t	file_len = 0;
	char	**names;
	size_t	nb_names;

	if (get_file(&file, &file_len) == 0)
		return -1;

	names = strsplit(file, ',');
	nb_names = double_array_len((void**)names);
	sort_names(names, nb_names);
	euler_22(names, nb_names);
	munmap(file, file_len);
	return 0;
}
