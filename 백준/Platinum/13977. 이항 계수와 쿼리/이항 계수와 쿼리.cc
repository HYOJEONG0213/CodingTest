#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
ll M, N, K, dp[4000004];

ll f(ll num, ll exp){
	ll ret = 1;
	num %= MOD;
	
	while(exp > 0){
		if(exp % 2 == 1){
			ret = (ret * num) % MOD;
		}
		
		num = (num * num) % MOD;
		exp /= 2;
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	
	dp[0] = 1;
	for(int i = 1; i <= 4000000; i++){
		dp[i] = (dp[i-1]*i) % MOD;
	}
	
	for(int i = 0; i < M; i++){
		cin >> N >> K;
		ll factN = dp[N];
		ll factK = (dp[K] * dp[N-K]) % MOD;
		
		ll temp = (dp[N] * f(factK, MOD-2)) % MOD;
		cout << temp << "\n";
	}
	
}