#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    // Find the length of the first string
    int len = strlen(strs[0]);
    
    // We must use the malloced memory, the char array will not allow add NULL Null-terminate, will issue a SIG 10 error
    char* prefix = (char*)malloc((len + 1) * sizeof(char)); // Allocate memory for the common prefix

    for (int j = 0; j < len; j++) {
        for (int i = 0; i < strsSize; i++) {
            if (strs[i][j] != strs[0][j]) {
                prefix[j] = '\0'; // Null-terminate the common prefix
                return prefix;
            }
        }
        prefix[j] = strs[0][j]; // Copy character to common prefix
    }

    prefix[len] = '\0'; // Null-terminate the common prefix
    return prefix;
}

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;
    char* result = longestCommonPrefix(strs, strsSize);

    if (strlen(result) == 0) {
        printf("No common prefix found.\n");
    } else {
        printf("Longest Common Prefix: %s\n", result);
    }

    free(result); // Don't forget to free the allocated memory

    return 0;
}
