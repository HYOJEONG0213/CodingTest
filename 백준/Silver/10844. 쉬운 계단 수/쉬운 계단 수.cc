#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, dp[104][10];

//dp[해당 길이에서][해당 숫자] 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	ll ret = 0;
	
	for(int i = 1; i <= 9; i++){
		dp[1][i] = 1;
	}
	dp[1][0] = 0;
	
	for(int i = 2; i <= N; i++){
		for(int j = 0 ; j <= 9; j++){
			if(j-1 >= 0)	
				dp[i][j] += dp[i-1][j-1];
			if(j+1 <= 9)
				dp[i][j] += dp[i-1][j+1];
			dp[i][j] %= 1000000000;
		}
	}
	
	for(int i = 0; i <= 9; i++){
		ret += dp[N][i] % 1000000000;
	}
	
	cout << ret % 1000000000;
}