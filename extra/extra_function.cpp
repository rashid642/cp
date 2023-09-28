#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll giveSqrt(ll x){
    ll low = 1, high = 3e9, ans = 1;
    while(low<=high){
        ll mid = (low+high)/2;
        if(mid*mid<=x){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}
ll power(ll a, ll b, ll modu){ // a ^ b
    if(b == 0) return 1LL;
    ll ans = power(a, b/2, modu);
    ans = (ans * ans)%modu;
    if(b%2) ans = (ans*a);
    return ans % modu;
}
ll handlePower(ll a, ll b){ // a ^ b
    if(b == 0) return 1LL;
    ll ans = handlePower(a, b/2);
    if(ans == -1) return -1;
    __int128 t = (ans * ans);
    if(t > 1e10) return -1;
    ans = t;
    if(b%2) {
        __int128 t = (ans*a);
        if(t > 1e10) return -1;
        ans = (ans*a);
    }
    return ans;
}
vector<ll> getFactors(ll n){
    vector<ll> v;
    for(ll i=1; i*i <= n; i++){
        if(n%i == 0){
            v.push_back(i);
            if(i != n/i) v.push_back(n/i);
        }
    }
    return v;
}
vector<bool> primeNumber(int n){
    vector<bool> v(n, true);
    v[0] = false; v[1] = false; v[2] = true;
    for(int i=2; i<n; i++){
        if(v[i]){
            for(int j=i*2; j<n; j = j+i) v[j] = false;
        }
    }
    return v;
}

int main(){
    return 1;
}