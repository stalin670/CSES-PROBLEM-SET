// C.cpp
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define inf 1000000000
#define mod 1000000007
 
ll max_digit(ll n) {
    ll maxi = n % 10;
    while (n) {
        maxi = max(maxi, n % 10);
        n /= 10;
    }
    return maxi;
}
 
void solve() {
    ll n;
    cin >> n;
    ll steps = 0;
    while (n) {
        n -= max_digit(n);
        steps++;
    }
    cout << steps << endl;
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
