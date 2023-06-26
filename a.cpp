#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;

void precompute(){
}
void solve(int test){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, 0});
        adj[v].push_back({u, w, 0});
    }
    vector<ll> train(n+1, INT_MAX);
    for(int i=0; i<k; i++){
        ll u, d;
        cin >> u >> d;
        train[u] = min(d, train[u]);
    }
    for(int i=1; i<=n; i++){
        if(train[i] >= INT_MAX) continue;
        adj[1].push_back({i, train[i], 1});
    }
    vector<ll> dis(n+1, 1e16);
    priority_queue<vector<ll>> pq;
    pq.push({0, 0, 1}); // dis, train_path, node
    dis[1] = 0;
    int ans = 0;
    while(!pq.empty()){
        // as those with the least dist. will be coming first
        // and if distance are same road path will be given prefrence as road_path has val = 0
        auto it = pq.top();
        int node = it[2];
        int tr = it[1];
        ll d = -it[0];
        pq.pop();
        if(dis[node] != d) continue;
        ans += tr;
        for(auto it: adj[node]){
            int adjNode = it[0];
            ll w = it[1];
            if(d + w < dis[adjNode]){
                dis[adjNode] = d + w;
                pq.push({-dis[adjNode], it[2], adjNode});
            }
        }
    }
    ans = k - ans;
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