#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(vector<pair<int, int>> adj[], int source, int n){
    priority_queue<pair<long long, int>> pq;
    vector<long long> dis(n+1, 1e18);
    pq.push({0, source});
    dis[source] = 0;
    while(pq.empty() == false){
        int node = pq.top().second;
        long long d = -pq.top().first;
        pq.pop();
        if(dis[node] != d) continue;
        for(auto it: adj[node]){
            int adjNode = it.first;
            long long w = it.second;
            if(dis[adjNode] > d + w){
                dis[adjNode] = d + w;
                pq.push({-dis[adjNode], adjNode});
            }
        }
    }
    return dis;
}
int main() {
    return 0;
}