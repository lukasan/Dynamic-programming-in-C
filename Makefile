CFLAGS=-Wall -Werror -pedantic -lm

programs = recursive-palindrome dp-palindrome lcs_weighted

all: $(programs)

$(programs): %: %.c

clean:
	rm -f recursive-palindrome recursive-palindrome.o dp-palindrome dp-palindrome.o lcs_weighted lcs_weighted.o