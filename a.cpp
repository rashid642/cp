#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(n, m) for(int i=n; i<m; i++)
#define repj(n, m) for(int j=n; j<m; j++)
#define repk(n, m) for(int k=n; k<m; k++)
#define rrep(n, m) for(int i=n; i>=m; i--)
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define sv(v) sort(v.begin(), v.end())
#define sr(v) sort(v.begin(), v.end()); reverse(v.begin(), v.end());
#define sa(arr, n) sort(arr, arr+n)
#define endll "\n\n"
#define endl "\n"
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
// number of subset index ind belong = (ind+1)(n-ind) with 0 indexing
// If a particular bit is set in array then if we take all the subsequence of that
// array then that set bit will will occur 2^(n-1) times

// Cin overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p){return (istream >> p.first >> p.second);}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v){for (auto &it : v) cin >> it; return istream;}

void precompute(){
}
void solve(int test){
    
}
int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0); 
    ll t = 1;
    precompute();
    cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}
