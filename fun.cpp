#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;
 
void precompute(){
}
int n, m;
void dfs(vector<int> adj[], int node, vector<int> &dp, vector<int> &par, vector<int> &vis){
    vis[node] = 1;
    if(node == n){
        dp[node] = 1;
        return; 
    }
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(adj, it, dp, par, vis);
        }
        if(dp[node] < 1 + dp[it]){
            par[node] = it;
        }
        dp[node] = max(dp[node], 1 + dp[it]);
    }
}
void solve(int test){
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> dp(n+1, INT_MIN), par(n+1, -1), vis(n+1, 0);
    dfs(adj, 1, dp, par, vis);
    if(!vis[n]){
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> ans;
    int node = 1;
    while(node != n){
        ans.push_back(node);
        node = par[node];
    }
    ans.push_back(node);
    cout << ans.size() << endl;
    tv(ans);
}   
int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif
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