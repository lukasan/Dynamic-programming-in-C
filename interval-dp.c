#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMin(int a, int b){
    if (a > b) return b;
    else return a;
}

int findMinInserts(char *str, int first, int last){
    // Base cases
    if (first == last)
        return 0;
    if (first > last){
        printf("Something went wrong...\n");
        abort();
    }
    if (first == last - 1){
        if (str[first] == str[last])
            return 1;
        else 
            return 0;
    }
    
    // Main case
    if (str[first] == str[last]){
        return findMinInserts(str, first + 1, last - 1);
    }
    else {
        return findMin(
            findMinInserts(str, first, last - 1),
            findMinInserts(str, first + 1, last)
        ) + 1;
    }
}

int main(int argc, char **argv){
    if (argc != 2){
        printf("Usage: %s inputString\n", __FILE__);
        exit(255);
    }

    printf("%d\n", findMinInserts(argv[1], 0, strlen(argv[1]) - 1));
    return 0;
}