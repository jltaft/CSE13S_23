CC= gcc
SOURCE=test_ll_cycle.c ll_cycle.c
OBJ=test_ll_cycle.o ll_cycle.o
HEADER=ll_cycle.h
FLAGS =-Wall -Wextra -Wpedantic

check_cycle: ${OBJ} ${HEADER}
	$(CC) $(FLAGS) $(OBJ) -o check_cycle

%.o: %.c $(HEADER)
	$(CC) $< -c

clean:
	rm -rf check_cycle
	rm -rf *.o
