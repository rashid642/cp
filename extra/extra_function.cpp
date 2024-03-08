#include<bits/stdc++.h>
using namespace std;

// #define long long long long

long long giveSqrt(long long x){
    long long low = 1, high = 3e9, ans = 1;
    while(low<=high){
        long long mid = (low+high)/2;
        if(mid*mid<=x){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}
long long power(long long a, long long b, long long modu){ // a ^ b
    if(b == 0) return 1;
    long long ans = power(a, b/2, modu);
    ans = (ans * ans)%modu;
    if(b%2) ans = (ans*a);
    return ans % modu;
}

const long long inf = 1e18 + 10;
long long handlePower(long long a, long long b){ // a ^ b
    if(b == 0) return 1;
    long long ans = handlePower(a, b/2);
    if(ans == -1) return -1;
    __int128 t = ((__int128)1*ans * ans);
    if(t >= inf) return -1;
    ans = t;
    if(b%2) {
        __int128 t = ((__int128)1*ans*a);
        if(t > inf) return -1;
        ans = (ans*a);
    }
    return ans;
}
vector<long long> getFactors(long long n){
    vector<long long> v;
    for(long long i=1; i*i <= n; i++){
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
class ModuloOpertion{
    public:
    int mod;
    ModuloOpertion(int _mod){
        mod = _mod;
    }
    long long binaryExponentiation(long long a, long long b){
        // a^b;
        if(b == 0) return 1;
        long long ans = binaryExponentiation(a, b/2);
        ans = (ans*ans) % mod;
        if(b%2) ans = (ans*a) % mod;
        return ans;
    }
    long long add(long long a, long long b){
        return (a + b) % mod;
    }
    long long multiply(long long a, long long b){
        return (a*b) % mod;
    }
    long long divide(long long a, long long b){ // a / b
        long long inv = binaryExponentiation(a, mod-2);
        return multiply(a, inv);
    }
    long long sub(long long a, long long b){
        return ((a - b + mod) % mod + mod) % mod;
    }
};
/*
floor x -> n <= x < n + 1
ceil x -> n - 1 < x <= n

let y = floor(x + a) where x and a both are integer
n <= x + a < n + 

x <= 5/3 - 1 take 5/3 as floor
x >= 5/3 - 1 take 5/3 as ceil

fermat's thearem 
a^(p-1) % p = 1 {where p is prime} --> fermat's little thearem
but this only workds when p is prime

so when p isn't prime
a * a^-1 = 1 (mod m)
ax = 1 (mod m) taking a^-1 as x
ax + my = 1 // as we are taking mod m so we can add any number of m
here we can apply linear diophantine equation
here gcd(a, b) = 1
and we can just apply that and find x which is inverse

LINEAR CONGRUENCE
ax = b (mod m) -> find value of x such that ax%m = m
ax + my = b
here also gcd(a, m) = 1
and we can again apply that diophantine equation and get x

from the above question if we have to find what all possible values of b is possible
then gcd(a, m) needs to divide b and find all values
which is m / gcd(a, m)
*/
// from xp algo
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main(){
    return 1;
}