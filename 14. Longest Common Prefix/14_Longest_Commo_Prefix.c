#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        strs[0][j] = strs[0][j] == strs[i][j] ? strs[0][j] : '\0';
    }
    return strs[0];
}
int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;
    char* result = longestCommonPrefix(strs, strsSize);
    printf("Longest Common Prefix: %s\n", result);
    return 0;
}
