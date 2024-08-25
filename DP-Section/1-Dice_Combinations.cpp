#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void solve() {
	ll n;
	cin >> n;
	ll mod = 1e9 + 7;
	vector<ll> dp(n + 1, 0);
	dp[0] = 1;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= 6; j++) {
			if(i - j >= 0) {
				dp[i] = dp[i] + dp[i - j];
				dp[i] = dp[i] % mod;
			}
		}
	}
 
	cout << dp[n] << endl;
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
