#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000000;
int N;
ll dp[2][10][(1<<10) + 4], ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	int here = 0;
	for(int i = 1; i <= 9; i++){
		dp[here][i][1<<i] = 1;
	}
	for(int i = 2; i <= N; i++){
		int next = 1 - here;
		
		memset(dp[next], 0, sizeof(dp[next]));
		
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <= (1<<10)-1; k++){
				if(dp[here][j][k]==0) continue;
				
				
				
				if(j > 0){
					int bit = k | (1<<(j-1));
					dp[next][j-1][bit] = (dp[next][j-1][bit] + dp[here][j][k]) % MOD;
				}
				if(j < 9){
					int bit = k | (1<<(j+1));
					dp[next][j+1][bit] = (dp[next][j+1][bit] + dp[here][j][k]) % MOD;
				}
			}
		}
		here = next;
	}

	for(int j = 0; j <= 9; j++){
		ret = (ret + dp[here][j][(1<<10) - 1]) % MOD;
	}
	cout << ret;
	
}