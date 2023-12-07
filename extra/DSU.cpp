#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int> parent, rank, nodeSize;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        nodeSize.resize(n, 1);
        for(int i=1; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionDSU(int u, int v){
        v = findParent(v); u = findParent(u); 
        if(rank[u] < rank[v]){
            nodeSize[v] += nodeSize[u];
            parent[u] = v;
        }else if(rank[u] > rank[v]){
            nodeSize[u] += nodeSize[v];
            parent[v] = u;
        }else{
            nodeSize[v] += nodeSize[u];
            parent[u] = v;
            rank[u]++;
        }
    }
    int getSize(int node){
        int par = findParent(node);
        return nodeSize[par];
    }
};
int main(){
    DSU d(10);
    d.unionDSU(1,2);
    cout << d.findParent(1) << " " << d.findParent(2) << endl;
    return 0;
}