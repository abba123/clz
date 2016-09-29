CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
LDFLAGS =-lm
EXEC = clz


main: *.[ch]
	$(CC) $(CFLAGS) $(LDFLAGS) *.[ch] -o $(EXEC)

plot: main
	./clz 1
	gnuplot plot.gp
	eog runtime.png
