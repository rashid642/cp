#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;

void precompute(){
}
void solve(int test){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag = 0;
    for(int i=0; i<n; i++){
        if(s[i] != '0') {
            s = s.substr(i);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << 0 << endl;
        return;
    }
    n = s.size();
    int ind = 0;
    int firstOne = 0;
    while(ind < n && s[ind] == '1') ind++;
    if(ind == n){
        cout << s << endl;
        return;
    }
    int firstZero = ind;
    string ans = s;
    for(int i=firstOne; i<firstZero; i++){
        string t = s.substr(i);
        string t2 = s;
        for(int j=firstZero, k = 0; j<n && k < t.size(); j++, k++){
            if(t[k] == '1' || s[j] == '1'){
                t2[j] = '1';
            }
        }
        ans = max(ans, t2);
    }
    cout << ans << endl;
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