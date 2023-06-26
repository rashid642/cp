#include<bits/stdc++.h>
using namespace std;

class EulerTourType1{
    // for finding LCA
    // find first occ of nodeA and nodeB 
    // and get the lowest level in between
    public:
    vector<vector<int>> adj;
    vector<int> level, v;
    vector<pair<int, int>> occ;
    int ind;
    EulerTourType1(vector<vector<int>> _adj, int soruce, int n){
        adj = _adj;
        ind = 0;
        level.resize(n+1);
        dfs(soruce, -1);
        occ.resize(n+1, {-1, -1});
        for(int i=0; i<v.size(); i++){
            if(occ[v[i]].first == -1){
                occ[v[i]].first = i;
            }
        }
        for(int i=v.size()-1; i>=0; i--){
            if(occ[v[i]].second == -1){
                occ[v[i]].second = i;
            }
        }
    }
    void dfs(int node, int par, int l = 0){
        level[node] = l;
        v.push_back(node);
        ind++;
        for(auto it: adj[node]){
            if(it == par) continue;
            dfs(it, node, l + 1);
            v.push_back(node);
            ind++;
        }
    }
    void tv(){
        for(auto it: v) cout << it << " "; cout << endl;
    }
};
class EulerTourType2{
    // used in subtree problems
    public:
    vector<vector<int>> adj;
    vector<int> v;
    map<int, int> mpp;
    vector<pair<int, int>> occ;
    int ind;
    EulerTourType2(vector<vector<int>> _adj, int soruce, int n){
        adj = _adj;
        ind = 0;
        dfs(soruce, -1);
        occ.resize(n+1, {-1, -1});
        for(int i=0; i<v.size(); i++){
            if(occ[v[i]].first == -1){
                occ[v[i]].first = i;
            }
        }
        for(int i=v.size()-1; i>=0; i--){
            if(occ[v[i]].second == -1){
                occ[v[i]].second = i;
            }
        }
    }
    void dfs(int node, int par){
        v.push_back(node);
        ind++;
        for(auto it: adj[node]){
            if(it == par) continue;
            dfs(it, node);
        }
        v.push_back(node);
        ind++;
    }
    void tv(){
        for(auto it: v) cout << it << " "; cout << endl;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    EulerTourType1 eu(adj, 1, n);
    eu.tv();
    cout << eu.occ[3].first << " " << eu.occ[3].second << endl;
}
