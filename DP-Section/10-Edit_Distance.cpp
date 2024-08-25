// 10.cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1000000000
#define mod 1000000007

// Giving TLE

ll helper_function(ll i, ll j, ll n, ll m, string s, string t, vector<vector<ll>>& dp) {
	if (i < 0)
		return j + 1;
	if (j < 0)
		return i + 1;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s[i] == t[j])
		return dp[i][j] = helper_function(i - 1, j - 1, n, m, s, t, dp);

	dp[i][j] = 1 + min({helper_function(i - 1, j, n, m, s, t, dp), helper_function(i, j - 1, n, m, s, t, dp),
	                    helper_function(i - 1, j - 1, n, m, s, t, dp)
	                   });

	return dp[i][j];
}

void solve() {
	string s, t;
	cin >> s >> t;

	ll n = s.size(), m = t.size();

	vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));

	// ll edit_len = helper_function(n - 1, m - 1, n, m, s, t, dp);

	for (ll i = 0; i <= n; i++)
		dp[i][0] = i;
	for (ll j = 0; j <= m; j++)
		dp[0][j] = j;

	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
		}
	}

	cout << dp[n][m] << endl;
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

