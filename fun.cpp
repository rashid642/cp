#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> adj[N];
int c[N];
int dp[N];
int par[N];
void solve(int test){
    int n;
    cin >> n;
    int root = 0;
    for(int i=1; i<=n; i++){
        int p;
        cin >> p >> c[i];
        if(p == -1) {
            root = i;
            continue;
        }
        par[i] = p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for(int i=1; i<=n; i++){
        for(auto it: adj[i]){
            if(par[i] == it) continue;
            if(c[it] == 0) dp[i] = 1;
        }
    }
    // for(int i=1; i<=n;i ++) index2(dp[i], c[i]);
    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(c[i] == 1 && dp[i] == 0){
            ans.push_back(i);
        }
    }
    if(ans.size() == 0){
        cout << -1 << endl;
        return;
    }
    for(auto it: ans) cout << it << " "; cout << endl;
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
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}