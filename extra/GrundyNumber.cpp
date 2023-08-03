#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;


// Problem Link - https://lightoj.com/problem/partitioning-game
const int N = 10001;
int grundy[N];
int MEX(map<int, int> &mpp){
    for(int i=0; ;i++){
        if(mpp[i] == 0) return i;
    }
}
void precompute(){
    for(int i=0; i<N; i++){
        map<int, int> mpp;
        for(int j=1; j < i - j; j++){
            int t = grundy[i-j]^grundy[j];
            mpp[t]++;
        }
       grundy[i] = MEX(mpp);
    }
}
void solve(int test){
    cout << "Case " << test << ": ";
    int n;
    cin >> n;
    int x = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        x ^= grundy[a];
    }
    cout << (x == 0 ? "Bob\n" : "Alice\n");
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t = 1;
    cin >> t;
    precompute();
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}