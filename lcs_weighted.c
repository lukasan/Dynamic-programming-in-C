#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int max(int a, int b){
    if (a > b) return a;
    else return b;
}

void printTable(char *x, char *y, int m, int n, int L[m+1][n+1]){
    printf(" ");
    for (int i = 0; i < strlen(x); i++){
        printf(" %c", x[i]);
    }
    printf("\n");
    
    for (int i = 1; i <= strlen(y); i++){
        for (int j = 1; j <= strlen(x); j++){
            if (j == 1)
                printf("%c", y[i-1]);
            printf(" %d", L[j][i]);
        }
        printf("\n");
    }
}

void print_lcs(char *x, char *y, int m, int n, int L[m+1][n+1]){
    // Following code is used to print LCS 
    int index = L[m][n];
    // Create a character array to store the lcs string 
    char lcs[index+1]; 
    lcs[index] = '\0'; // Set the terminating character 

    // Start from the right-most-bottom-most corner and 
    // one by one store characters in lcs[] 
    int i = m, j = n; 
    while (i > 0 && j > 0) 
    { 
    // If current character in X[] and Y are same, then 
    // current character is part of LCS 
    if (x[i-1] == y[j-1]) 
    { 
        lcs[index-1] = x[i-1]; // Put current character in result 
        i--;
        j--;
        index--;
    } 

    // If not same, then find the larger of two and 
    // go in the direction of larger value
    else if (L[i-1][j] > L[i][j-1]) 
        i--; 
    else
        j--; 
    } 
  
    // Print the lcs 
    //printf("LCS of %s and %s is %s\n", x, y, lcs); 
    printf("LCS string: %s\n", lcs);
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n, int weight1, int weight2) { 
    int L[m+1][n+1]; 
    //int i, j; 
   
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note  
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i=0; i<=m; i++){ 
        for (int j=0; j<=n; j++){ 
        
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
            
            else if (X[i-1] == Y[j-1]){
                L[i][j] = L[i-1][j-1] + 1; 
            }

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
   

    printTable(X, Y, m, n, L);
    printf("LCS length: %d\n", L[m][n]);
    print_lcs(X, Y, m, n, L);
    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return (m - L[m][n]) * weight1 + (n - L[m][n]) * weight2;
}

int main(int argc, char **argv){
    if (argc != 5){
        printf("Usage:\n %s str1 str2 weight1 weight2\n", __FILE__);
        exit(255);
    }

    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);

    int weight1 = atoi(argv[3]);
    int weight2 = atoi(argv[4]);

    int cost = lcs(argv[1], argv[2], len1, len2, weight1, weight2);

    printf("Cost of removing: %d\n", cost);
    return 0;
}