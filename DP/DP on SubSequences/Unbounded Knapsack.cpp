#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define print_1D_arr(a, n) for (long long i = 0; i < n; i++) { cout << a[i] << ' '; } cout << endl;
#define in_1D_arr(a,n) f(i,0,n){cin>>a[i];}

#ifdef parthgupta21
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef long long int lli;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
/*--------------------------------------------------------------------------------------------------------------------------*/
int table(int n, int w, vector<int> wt, vector<int> val, int ind) // O(n*w) time and O(n*w) space
{
    vvll dp(n, vll(w + 1, 0));

    f(j,0,n)
    {
        if(wt[0] <= j)
        {
            dp[0][j] = (j/wt[0]) * val[0];
        }
        
    }


    f(i,1,n)
    {
        f(j,0,w+1)
        {
            int notTake = dp[i - 1][j];
            int take = -INF;

            if(wt[i] <= j)
            {
                take = val[i] + dp[i][j - wt[i]];
            }
            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n - 1][w];
}


int memo(int n, int w, vector<int> wt, vector<int> val, int ind) // O(n*w) time and O(n*w) space
{
    vvll dp(n, vll(w + 1, -1));

    if(ind == 0)
    {
        if(wt[0] <= w)
        {
            return (w / wt[0]) * val[0];
        }
        return 0;
    }
    if(dp[ind][w] != -1)
    {
        return dp[ind][w];
    }

    int notTake = 0 + memo(n, w, wt, val, ind - 1);
    int take = -INF;

    if(wt[ind] <= w)
    {
        take = val[ind] + memo(n, w - wt[ind], wt, val, ind);
    }

    return dp[ind][w] = max(take, notTake);
}

int recurr(int w, vector<int> wt, vector<int> val, int ind) // O(2^n) time  and O(n) stack space
{
    if (ind == 0)
    {
        if (wt[0] <= w)
        {
            return (w / wt[0]) * val[0];
        }
        return 0;
    }

    int notTake = 0 + recurr(w, wt, val, ind - 1);
    int take = -INF;
    if (wt[ind] <= w)
    {
        take = val[ind] + recurr(w - wt[ind], wt, val, ind);
    }

    return max(take, notTake);
}

ll space(int w, vector<int> wt, vector<int> val, int n)
{
    vll prev(w + 1, 0);
    vll curr(w + 1, 0);

    f(j, 0, n)
    {
        if(wt[0] <= j)
        {
            prev[j] = j / wt[0] * val[0];
        }
    }

    f(i,1,n)
    {
        f(j,0,w+1)
        {
            int notTake = prev[j];
            int take = -INF;

            if(wt[i] <= j)
            {
                take = val[i] + curr[j - wt[i]];
            }
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[w];
}

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> wt(n), val(n);
    in_1D_arr(wt, n);
    in_1D_arr(val, n);

    cout << recurr(w, wt, val, n - 1) << endl;
    cout << memo(n,w, wt, val, n - 1) << endl;
    cout << table(n, w, wt, val, n) << endl;
    cout << space(w, wt, val, n) << endl;
}
int main() {
#ifdef parthgupta21
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    lli t;
    cin >> t;
    while (t--) {
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef parthgupta21
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
    return 0;
}