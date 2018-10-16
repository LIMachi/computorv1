OBJECTS := src/main.o src/print.o src/parse.o

all: computorv1

test: all
	./computorv1 "5 + 4 * X + X ^ 2 = X ^ 2"

computorv1: $(OBJECTS)
	gcc $^ -o computorv1

src/%.o: src/%.c
	gcc -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f computorv1

re: fclean all