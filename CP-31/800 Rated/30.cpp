#include <iostream>
#include <vector>
using namespace std;

bool check(int x) {
    string s = to_string(x);
    int cnt = 0;
    for (char c : s) {
        if (c != '0') {
            cnt++;
        }
    }
    return cnt == 1;
}

vector<int> precompute() {
    vector<int> a;
    for (int i = 1; i < 1000000; ++i) {
        if (check(i)) {
            a.push_back(i);
        }
    }
    return a;
}

int main() {
    vector<int> a = precompute();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int x : a) {
            if (x <= n) {
                ans++;
            } else {
                break; // Since a is sorted, we can break early
            }
        }
        cout << ans << endl;
    }
    return 0;
}
