#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int findMin(int a, int b){
    if (a > b) return b;
    else return a;
}

int findMinInserts(char str[], int n)
{
    // Create a table of size n*n. table[i][j]
    // will store minimum number of insertions
    // needed to convert str[i..j] to a palindrome.
    int table[n][n], first, last, gap;

    // Initialize all table entries as 0
    memset(table, 0, sizeof(table));

    // Fill the table
    for (gap = 1; gap < n; ++gap){
        for (first = 0, last = gap; last < n; ++first, ++last){
            if (str[first] == str[last]){
                table[first][last] = table[first+1][last-1];
            }
            else{
                table[first][last] = findMin(
                    table[first][last-1],
                    table[first+1][last]
                ) + 1;
            }
        }
    }
    // Return minimum number of insertions for str[0..n-1]
    return table[0][n-1];
}

int main(int argc, char **argv){
    if (argc != 2){
        printf("Usage: %s inputString\n", __FILE__);
        exit(255);
    }
    
    clock_t t;
    t = clock();
    printf("Minimum insertions: %d\n", findMinInserts(argv[1], strlen(argv[1])));
    t = clock() - t;
    printf("Took %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    return 0;
}