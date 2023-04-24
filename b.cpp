#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(n, m) for(int i=n; i<m; i++)
#define repj(n, m) for(int j=n; j<m; j++)
#define repk(n, m) for(int k=n; k<m; k++)
#define rrep(n, m) for(int i=n; i>=m; i--)
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define sv(v) sort(v.begin(), v.end())
#define sr(v) sort(v.begin(), v.end()); reverse(v.begin(), v.end());
#define sa(arr, n) sort(arr, arr+n)
#define endll "\n\n"
#define endl "\n"
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793
#define vll vector<long long>
#define vvll vector<vector<long long>>
// number of subset index ind belong = (ind+1)(n-ind) with 0 indexing
// If a particular bit is set in array then if we take all the subsequence of that
// array then that set bit will will occur 2^(n-1) times

// Cin overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p){return (istream >> p.first >> p.second);}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v){for (auto &it : v) cin >> it; return istream;}

ll giveSqrt(ll x){
    ll low = 1, high = 3e9, ans = 1;
    while(low<=high){
        ll mid = (low+high)/2;
        if(mid*mid<=x){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}
ll power(ll a, ll b, ll modu){ // a ^ b
    if(b == 0) return 1LL;
    ll ans = power(a, b/2, modu);
    ans = (ans * ans)%modu;
    if(b%2) ans = (ans*a);
    return ans % modu;
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
void tv(vector<ll> v){
    for(int i=0; i<v.size(); i++) cout << v[i] << " "; cout << endl;
}
void tv(vector<int> v){
    for(int i=0; i<v.size(); i++) cout << v[i] << " "; cout << endl;
}
vector<bool> primeNumber(int n){
    vector<bool> v(n, true);
    v[0] = false; v[1] = false; v[2] = true;
    for(int i=2; i<n; i++){
        if(v[i]){
            for(int j=i*2; j<n; j = j+i) v[j] = false;
        }
    }
    return v;
}
void precompute(){
}
void solve(int test){
    
}
int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    precompute();
    cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}
