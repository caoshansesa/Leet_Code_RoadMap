#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    // Find the length of the first string
    int len = strlen(strs[0]);

    for (int j = 0; j < len; j++) {
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][j] != strs[0][j]) {
                strs[0][j] = '\0'; // Null-terminate the common prefix
                return strs[0];
            }
        }
    }

    return strs[0];
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

    return 0;
}
