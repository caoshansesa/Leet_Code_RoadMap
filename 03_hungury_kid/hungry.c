#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
  return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int child = 0;
    for (int i = 0; i < sSize && child < gSize; i++) {
        if (g[child] <= s[i]) {
            child++;
        }
    }
    return child;
}

// Test the function
int main() {
    int greed[] = {1, 2, 3}; // Greed factors of children
    int cookieSizes[] = {1, 1}; // Sizes of cookies

    int numKids = findContentChildren(greed, sizeof(greed) / sizeof(greed[0]), cookieSizes, sizeof(cookieSizes) / sizeof(cookieSizes[0]));

    printf("Number of content children: %d\n", numKids);
    return 0;
}

