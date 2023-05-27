#include<bits/stdc++.h>
using namespace std;
/*
    x-1      x-1
A ------ B -------- C
dp[A][x-1] = B
dp[B][x-1] = C
dp[A][x] = C --> 2^(x-1) + 2^(x-1) => 2^x
dp[A][x] = dp[B][x-1]
dp[A][x] = dp[dp[A][x-1]][x-1]
*/

class BinaryLifting{
    public :
    vector<int> parent;
    vector<vector<int>> dp;
    vector<vector<int>> adj;
    vector<int> level;
    int n, m, source;
    BinaryLifting(vector<int> p, int _n, int s){
        n = _n;
        m = 17; source = s;
        parent = p;
        adj.resize(n+1);
        dp.resize(n+1, vector<int> (m, 0));
        level.resize(n+1);
        for(int i=1; i<=n; i++){
            if(p[i] == -1) continue;
            adj[p[i]].push_back(i);
            adj[i].push_back(p[i]);
        }
        precomutation(source, 0, 0);
    }
    void precomutation(int node, int par, int depth){
        level[node] = depth;
        dp[node][0] = par;
        for(int i=1; i<m; i++){
            dp[node][i] = dp[dp[node][i-1]][i-1];
        }
        for(auto it: adj[node]){
            if(it == par) continue;
            precomutation(it, node, depth + 1);
        }
    }   
    int kthParent(int node, int k){
        for(int i=0; i<m; i++){
            if(k & (1 << i)){
                node = dp[node][i];
            }
        }
        return node;
    }
    int LCA(int node1, int node2){
        if(level[node1] < level[node2]) swap(node1, node2);
        node1 = kthParent(node1, level[node1] - level[node2]);
        if(node1 == node2) return node1;
        for(int i=m-1; i>=0; i--){
            if(dp[node1][i] != dp[node2][i]){
                node1 = dp[node1][i];
                node2 = dp[node2][i];
            }
        }
        return dp[node1][0];
    }
};
int main(){
    // 8
    // -1 1 1 2 2 5 5 7
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];
    BinaryLifting bf(v, n, 1);
    for(int i=1; i<=n; i++){
        cout << i << "->";
        for(auto it: bf.dp[i]) cout << it << " "; cout << endl;
    }
    cout << bf.kthParent(8, 3) << endl;
    cout << bf.kthParent(6, 2) << endl;
    cout << bf.LCA(8, 7);
    return 1;
}