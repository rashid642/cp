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
    vector<int> v(n, 0);
    int j = 0;
    for(int i=1; i<n; i++){
        if(s[i] == s[j]){
            j++;
            v[i] = j;
        }else{
            if(j == 0){
                v[i] = 0;
            }else{
                j = v[j-1];
                i--;
            }
        }
    }
    return v;
}
vector<int> KMP(string s, string pat){
    /*
    the other method would be just attach two string
    like news = pat + '$' + s;
    */
    int n = s.size(), m = pat.size();
    vector<int> v = LPS(pat);
    int j = 0;
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(s[i] == pat[j]){
            j++;
            if(j == m) {
                j = v[j-1];
                ans.push_back(i - m + 1);
            }
        }else{
            if(j == 0){
                continue;
            }
            j = v[j-1];
            i--;
        }
    }
    return ans;
}
void solve(int test){
    string s, pat;
    cin >> s >> pat;
    vector<int> ans = KMP(s, pat);
    if(ans.size() == 0){
        cout << "Not Found\n\n";
        return;
    }
    cout << ans.size() << endl;
    for(auto it: ans) cout << it + 1 << " "; cout << endl;
    cout << endl;
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