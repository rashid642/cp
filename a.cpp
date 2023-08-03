#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;

void precompute(){
}
vector<ll> getFactors(ll n){
    vector<ll> v;
    for(ll i=1; i*i <= n; i++){
        if(n%i == 0){
            v.push_back(i);
            if(i != n/i) v.push_back(n/i);
        }
    }
    return v;
}
bool isSqaure(ll a){
    ll t = sqrt(a);
    return t*t == a;
}
ll helper(vector<ll> &v, int n, ll x){
    ll count = 0;
    if(x < 0) return 0;
    for(int k=0; k<n; k++){
        ll newnum = v[k] + x;
        count += isSqaure(newnum);
    }
    return count;
}
void solve(int test){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    ll ans = 1;
    sort(v.begin(), v.end());
    for(int j=0; j<n; j++){
        for(int i=j+1; i<n; i++){
            ll diff = v[i] - v[j];
            vector<ll> fac = getFactors(diff);
            for(auto t: fac){
                if(((v[i] - v[j])/t + t)%2 == 0 && ((v[i] - v[j])/t - t)%2 == 0){
                    ll a = ((v[i] - v[j])/t + t)/2;
                    ll x = a*a - v[i];
                    ans = max(ans, helper(v, n, x));
                }
            }
        }
    }
    cout << ans << endl;
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