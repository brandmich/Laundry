laundry_list: laundry_list.o readline.o request.o 
	gcc -o laundry_list laundry_list.o readline.o request.o
  
laundry_list.o: laundry_list.c request.h
	gcc -c laundry_list.c
  
readline.o: readline.c readline.h
	gcc -c readline.c

request.o: request.c request.h readline.h
	gcc -c request.c
