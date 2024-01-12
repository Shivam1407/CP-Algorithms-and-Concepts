#include<bits/stdc++.h>
using namespace std;
int getVal(int a, int b)
{
    int res = 1;
    while(a && b)
    {
        if(a&1 == 1)
        {
            if(b&1 == 1)
            {
                res *= 2;
            }
            else{
                res = 0;
            }
        }
        a = a >> 1;
        b = b >> 1;
    }
    return res;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << getVal(a, b);
    return 0;
}