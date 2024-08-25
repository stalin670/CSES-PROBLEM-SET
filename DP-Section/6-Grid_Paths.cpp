// C.cpp
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define inf 1000000000
#define mod 1000000007
 
ll helper_function(ll i, ll j, ll n, vector<string>& arr, vector<vector<ll>>& dp) {
    if (i == n - 1 and j == n - 1 and arr[i][j] != '*')
        return 1;
    if (i >= n || j >= n)
        return 0;
 
    if (arr[i][j] == '*')
        return 0;
 
    if (dp[i][j] != -1)
        return dp[i][j];
 
    ll right = helper_function(i, j + 1, n, arr, dp);
    ll down = helper_function(i + 1, j, n, arr, dp);
 
    return dp[i][j] = (right + down) % mod;
}
 
void solve() {
    ll n;
    cin >> n;
    vector<string> arr(n);
    for (auto &it : arr)
        cin >> it;
 
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
 
    ll max_ways = helper_function(0, 0, n, arr, dp);
    cout << max_ways << endl;
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
}
