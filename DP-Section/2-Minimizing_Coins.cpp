// B.cpp
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define inf 1000000000
 
ll helper_function(ll ind, ll target, ll n, vector<ll> & arr, vector<vector<ll>> & dp) {
    if(ind == n - 1) {
        if(target % arr[ind] == 0)
            return target / arr[ind];
        return inf;
    }
 
    if(dp[ind][target] != -1)
        return dp[ind][target];
 
    ll take = inf;
    if(arr[ind] <= target) {
        take = 1 + helper_function(ind, target - arr[ind], n, arr, dp);
    }
    ll not_take = 0 + helper_function(ind + 1, target, n, arr, dp);
 
    return dp[ind][target] = min(take, not_take);
}
 
void solve() {
    ll n, target;
    cin >> n >> target;
 
    vector<ll> arr(n);
    for(auto &it : arr)
        cin >> it;
 
    // vector<vector<ll>> dp(n + 1, vector<ll> (target + 1, -1));
 
    // ll min_coins = helper_function(0, target, n, arr, dp);
 
    vector<ll> dp(target + 1, inf);
    dp[0] = 0;
    for(ll i = 1; i <= target; i++) {
        for(ll j = 0; j < n; j++) {
            if(i - arr[j] >= 0) {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }
 
    if(dp[target] == inf) {
        cout << -1 << endl;
    }
    else {
        cout << dp[target] << endl;
    }
 
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
 
    int tc;
    tc = 1;
    // cin >> tc;
    for(ll i = 1; i <= tc; i++) {
        // cout << "TEST CASE : " << i << " : ";
        solve();
    }
 
    return 0;
}
