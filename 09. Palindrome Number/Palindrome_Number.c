#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x)
{
    int x_save = x;
    int t = 0;
    int revese_x = 0;
    // Mainly used to create a reverse of x, anc check whether thse two are equal.
    while (x > 0)
    {
        int t = x % 10;              // get the last digits of the input
        revese_x = revese_x * 10 + t;// put as the first digits of the reversed one 
        x = x / 10;                  // remove the last digit, and prepare for the next round
    }
    if (x_save == revese_x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    bool result = isPalindrome(12321);
    if (result == true)
    {
        printf("Test Passed\n");
    }
    else
    {
        printf("Test Failed\n");
    }
}
