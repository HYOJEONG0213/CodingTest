#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000000;
int N;
ll dp[104][10][(1<<10) + 4], ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	for(int i = 1; i <= 9; i++){
		dp[1][i][1<<i] = 1;
	}
	for(int i = 2; i <= N; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <= (1<<10)-1; k++){
				int next = k | (1<<j);
				
				if(j > 0){
					dp[i][j][next] = (dp[i][j][next] + dp[i-1][j-1][k]) % MOD;
				}
				if(j < 9){
					dp[i][j][next] = (dp[i][j][next] + dp[i-1][j+1][k]) % MOD;
				}
			}
		}
	}

	for(int j = 0; j <= 9; j++){
		ret = (ret + dp[N][j][(1<<10) - 1]) % MOD;
	}
	cout << ret;
	
}