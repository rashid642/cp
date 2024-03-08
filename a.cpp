#include <bits/stdc++.h>
using namespace std;

void solve(int test){
    long long k, x, a;
    cin >> k >> x >> a;
    // goal is to reach a + 1
    long long l = 0, r = a - x;
    long long pos = -1;
    while(l <= r){
        long long mid = (l + r) / 2;
        long long t = (a - x) + mid*(k - 1);
        if(t >= a + 1){
            cout << t << " " << mid << "\n";
            pos = t;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    if(pos == a + 1){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}