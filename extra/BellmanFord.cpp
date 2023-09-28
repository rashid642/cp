#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;
 
void precompute(){
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char dir[] = {'R', 'D', 'L', 'U'};
int node1 = -1, node2 = -1;
const ll inf = 1e17;
const ll ninf = -inf;
/*
In Bellman ford we need to do n-1 relaxation
then +1 relaxation to detect -ve cycle
and n-2 more cycles to detect all the nodes which are affected by -ve cycle
Problem 1 - https://cses.fi/problemset/task/1197
Problem 2 - https://cses.fi/problemset/task/1673
*/
void solve(int test){
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> adj[n];
    for(int i=0; i<m; i++){
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        adj[u].push_back({v, d});
    }
    vector<ll> dis(n, inf), par(n, -1);
    dis[0] = 0;
    for(int i=0; i<n-1; i++){
        for(int node=0; node<n; node++){
            for(auto it: adj[node]){
                int adjNode = it.first;
                ll d = it.second;
                if(dis[node] + d < dis[adjNode]){
                    par[adjNode] = node;
                    dis[adjNode] = d + dis[node];
                }
            }
        }
    }
    for(int node=0; node<n; node++){
        for(auto it: adj[node]){
            int adjNode = it.first;
            ll d = it.second;
            if(dis[node] + d < dis[adjNode]){
                par[adjNode] = node;
                node2 = node;
                break;
            }
        }
    }
    if(node2 == -1) {
        cout << "NO\n";
        return;
    }
    for(int i=0; i<n; i++){
        node2 = par[node2];
    }
    vector<int> ans;
    int t = node2;
    ans.push_back(t);
    t = par[t];
    int i = 0;
    while(node2 != t && i < 100){
        i++;
        ans.push_back(t);
        t = par[t];
    }
    ans.push_back(t);
    // ans.push_back(t);
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    for(auto it: ans) cout << it + 1 << " "; cout << endl;
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