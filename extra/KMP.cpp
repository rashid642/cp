#include<bits/stdc++.h>
using namespace std;
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
int main(){
    // string s = "AABAACAADAABAABA";
    // LPS(s);
    KMP("baabaaa", "aa");
    return 1;
}