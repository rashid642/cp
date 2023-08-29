#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;

void precompute(){
}
int solve(int n, vector<vector<int>> v) {
    // int n;
    // std::cin >> n;
    vector<vector<int>> b(n, vector<int>(n)), a(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = v[i+1][j+1];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] ^= b[i][j];
            ans += a[i][j];
            b[i][j] ^= a[i][j];
            a[i][j] ^= b[i][j];
            if (i + 1 < n) {
                a[i + 1][j] ^= b[i][j];
                if (j - 1 >= 0) {
                    b[i + 1][j - 1] ^= b[i][j];
                } else if (i + 2 < n) {
                    b[i + 2][j] ^= b[i][j];
                }
                if (j + 1 < n) {
                    b[i + 1][j + 1] ^= b[i][j];
                } else if (i + 2 < n) {
                    b[i + 2][j] ^= b[i][j];
                }
                if (i + 2 < n) {
                    b[i + 2][j] ^= b[i][j];
                }
            }
            b[i][j] = 0;
        }
    }
    // std::cout << ans << "\n";
    return ans;
}
void solve(int test){
    int n = 3;
    // cin >> n;
    vector<vector<int>> v(n+10, vector<int>(n+10, 0)), tempv;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=n; j++){
            // v[i+1][j] = s[j-1] - '0';
            v[i+1][j] = rand() % 2;
            // cin >> v[i+1][j];
        }
    }
    tempv = v;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++) cout << v[i][j] << " "; cout << endl;
    // }
    ll t = solve(n, v);
    vector<int> start(n + 10, 0), end(n + 10, 0);
    int ans = 0;
    for(int i=1; i<=n; i++){
        vector<int> t(n + 1, 0);
        for(int j=1; j<=n; j++) {
            t[j] = t[j-1] + start[j] - end[j];
        }
        // tv(t);
        for(int j=1; j<=n; j++){
            if(t[j]%2) v[i][j] ^= 1;
            if(v[i][j]){
                ans++;
                start[j]++;
                end[j+1]++;
            }
        }
        vector<int> nstart(n + 10, 0), nend(n + 10, 0);
        for(int j=1; j<=n; j++){
            if(start[j]){
                if(j-1 == 0) nstart[j] = start[j];
                else nstart[j-1] = start[j];
            }
            if(end[j]){
                nend[j+1] = end[j];
            }
        }
        start = nstart;
        end = nend;
        // tv(start); 
        // tv(end);
        // cout << endl;
    }
    if(ans != t){
        cout << ans << " " << t << endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++) cout << tempv[i][j] << " "; cout << endl;
        }
    }
    // cout << ans << endl;
}   
int main() {
    srand(time(NULL));
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