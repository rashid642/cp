// get fenwick tree equals to size of the array + 1
// so for example if it has 5 elements
// 0   1       2       3       4        5
//   (1,1)   (1,2)   (3,3)   (1,4)     (5,5)

// to get range
// 1. left range: switch off right most bit and add 1
//     2 -> 10 -> 00 -> 0 + 1 = 1;
// 2. right range: is same as index

// first initialize fenwick tree with 0
// to update value
// so if you want to update value at index 3
// so first go at 3rd index of fenwick tree and add the value
// now to update next value which have 3 in range follow these steps:
// 1. take 2's compliment
// 2. and with orignal number
// 3. add to orignal number

// so for example
// index = 3 = 11
// two's compliment = 01
// and with orignal = 01
// add orignal 01 + 11 = 4
// so next we need to update 4th index in fenwick tree
// easy way => i = i + (i & (-i))

// to get sum of a range
// it's similar to update just subtract orignal from 
// so for example if you want to get sum of range 1 to 3
// index = 3 = 11
// two's compliment = 01
// and with orignal = 01
// add orignal 11 + 01 = 2

#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int fen[N];
void update(int i, int add){
    while(i < N){
        fen[i] += add;
        i = i + (i & (-i));
    }
}
int sum(int i){
    int sum = 0;
    while(i > 0){
        sum += fen[i];
        i = i - (i & (-i));
    }
    return sum;
}
int rangeSum(int l, int r){
    return sum(r) - sum(l-1);
}
class FenwickTree{
    public:
    vector<int> tree;
    int n;
    FenwickTree(vector<int> &v){
        n = v.size();
        tree.resize(n+1, 0);
        for(int i=0; i<n; i++) update(i, v[i]);
    }
    void update(int i, int val){
        for(i++; i<=n; i += (i&-i)) tree[i] += val;
    }
    int sum(int i){
        int s = 0;
        for(i++; i>0; i -= (i&-i)) s += tree[i];
        return s;
    }
    int query(int l, int r){
        return sum(r) - sum(l - 1);
    }
};
class FenwickTree2D{
    public:
    vector<vector<int>> tree;
    int n, m;
    FenwickTree2D(vector<vector<int>> &v){
        n = v.size(), m = v[0].size();
        tree.resize(n+1, vector<int>(m+1, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                update(i, j, v[i][j]);
            }
        }
    }
    void update(int x, int y, int val){
        for(int i = x + 1; i<=n; i += (i&-i)){
            for(int j = y + 1; j<=m; j += (j&-j)){
                tree[i][j] += val;
            }
        }
    }
    int sum(int x, int y){
        int s = 0;
        for(int i = x + 1; i>0; i -= (i&-i)){
            for(int j = y + 1; j>0; j -= (j&-j)){
                s += tree[i][j];
            }
        }
        return s;
    }
    int query(int r1, int c1, int r2, int c2){
        return sum(r2, c2) - sum(r1-1, c2) - sum(r2, c1-1) + sum(r1-1, c1-1);
    }
};
int main(){
    vector<vector<int>> a = {{1,2,3,4},{2,3,4,5},{3,4,5,6}};
    FenwickTree2D ft2(a);
    cout << ft2.query(0,0, 2,3) << endl;
    ft2.update(1,1,10);
    return 0;
}

    // vector<int> v = {1,2,3,4,5,6};
    // FenwickTree ft(v);
    // cout << ft.query(1,3) << endl; // 2 + 3 + 4 -> 9
    // ft.update(1, -2);
    // ft.update(1, 20);
    // cout << ft.query(1, 3) << endl; // 10 + 3 + 4 -> 17
