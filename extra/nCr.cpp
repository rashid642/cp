#include<bits/stdc++.h>
using namespace std;
class nCr{
    public:
    vector<long long> fac;
    int mod;
    nCr(int mod){
        mod = _mod; 
        fac.resize(1e6+5, 0);
        fac[0] = 1;
        for(int i=1; i<fac.size(); i++){
            fac[i] = (fac[i-1] * i)%mod;
        }
    }
    long long binaryExponentiation(long long a, long long b){
        // a^b;
        if(b == 0) return 1;
        long long ans = binaryExponentiation(a, b/2);
        ans = (ans*ans) % mod;
        if(b%2) ans = (ans*a) % mod;
        return ans;
    }
    long long moduloInverse(long long a){
        return binaryExponentiation(a, mod - 2);
    }
    long long combination(int n, int r){
        long long ans = fac[n];
        ans = (ans * moduloInverse(fac[n-r])) % mod;
        ans = (ans * moduloInverse(fac[r])) % mod;
        return ans;
    }
};
int main(){
    // cout << "at start" << endl;
    nCr n(1e9+7);
    long long ans = n.combination(100,95);
    cout << ans << endl;
    return 0;
}
