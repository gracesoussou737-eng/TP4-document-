CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -g
all : test_tp3 main
test_tp3 : pile.c file.c calc.c test_tp3.c
$(CC) $(CFLAGS) pile.c file.c calc.c test_tp3.c -o test_tp3
main : pile.c file.c calc.c main.c
$(CC) $(CFLAGS) pile.c file.c calc.c main.c -o main
test : test_tp3
./test_tp3
clean :
rm -f test_tp3 main
