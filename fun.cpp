#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(n, m) for(int i=n; i<m; i++)
#define repj(n, m) for(int j=n; j<m; j++)
#define rrep(n, m) for(int i=n; i>=m; i--)
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define sv(v) sort(v.begin(), v.end())
#define sr(v) sort(v.begin(), v.end()); reverse(v.begin(), v.end());
#define sa(arr, n) sort(arr, arr+n)
#define endll "\n\n"
#define endl "\n"
#define imax INT_MAX
#define imin INT_MIN 
#define sum(v) accumulate(v.begin(), v.end(), 0LL);
#define index(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793
// number of subset index ind belong = (ind+1)(n-ind) with 0 indexing

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
void traverseVector(vector<ll> v){
    int n = v.size();
    for(int i=0; i<n; i++) cout << v[i] << " "; cout << endl;
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
class nCr{
    public:
    vector<long long> fac;
    int mod;
    nCr(int _mod){
        mod = _mod; 
        fac.resize(1e6+5, 0);
        fac[0] = 1;
        for(int i=1; i<fac.size(); i++){
            fac[i] = (fac[i-1] * i)%mod;
        }
    }
    long long binaryExponentiation(long long a, long long b){
        // a^b;
        if(b == 0) return 1;
        long long ans = binaryExponentiation(a, b/2);
        ans = (ans*ans) % mod;
        if(b%2) ans = (ans*a) % mod;
        return ans;
    }
    long long moduloInverse(long long a){
        return binaryExponentiation(a, mod - 2);
    }
    long long combination(int n, int r){
        long long ans = fac[n];
        ans = (ans * moduloInverse(fac[n-r])) % mod;
        ans = (ans * moduloInverse(fac[r])) % mod;
        return ans;
    }
};
class DSU{
    public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=1; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionDSU(int u, int v){
        v = findParent(v); u = findParent(u); 
        if(rank[u] < rank[v]){
            parent[u] = v;
        }else if(rank[u] > rank[v]){
            parent[v] = u;
        }else{
            parent[u] = v;
            rank[u]++;
        }
    }
};
void solve(){
    
}
int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
	ll t = 1;
	cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}



