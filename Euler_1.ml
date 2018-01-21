let rec euler_1 ret i max =
  if i = max then ret
  else if ((i mod 3) = 0) || ((i mod 5) = 0) then euler_1 (ret + i) (i +1) max
  else euler_1 ret (i + 1) max
 
 let () =
   print_endline (string_of_int (euler_1 0 0 1000))
 
