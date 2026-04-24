#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, n, l, r;
ll dp[24][24][24];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	dp[1][1][1] = 1;
	for(int i = 2; i <= 20; i++){
		for(int j = 1; j <= 20; j++){
			for(int k = 1; k <= 20; k++){
				dp[i][j][k] += dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k] * (i-2);
			}
		}
	}
	
	while(T--){
		cin >> n >> l >> r;
		cout << dp[n][l][r] << "\n";
	}
	
}