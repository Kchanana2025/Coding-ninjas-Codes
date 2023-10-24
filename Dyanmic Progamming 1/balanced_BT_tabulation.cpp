#include <bits/stdc++.h>
using namespace std;
// we are assuming that h>=0
int balanced_BT(int h)
{

    if (h == 0 || h == 1) // recursion ka base case tabhi chalega jab dono n ki values 1 return kregi
    //    normally bhi jab root=NULL(or h=0) hota hai tab we say that it is a balanced BT.(jab koi node hi nai hai toh balanced binary tree hai)
    {
        return 1;
    }
    int mod = (int)(pow(10, 9)) + 7;
    int x = balanced_BT(h - 1);
    int y = balanced_BT(h - 2);
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    int ans = (temp1 + temp2) % mod;
    // int ans = x * x + 2 * x * y;
    return ans;
}
int main()
{
    int h;
    cin >> h;
    cout << balanced_BT(h);
}