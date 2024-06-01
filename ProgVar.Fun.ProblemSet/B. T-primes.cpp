#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(),v.end())
#define print_1D_arr(a,n)  for(ll i=0; i<n; i++),{cout<<a[i]<< ;} cout << endl;
#define in_1D_arr(a,n)                     f(i,0,n){cin>>a[i];}
typedef long long ll; 
typedef vector<int> vi;
bool all_same_element_in_arr(ll *arr, ll n){for(ll i=0; i<n-1; i++){if(arr[i]!=arr[i+1]){return false;}}return true;}
void solve();

//--------------------------------------------------SOLVE---------------------------------------------------------------------------------------------------------------------------------------------------

const int N = 1e6 + 1;

set<ll> prime_sq()
{
    vector<bool> is_prime(N, false);
    

    for (ll i = 2; i * i < N; i++)
    {
        if(is_prime[i] == false)
        {
            for (ll j = i * i; j < N; j += i)
            {
                is_prime[j] = true;
            }
        }
        
    }
    set<ll> primes;
    for (ll i = 2; i < N; i++)
    {
        if(is_prime[i] == false)
        {
            primes.insert(i * i);
        }
    }
    return primes;
}

//--------------------------------------------------MAIN---------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    ll t;
    cin >> t;
    set<ll> primes = prime_sq();
    while (t--)
    {
        ll n;
        cin >> n;

        if (primes.find(n) != primes.end())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}