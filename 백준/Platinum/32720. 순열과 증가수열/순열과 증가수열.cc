#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
ll M, N, K, dp[1000004];

ll f(ll base, ll exp){
	ll ret = 1;
	base %= MOD;
	
	while(exp > 0){
		if(exp % 2){
			ret = (ret*base) % MOD;
		}
		base = (base*base)%MOD;
		exp /= 2;
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	
	dp[0] = 1;
	for(int i = 1; i <= 1000000; i++){
		dp[i] = (dp[i-1]*i) % MOD;
	}
	
	ll Q = N / K;
	ll R = N % K;
	ll num1 = R;		//q+1 그룹이 총 R개  
	ll num0 = K - R;	//q 그룹이 총 K-R개  
	
	ll factN = dp[N];	// N!
	ll factnum1 = f(dp[Q+1], R);	// Q+1 그룹 
	ll factnum0 = f(dp[Q], K-R);
	ll p = (factnum1 * factnum0) % MOD;
	
	cout << (factN * f(p, MOD-2)) % MOD;
}