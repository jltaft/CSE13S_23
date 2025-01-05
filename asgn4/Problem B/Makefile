CC= gcc
SOURCE=growing_arrays.c
OBJ=growing_arrays.o
HEADER=growing_arrays.h
FLAGS =-Wall -Wextra -Wpedantic

growing_arrays: ${OBJ} ${HEADER}
	$(CC) $(FLAGS) $(OBJ) -o growing_arrays

%.o: %.c $(HEADER)
	$(CC) $< -c

clean:
	rm -rf growing_arrays
	rm -rf *.o
