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
    for(auto it: v) cout << it << " "; cout << endl;
    return v;
}
int main(){
    string s = "AABAACAADAABAABA";
    LPS(s);
    return 1;
}