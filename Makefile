OBJECTS := src/main.o src/print.o src/parse.o

all: computorv1

computorv1: $(OBJECTS)
	gcc $^ -o computorv1

src/%.o: src/%.c
	gcc -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f computorv1

re: fclean all