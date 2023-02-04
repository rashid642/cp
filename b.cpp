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
#define imax INT_MAX
#define imin INT_MIN 
// #define sum(v) accumulate(v.begin(), v.end(), 0LL);
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
bool isPalindrome(vll s){
    int i = 0, j = s.size()-1;
    while(i < j){
        if(s[i] != s[j]) return false; 
        i++, j--;
    }
    return true;
}
class SegmentTree{
    public:
    vector<long long> tree, lazy;
    SegmentTree(int n){
        tree.resize(4*n+1, 0);
        lazy.resize(4*n+1, 0);
    }
    void build(int l, int r, int ind, vector<long long> &v){
        if(l == r){
            tree[ind] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, 2*ind+1, v);
        build(mid+1, r, 2*ind+2, v);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
    }
    long long rangeSum(int l, int r, int ind, int i, int j){
        // i and j are range in which you want the sum
        tree[ind] = tree[ind] + (r - l + 1) * lazy[ind];
        if(l != r){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
        if(i <= l && r <= j){
            return tree[ind];
        }
        if(r < i || l > j) {
            return 0;
        }
        int mid = (l + r) / 2;
        long long left = rangeSum(l, mid, 2*ind+1, i, j);
        long long right = rangeSum(mid+1, r, 2*ind+2, i, j);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
        return left + right;
    }
    void rangeUpdate(int l, int r, int ind, int i, int j, int val){
        tree[ind] = tree[ind] + (r - l + 1) * lazy[ind];
        if(l != r){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
        if(i <= l && r <= j){
            tree[ind] = tree[ind] + (r - l + 1) * val;
            if(l != r){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }
        if(r < i || l > j) {
            return;
        }
        int mid = (l + r) / 2;
        rangeUpdate(l, mid, 2*ind+1, i, j, val);
        rangeUpdate(mid+1, r, 2*ind+2, i, j, val);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
    }
};
void precompute(){
}
void solve(){
    
}
int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    precompute();
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
