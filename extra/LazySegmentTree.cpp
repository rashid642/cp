#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
class LazySegmentTree{
    public:
    long long tree[4*N+1], lazy[4*N+1];
    LazySegmentTree(int n){
        for(int i=0; i<4*N+1; i++){
            tree[i] = 0;
            lazy[i] = 0;
        }
    }
    long long operation(long long a, long long b){
        return (a + b);
    }
    long long operation2(long long a, long long b){
        return (a + b);
    }
    void build(int l, int r, int ind, vector<int> &v){
        if(l == r){
            tree[ind] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, 2*ind+1, v);
        build(mid+1, r, 2*ind+2, v);
        tree[ind] = operation(tree[2*ind+1], tree[2*ind+2]);
    }
    long long query(int l, int r, int ind, int i, int j){
        tree[ind] = operation2(tree[ind], lazy[ind]);
        if(l != r){
            lazy[2*ind+1] = operation2(lazy[2*ind+1], lazy[ind]);
            lazy[2*ind+2] = operation2(lazy[2*ind+2], lazy[ind]);
        }
        lazy[ind] = 0;
        if(r < i || j < l) return 0;
        if(i <= l && r <= j) return tree[ind];
        int mid = (l + r) / 2;
        return operation(query(l, mid, 2*ind+1, i, j), query(mid+1, r, 2*ind+2, i, j));
    }
    void update(int l, int r, int ind, int i, int j, long long val){
        tree[ind] = operation2(tree[ind], lazy[ind]);
        if(l != r){
            lazy[2*ind+1] = operation2(lazy[2*ind+1], lazy[ind]);
            lazy[2*ind+2] = operation2(lazy[2*ind+2], lazy[ind]);
        }
        lazy[ind] = 0;
        if(r < i || j < l) return;
        if(i <= l && r <= j) {
            tree[ind] = operation2(tree[ind], val);
            if(l != r){
                lazy[2*ind+1] = operation2(lazy[2*ind+1], val);
                lazy[2*ind+2] = operation2(lazy[2*ind+2], val);
            }
            return;
        }
        int mid = (l + r) / 2;
        update(l, mid, 2*ind+1, i, j, val);
        update(mid+1, r, 2*ind+2, i, j, val);
        tree[ind] = operation(tree[2*ind+1], tree[2*ind+2]);
    }
    long long make_query(int l, int r){
        return query(0, N, 0, l, r);
    }
    void make_update(int ind1, int ind2, long long val){
        update(0, N, 0, ind1, ind2, val);
    }
    void tv(){
        for(auto it: tree) cout << it << " "; cout << endl;
    }
};
int main(){
    return 0;
}