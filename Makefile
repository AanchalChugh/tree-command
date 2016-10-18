try: main.o file.o fileo.o 
	cc main.o file.o fileo.o -o try
main.o: main.c file.h
	cc -c main.c
file.o: file.c file.h
	cc -c file.c
fileo.o: fileo.c file.h
	cc -c fileo.c
clean: rm*o
