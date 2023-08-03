#include<bits/stdc++.h>
using namespace std;
#define ll long long
//        ind
//  2*ind+1  2*ind+2
class SegmentTree{
    public: 
    vector<ll> tree;
    int n;
    SegmentTree(int _n){
        n = _n;
        for(int i=0; i<4*n+1; i++) tree.push_back(-1);
    }
    ll operation(ll a, ll b){
        return a + b;
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
        if(j < l || r < i) return 0;
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
    ll make_query(int l, int r){
        return query(l, r, 0, n-1, 0);
    }
    void make_update(int ind, int val){
        update(0, n-1, 0, val, ind);
    }
};

int main(){
    vector<ll> v = {1,5,3,4,7,8,2,1};
    int n = v.size();
    SegmentTree *st = new SegmentTree(n);
    st->build(v, 0, n-1, 0);
    vector<ll> tree = st->tree;
    for(auto it: tree){
        cout << it << " ";
    }
    cout << endl;
    cout << "before :"; 
    cout << st->query(n-2, n-1, 0, n-1, 0) << endl;
    st->update(0, n-1, 0, 10, n-1);
    cout << "After :";
    cout << st->query(n-2, n-1, 0, n-1, 0) << endl;
    return 0;
}