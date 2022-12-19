#include "string.h"
#include <iostream>
using namespace std;
;
int *sort(int *Array, int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = j; i < size - j; i++)
        {
            if (*(Array + i) < *(Array + i + 1))
            {
                int temp = *(Array + i);
                *(Array + i) = *(Array + i + 1);
                *(Array + i + 1) = temp;
            }
        }
    }
    return Array;
}
void print_array(int *Array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(Array + i) << "";
    }
    cout << endl;
}

int main()
{
    int kid_a[] = {1, 2, 3, 4, 5, 6, 7};
    int cake_arr[] = {4, 3, 2, 5, 4, 6, 8};

    cout << "before sort" <<endl;
    print_array(kid_a, 7);
    // find the most hungury kid
    int *max_hungury_kid = sort(kid_a, 7);
    cout << "after sort" <<endl;
    print_array(max_hungury_kid, 7);

    return 0;
}
