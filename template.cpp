#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(n, m) for(int i=n; i<m; i++)
#define repj(n, m) for(int j=n; j<m; j++)
#define rrep(n, m) for(int i=n; i>=m; i--)
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define sv(v) sort(v.begin(), v.end())
#define sa(arr, n) sort(arr, arr+n)
#define endll "\n\n"
#define endl "\n"
#define imax INT_MAX
#define imin INT_MIN 
#define sum(v) accumulate(v.begin(), v.end(), 0LL);
#define index(i, j) cout << "(" << i << "," << j << ") "
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793

void traverseArray(ll arr[], int n); 
void traverseVector(vector<ll> v);
vector<bool> primeNumber(int n);
void mapTraversal(map<char, int> &mpp);
vector<int> testCases();
vector<ll> getFactors(ll n); // O(sqrt(n))
string StringtestCases();
// ll power(ll a, ll b, ll modu); // a^b
void makeSet(int parent[], int rank[], int n);
int findParent(int parent[], int node);
void unionDSU(int u, int v, int parent[], int rank[]);
// number of subset index ind belong = (ind+1)(n-ind) with 0 indexing

// brother dont rush
// make note of other testcase before submitting A and B
// think reverse construction, binary search
// try generating equations for maths problem
// if it's written find minimum and then u can think of a binary search

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

//////disjoint set union ///////

void makeSet(int parent[], int rank[], int n){
    for(int i=1; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(int parent[], int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}
void unionDSU(int u, int v, int parent[], int rank[]){
    v = findParent(parent, v); u = findParent(parent, u); 
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }else{
        parent[u] = v;
        rank[u]++;
    }
}

//////////////////////////////

ll power(ll a, ll b, ll modu){
    // a ^ b
    if(b == 0){
        return 1LL;
    }
    ll ans = power(a, b/2, modu);
    ans = (ans * ans)%modu;
    if(b%2){
        ans = (ans*a);
    }
    return ans % modu;
}
vector<ll> getFactors(ll n){
    vector<ll> v;
    for(ll i=1; i*i <= n; i++){
        if(n%i == 0){
            v.push_back(i);
            if(i != n/i)
                v.push_back(n/i);
        }
    }
    return v;
}
void traverseArray(ll arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void traverseVector(vector<ll> v){
    int n = v.size();
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
vector<bool> primeNumber(int n){
    vector<bool> v(n, true);
    v[0] = false;
    v[1] = false;
    v[2] = true;
    for(int i=2; i<n; i++){
        if(v[i]){
            for(int j=i*2; j<n; j = j+i){
                v[j] = false;
            }
        }
    }
    return v;
}
void mapTraversal(map<char, int> &mpp){
    for(auto it : mpp){
        cout << it.first << "->" << it.second << " ";   
    }
    cout << endl;
}


