base: base.o
	gcc -m32 -Wall -g -o base base.o

base.o: base.c
	gcc -m32 -Wall -g -c -o base.o base.c

.PHONY: clean

clean:
	rm -f *.o base