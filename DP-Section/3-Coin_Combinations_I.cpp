// C.cpp
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define inf 1000000000
#define mod 1000000007
 
void solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> arr(n);
	for (auto &it : arr)
		cin >> it;
 
	sort(arr.begin(), arr.end());
 
	vector<ll> dp(x + 1, 0);
	dp[0] = 1;
 
	for (ll i = 1; i <= x; i++) {
		for (ll j = 0; j < n; j++) {
			if (arr[j] <= i) {
				dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
			}
			else
				break;
		}
	}
 
	cout << dp[x] << endl;
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	ll tc;
	tc = 1;
	// cin >> tc;
 
	while (tc--) {
		solve();
	}
 
	return 0;
}
