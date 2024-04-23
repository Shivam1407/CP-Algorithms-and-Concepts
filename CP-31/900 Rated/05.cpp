#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(),v.end())
typedef long long ll; 


void solve();
int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    f(i,0,n)
    {
        cin >> arr[i];
    }

    if(n&1)
    {
        cout << "4" << endl;
        cout << 1 << " " << n << endl;
        cout << 2 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else{
        cout << "2" << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
    }
}



// In one operation, you select two indices l
//  and r
//  (1≤l≤r≤n
// ) and do the following:

// Let s=al⊕al+1⊕…⊕ar,  where ⊕  denotes the bitwise XOR operation;


// Then, for all l≤i≤r, replace ai with s .



// if n = even        for ex   1 2 3 0
//  we will select 1 and 4 and  do 1^2^3^0 = 0 now we will replace all the remaining spaces with this i.e array will become 0 0 0 0 

//  if odd             for exam   1 2 3 4 5

//  we will select from 1 to 5 and do xor so   1^2^3^4^5 = x(lets assume) iske baad replace all the remaining spaces with this i.e array will become x x x x x 
//  now we will again select from 1 to 5 and do xor ie x^x^x^x^x = x    ---->    x  0 0 0 0
//  now we will take 1 to 2 and do xor   i.e  x^0 = x              ->         x x 0 0 0
//  now again we will take 1 to 2 and do xor i.e. x^x=0   -> 0 0 0 0
