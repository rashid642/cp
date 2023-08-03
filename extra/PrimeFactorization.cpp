// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 10;
int spf[MAXN];
void sieve() {
	spf[1] = 1;
	for (int i=2; i<MAXN; i++) spf[i] = i;
	for (int i=4; i<MAXN; i+=2) spf[i] = 2;
	for (int i=3; i*i<MAXN; i++) {
		if (spf[i] == i) {
			for (int j=i*i; j<MAXN; j+=i)
				if (spf[j]==j) spf[j] = i;
		}
	}
}
vector<int> getFactorization(int x) {
	vector<int> ret;
	while (x != 1) {
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}




// prime factros upto 1e9
vector<int> primeFactors(int n){
	set<int> st;
    while (n % 2 == 0) {
		st.insert(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
			st.insert(i);
            n = n/i;
        }
    } 
    if (n > 2) st.insert(n);
	vector<int> v;
	for(auto it: v) v.push_back(it);
	return v;
}


// more optimal
vector<long long> wheel(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        if(n % d == 0)
            factorization.push_back(d);
        while (n % d == 0) {
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        if(n % d == 0)
            factorization.push_back(d);
        while (n % d == 0) {
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}





// driver program for above function
int main(int argc, char const *argv[])
{
	// precalculating Smallest Prime Factor
	sieve();
	int x = 9856;
	cout << "prime factorization for " << x << " : ";

	// calling getFactorization function
	vector <int> p = getFactorization(x);

	for (int i=0; i<p.size(); i++)
		cout << p[i] << " ";
	cout << endl;
	return 0;
}
