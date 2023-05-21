#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
const int mod = 1e9 + 7;
class SegmentTree{
    public: 
    vector<ll> tree;
    SegmentTree(int n){
        for(int i=0; i<=4*n+1; i++) tree.push_back(-1);
    }
    ll operation(ll a, ll b){
        return max(a, b);
    }
    void update(int l, int r, int ind, ll val, int i){
        if(l == r){
            if(l == i) tree[ind] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(i <= mid){
            update(l, mid, 2*ind+1, val, i);
        }else{
            update(mid+1, r, 2*ind+2, val, i);
        }
        tree[ind] = operation(tree[2*ind+1], tree[2*ind+2]);
    }
    ll query(int i, int j, int l, int r, int ind){
        // complete overlap
        if(l >= i && r <= j) return tree[ind];
        // no overlap
        if(j < l || r < i) return INT_MIN;
        // partial overlap
        int mid = (l + r) / 2;
        return operation(query(i, j, l, mid, 2*ind+1), query(i, j, mid+1, r, 2*ind+2));
    }
    void build(vector<ll> &v, int l, int r, int ind){
        if(l == r){
            tree[ind] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(v, l, mid, 2*ind+1);
        build(v, mid+1, r, 2*ind+2);
        tree[ind] = operation(tree[2*ind+1], tree[2*ind+2]);
    }
};
void solve(int test){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout << i*j << " "; cout << endl;
    }
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t = 1;
    // cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}