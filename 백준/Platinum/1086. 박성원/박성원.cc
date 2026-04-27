#include <bits/stdc++.h>
using namespace std;

#define pow10 ppppp
typedef long long ll;
ll N, B[18], K, dp[1<<15][100], pow10[54];
string A[18];

void init(){
	pow10[0] = 1 % K;
	for(int i = 1; i < 51; i++){
		pow10[i] = (pow10[i-1]*10) % K;
	}
}

ll getGCD(ll p, ll q){
	if(q==0) return p;
	
	return getGCD(q, p%q);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	cin >> K;
	init();
	for(int i = 0; i < N; i++){
		int reminder = 0;
		for(int j = 0; j < A[i].size(); j++){
			int digit = A[i][j] - '0';
			reminder = (reminder * 10 + digit) % K;
		}
		B[i] = reminder;
		
		dp[1<<i][B[i]]++;
	}
	
	for(int i = 0; i < 1<<N ; i++){
		for(int j = 0; j < K; j++){
			if(dp[i][j]==0) continue;
			
			for(int k = 0 ; k < N; k++){
				if((i&(1<<k))==0){	//아직 안썼다면 
					int reminder = (j * pow10[A[k].size()] + B[k]) % K;
					dp[i|(1<<k)][reminder] += dp[i][j];
				}
			}
		}
	}
	
	ll total = 1;
	for(int i = 2; i<=N;i++){
		total *= i;
	}
	
	ll sum = dp[(1<<N)-1][0];
	ll gcd = getGCD(sum, total);
	
	cout << sum/gcd << "/" << total/gcd;
}