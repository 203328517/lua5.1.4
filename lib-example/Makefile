CC = gcc
CFLAGS= -O0 -g -Wall -I ../src
LIBS = -lm
# DO NOT DELETE

linux: table.o
	$(CC) $(LIBS) table.o ../src/liblua.a -o table
	rm -f *.o

table.o:
	$(CC) -c $(CFLAGS) table.c -o $@

clean:
	rm -f *.o
	rm -f table