// pow 함수 -> double형이므로 조심 ㅠㅠㅠ  

#include <bits/stdc++.h>
using namespace std;

#define pow10 ppp
typedef long long ll;
ll N, pow10[12], dp[12], cnt, ret[12];

ll getPow(ll num){
	for(int i = 10; i >= 0; i--){
		if(num / pow10[i] >= 1) return i;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	// 0 상관없이 넣기 
	dp[0] = 0;
	pow10[0] = 1;
	for(int i = 1; i <= 10; i++){
		pow10[i] = pow10[i-1] * 10;
		dp[i] += i * pow10[i-1];
	}
	
	// 짜투리 넣기  
	ll k = getPow(N);
	for(ll tempk = k ; tempk >= 0; tempk--){
		ll div = pow(10, tempk);
		ll Q = N/div;
		ll R = N%div;
		
		for(int i = 0; i <=9; i++){
			ret[i] += Q * dp[tempk];
		}
		
		for(int i = 0; i < Q; i++){
			ret[i] += pow10[tempk];
		}
		
		ret[Q] += R+1;
		N = R;
	}
	
	// 허위 0 제거
	for(ll i = 0; i <= k; i++){
		ret[0] -= pow10[i];
	} 
	
	for(ll i = 0; i <= 9; i++){
		cout << ret[i] << " ";
	}
}