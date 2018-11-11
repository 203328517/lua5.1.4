CC = gcc
CFLAGS= -O0 -g3 -Wall -I ../src
LIBS = -lm
# DO NOT DELETE

linux: table.o base.o
	$(CC) $(LIBS) table.o base.o ../src/liblua.a -o table
	rm -f *.o

base.o:
	$(CC) -c $(CFLAGS) base.c -o $@

table.o:
	$(CC) -c $(CFLAGS) table.c -o $@

clean:
	rm -f *.o
	rm -f table
