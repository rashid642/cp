#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    public:
    vector<long long> tree, lazy;
    SegmentTree(int n){
        tree.resize(4*n+1, 0);
        lazy.resize(4*n+1, 0);
    }
    void build(int l, int r, int ind, vector<long long> &v){
        if(l == r){
            tree[ind] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, 2*ind+1, v);
        build(mid+1, r, 2*ind+2, v);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
    }
    long long rangeSum(int l, int r, int ind, int i, int j){
        // i and j are range in which you want the sum
        tree[ind] = tree[ind] + (r - l + 1) * lazy[ind];
        if(l != r){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
        if(i <= l && r <= j){
            return tree[ind];
        }
        if(r < i || l > j) {
            return 0;
        }
        int mid = (l + r) / 2;
        long long left = rangeSum(l, mid, 2*ind+1, i, j);
        long long right = rangeSum(mid+1, r, 2*ind+2, i, j);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
        return left + right;
    }
    void rangeUpdate(int l, int r, int ind, int i, int j, int val){
        tree[ind] = tree[ind] + (r - l + 1) * lazy[ind];
        if(l != r){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
        if(i <= l && r <= j){
            tree[ind] = tree[ind] + (r - l + 1) * val;
            if(l != r){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }
        if(r < i || l > j) {
            return;
        }
        int mid = (l + r) / 2;
        rangeUpdate(l, mid, 2*ind+1, i, j, val);
        rangeUpdate(mid+1, r, 2*ind+2, i, j, val);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
    }
};
const int N = 2*1e5 + 5;
class SegmentTree2{
    public:
    long long tree[4*N+1], lazy[4*N+1];
    SegmentTree2(int n){
        for(int i=0; i<4*N+1; i++){
            tree[i] = 0;
            lazy[i] = 0;
        }
    }
    long long operation(long long a, long long b){
        return (a & b);
    }
    long long operation2(long long a, long long b){
        return (a | b);
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
    void update(int l, int r, int ind, int i, int j, int val){
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
    void tv(){
        for(auto it: tree) cout << it << " "; cout << endl;
    }
};
int main(){
    return 0;
}