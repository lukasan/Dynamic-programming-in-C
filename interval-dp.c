#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if (argc != 3){
        printf("Usage: %s firstString secondString\n", __FILE__);
        exit(255);
    }
    return 0;
}