CFLAGS=-Wall -Werror -pedantic -lm

programs = recursive-palindrome dp-palindrome

all: $(programs)

$(programs): %: %.c

clean:
	rm -f recursive-palindrome recursive-palindrome.o dp-palindrome dp-palindrome.o