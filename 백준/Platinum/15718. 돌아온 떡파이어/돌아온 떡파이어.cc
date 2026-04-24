#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD1 = 97;
const ll MOD2 = 1031;
const ll MOD = 100007;

ll T, N, M;
ll dp1[MOD1+4], dp2[MOD2+4];

ll f(ll base, ll exp, ll mod){
	ll ret = 1;
	base %= mod;
	
	while(exp > 0){
		if(exp % 2){
			ret = (ret * base) % mod;
		}
		base = (base*base) % mod;
		exp /= 2;
	}
	
	return ret;
}

ll getInverse(ll n, ll mod){
	return f(n, mod-2, mod);
}

ll nCm(ll n, ll m, ll mod, ll fact[]){
	if(n < m || m < 0) return 0;
	
	ll factn = fact[n];
	ll factp = (fact[m] * fact[n-m]) % mod;
	return (factn * getInverse(factp, mod)) % mod;
}

ll lucas(ll n, ll r, ll mod, ll fact[]){
	if(r < 0 || n < r) return 0;
	if(r == 0) return 1;
	
	return (lucas(n / mod, r / mod, mod, fact) * nCm(n % mod, r % mod, mod, fact)) % mod;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	
	dp1[0] = 1;
	dp2[0] = 1;
	for(int i = 1; i <= MOD1; i++){
		dp1[i] = (dp1[i-1] * i) % MOD1;
	}
	for(int i = 1; i <= MOD2; i++){
		dp2[i] = (dp2[i-1] * i) % MOD2;
	}
	
	// 모듈러 역원 구하고  
	ll m1 = MOD1, m2 = MOD2;
	ll inv1 = getInverse(m2, m1);
	ll inv2 = getInverse(m1, m2);
	
	while(T--){
		cin >> N >> M;
		
		if(N == 0 && M == 1){
			cout << 1 << "\n";
			continue;
		}
		if(M == 1 || M > N+1){
			cout << 0 << "\n";
			continue;
		}
		
		ll n = N-1;
		ll m = M-2;
		
		// 각 mod별로 뤄카 정리 후 
		ll ret1 = lucas(n, m, MOD1, dp1);
		ll ret2 = lucas(n, m, MOD2, dp2);
		
		// 나머지정리  
		cout << (ret1 * m2  % MOD * inv1 % MOD
		+ ret2 * m1 % MOD * inv2 % MOD) % MOD << "\n";
	}
	
}