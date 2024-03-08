#include <bits/stdc++.h>
using namespace std;

void solve(int test){
    int n;
    cin >> n;
    long long v[n]; 
    set<int> st;   
    map<int, int> mpp;
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n; i++){
        int newpos = i + v[i%n];
        mpp[(newpos + n)%n]++;
    }
    if(mpp.size() == n){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}