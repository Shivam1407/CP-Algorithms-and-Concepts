#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define print_1D_arr(a, n) for (long long i = 0; i < n; i++) { cout << a[i] << ' '; } cout << endl;
#define in_1D_arr(a,n)                     f(i,0,n){cin>>a[i];}
#define all(v)  v.begin(),v.end() 
#define pb push_back
typedef long long ll; 
typedef long long int  lli; 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<lli> vli;
void solve();
//--------------------------------------------------MAIN---------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//--------------------------------------------------SOLVE---------------------------------------------------------------------------------------------------------------------------------------------------
void solve() {
    lli n, a, b;
    cin >> n >> a >> b;

    vli arr(n);
    in_1D_arr(arr, n);

    vli prefix_sum(n+1,0);

    f(i,1,n+1)
    {
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
    }

    lli ans = LLONG_MIN;

    set <pair<lli, lli>> s;

    for (int i = a; i <= b ; i++)
    {
        s.insert({prefix_sum[i], i});
    }

    lli i = 1;
    while(i <= n-a+1)
    {
        auto it = s.rbegin();
        ans = max(ans, it->first - prefix_sum[i-1]);
        s.erase({prefix_sum[i+a-1], i+a-1});

        if(i+b <= n)
        {
            s.insert({prefix_sum[i+b], i+b});
        }
        i++;
    }

    cout << ans << endl;
}