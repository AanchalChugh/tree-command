try: main.o file.o printtree.o createtree.o node.o init.o
        cc main.o file.o printree.o createtree.o node.o init.o -o try
main.o: main.c init.h
        cc -c main.c
file.o: file.c init.h
        cc -c file.c
printree.o : printtree.o init.h
        cc -c printtree.c
createtree.o : createtree.o init.h
        cc -c createtree.c
node.o : node.c init.h
        cc -c node.c
init.o : init.c init.h
        cc -c init.c
clean: rm*o
