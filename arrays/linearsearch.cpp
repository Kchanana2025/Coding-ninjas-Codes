int linearSearch(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
#include <iostream>
using namespace std;

// #include "solution.h"

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        int val;
        cin >> val;
        cout << linearSearch(arr, n, val) << endl;
    }
    return 0;
}