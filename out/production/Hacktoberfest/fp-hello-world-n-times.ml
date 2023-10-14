let rec f = function
| x when x > 0 -> (
    print_endline "Hello World";
    f (x - 1)
    )
| _ -> ();;

f (read_int())