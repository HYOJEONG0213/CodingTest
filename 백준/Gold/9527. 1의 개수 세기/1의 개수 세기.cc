#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A, B, dp[60];

void init(){
	dp[0] = 0;
	for(int i = 1; i < 60; i++){
		dp[i] = dp[i-1] * 2 + (1LL << (i-1));
	}
}

ll f(ll N){
	if(N <= 0) return 0;
	//if(N == 1) return 1;
	
	ll i = 0;	// 최상위 비트 i 
	for(i = 59; i >= 0; i--){
		if(N & (1LL<<i)) break;
	}
	
	return dp[i] + (N - (1LL<<i) + 1) + f(N - (1LL << i));
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	cin >> A >> B;
	cout << f(B) - f(A-1);
}