#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;

void precompute(){
}
ll tot, w, f;
ll helper(ll water){
    ll fire = tot - water;
    ll t1 = (fire/f) + (fire%f > 0);
    ll t2 = (water/w) + (water%w > 0);
    return max(t1, t2);
}
ll helper(vector<ll> &v, int ind, ll water, vector<vector<ll>> &dp){
    if(ind == v.size()) {
        ll fire = tot - water;
        ll t1 = (fire/f) + (fire%f > 0);
        ll t2 = (water/w) + (water%w > 0);
        return max(t1, t2);
    }
    if(dp[water][ind] != -1) return dp[water][ind];
    return dp[water][ind] = min(helper(v, ind+1, water + v[ind], dp), helper(v, ind+1, water, dp));
}
void solve(int test){
    tot = 0;
    cin >> w >> f;
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    tot = accumulate(v.begin(), v.end(), 0LL);
    vector<vector<ll>> dp(tot + 1, vector<ll> (n, -1));
    // for(int ind=n-1; ind>=0; ind--){
    //     for(int water=tot; water>=0; water--){
    //         if(ind + 1 >= n){
    //             dp[water] = min(dp[water], helper(water));
    //         }
    //     }
    // }
    cout << helper(v, 0, 0, dp) << endl;
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t = 1;
    cin >> t;
    precompute();
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}