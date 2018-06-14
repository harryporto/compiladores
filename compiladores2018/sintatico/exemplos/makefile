CFLAGS =.g
BISON = bison
FLEX=flex

parcer: parcer.o scanner.o
	$(CC) -o compilador scanner.o parcer.o

parcer.c: parcer.y
	$(BISON) -d -o parcer.c parcer.y

scanner.c: lexico.l
	$(FLEX) -o codigo.c lexico.l

clean:
	rm -f scanner.c scanner.o parcer.c parcer.o parcer.h compilador