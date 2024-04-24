#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    // Return the maximum of a and b
    return (a > b) ? a : b;
}

int lcs(char *X, char *Y, int i, int j) {
    // Base case: if we reach the end of either string, return 0
    if (X[i] == '\0' || Y[j] == '\0') {
        return 0;
    }

    // If characters match, continue with the subsequence
    if (X[i] == Y[j]) {
        return 1 + lcs(X, Y, i + 1, j + 1);
    } else {
        // Choose the maximum LCS length from the two choices
        return max(lcs(X, Y, i, j + 1), lcs(X, Y, i + 1, j));
    }
}

int main() {
    char S1[] = "niki";
    char S2[] = "nikita";
    
    // Calculate the length of the LCS starting from the beginning of both strings
    int length_of_lcs = lcs(S1, S2, 0, 0);
    
    // Print the length of the LCS
    printf("Length of LCS is: %d\n", length_of_lcs);

    return 0;
}
