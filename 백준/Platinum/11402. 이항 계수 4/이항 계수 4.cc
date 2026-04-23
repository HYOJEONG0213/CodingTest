#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, M, K, dp[2004], ret=1;

ll f(ll base, ll exp){
	ll ret = 1;
	
	while(exp > 0){
		if(exp % 2){
			ret = (ret * base) % M;
		}
		
		base = (base * base) % M;
		exp /= 2;
	}
	
	return ret;
}

ll nCk(ll n, ll k){
	ll factN = dp[n];
	ll factp = (dp[k] * dp[n-k]) % M;
	ll p = f(factp, M-2);
	return (factN * p) % M;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> M;
	
	dp[0]= 1;
	for(ll i = 1; i <= M; i++){
		dp[i] = (dp[i-1] * i) % M;
	}
	
	
	while(N > 0 || K > 0){
		ll ni = N % M;
		ll ki = K % M;
		
		ret = (ret * nCk(ni, ki)) % M;
		
		N /= M;
		K /= M;
	}
	
	cout << ret;
	
}