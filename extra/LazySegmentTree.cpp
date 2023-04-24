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
int main(){
    return 0;
}