#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
// cost : 인덱스, 색깔  
// dp : 인덱스, 색깔   
int N, dp[1004][3], cost[1004][3], ret = INF;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	for(int i = 0; i < 3; i++){
		for(int j = 1; j <= N; j++){
			dp[j][0] = dp[j][1] = dp[j][2] = INF;
		}
		dp[1][i] = cost[1][i];
		
		for(int idx = 2; idx <= N; idx++){
			dp[idx][0] = cost[idx][0] + min(dp[idx-1][1], dp[idx-1][2]);
			dp[idx][1] = cost[idx][1] + min(dp[idx-1][0], dp[idx-1][2]);
			dp[idx][2] = cost[idx][2] + min(dp[idx-1][0], dp[idx-1][1]);
		}
		
		for(int color = 0; color < 3; color++){
			if(color != i){
				ret = min(ret, dp[N][color]);
			}
		}
	}
	
	cout << ret;
}