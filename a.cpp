#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;

void precompute(){
}
vector<int> LPS(string s){
    int n = s.size();
    vector<int> lps(n, 0);
    int j = 0;
    for(int i=1; i<n; i++){
        if(s[i] == s[j]){
            j++;
            lps[i] = j;
        }else{
            if(j == 0){
                continue;
            }else{
                j = lps[j-1];
                i--;
            }
        }
    }
    return lps;
}
void solve(int test){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v = LPS(s);
    tv(v);
    multiset<int> ms;
    int j = v[n-1];
    while(j != 0){
        ms.insert(j);
        j = v[j-1];
    }
    tv(ms);
    map<int, int> mpp;
    for(int i=1; i<n-1; i++){
        if(ms.find(v[i]) != ms.end()){
            mpp[v[i]]++;
        }
    }
    cout << mpp.size() << endl;
    for(auto it: mpp) cout << it.first << " " << it.second << endl;
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t = 1;
    // cin >> t;
    precompute();
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}