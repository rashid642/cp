#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;
void computeLPSArray(string pat, int M, int* lps);
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
// Prints occurrences of txt[] in pat[]
vector<int> KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
   vector<int> t = LPS(pat);
   tv(t);
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
    vector<int> ans;
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
    for(int i=0; i<M; i++) cout << lps[i] << " "; cout << endl;
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            // printf("Found pattern at index %d ", i - j);
            ans.push_back(i - j);
            j = lps[j - 1];
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return ans;
}
 
// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(string pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void precompute(){
}
void solve(int test){
    string s, pat;
    cin >> s >> pat;
    vector<int> ans = KMPSearch(pat, s);
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