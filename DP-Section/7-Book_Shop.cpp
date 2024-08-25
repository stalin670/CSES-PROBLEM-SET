// E.cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1000000000
#define mod 1000000007

// Memoization/Recursive DP

ll helper_function(ll ind, ll w, ll n, vector<ll>& wt, vector<ll>& val, vector<vector<ll>>& dp) {
    if (ind == n - 1) {
        if (wt[ind] <= w)
            return val[ind];
        return 0;
    }

    if (dp[ind][w] != -1)
        return dp[ind][w];

    ll max_val = helper_function(ind + 1, w, n, wt, val, dp);
    if (w - wt[ind] >= 0)
        max_val = max(max_val, helper_function(ind + 1, w - wt[ind], n, wt, val, dp) + val[ind]);

    return dp[ind][w] = max_val;
}

void solve() {
    ll n, w;
    cin >> n >> w;

    vector<ll> wt(n), val(n);
    for (auto &it : wt)
        cin >> it;
    for (auto &it : val)
        cin >> it;

    // vector<vector<ll>> dp(n + 1, vector<ll> (w + 1, -1));

    // ll max_val = helper_function(0, w, n, wt, val, dp);

    vector<ll> dp(w + 1, 0);
    for (ll i = 0; i < n; i++) {
        for (ll j = w; j >= 0; j--) {
            if (wt[i] > j)
                continue;
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }

    cout << dp[w] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll tc;
    tc = 1;
    // cin >> tc;
    for (ll i = 1; i <= tc; i++) {
        // cout << "TEST CASE : " << i << " : ";
        solve();
    }

    return 0;
}

