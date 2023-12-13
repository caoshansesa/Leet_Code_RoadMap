#include <stdio.h>
#include <string.h>

double fmax(double a, double b)
{
    return a > b ? a : b;
}
int lengthOfLongestSubstring(char *s)
{
    // Get length of the string.
    int lengthOfStr = strlen(s);
    // Declare the longest substring length.
    int lengthOFlongestSubStr = 0;

    for (int i = 0; i < lengthOfStr; i++)
    {
        for (int j = i + 1; j < lengthOfStr; j++)
        {
            if (s[i] == s[j])
            {
                // only find longest str if there is no repeat, if there is repeat, break, 
                // save the longest substring length. that is the longest substring length for current index
                // Then loop through next one, and compare, only keep the longer length
                lengthOFlongestSubStr = fmax(lengthOFlongestSubStr, j - i);
                break;
            }
        }
    }
    return lengthOFlongestSubStr;
}

int main()
{
    char s[] = "abcabcbb";
    int len = lengthOfLongestSubstring(s);
    printf("%d\n", len);
    return 0;
}