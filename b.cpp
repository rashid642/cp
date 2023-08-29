#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;

void precompute(){
}
const int N = 1e5 + 10;
ll depth[N];
void helper(vector<int> adj[], int node, int par) {
    for(auto it: adj[node]) {
        if(it == par) continue;
        helper(adj, it, node);
        depth[node] = max(depth[node], 1 + depth[it]);
    }
}
void solve(int test){
    int n;
    cin >> n;
    vector<int> adj[n+1];
    for(int i=2; i<=n; i++){
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    helper(adj, 1, -1);
    // for(int i=1; i<=n; i++) cout << depth[i] << " ";
    int ans = 0;
    for(auto it: adj[1]) ans += depth[it] + 1;
    if(adj[1].size() == 1) ans++;
    cout << ans << endl;
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t = 1;
    // cin >> t;
    precompute();
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}