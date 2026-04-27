#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int TIME= 100000;
int T, N, a, b;
// 0 : 현재, 1 : next  
int dp[2][TIME+4];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		cin >> N;
		
		fill(&dp[0][0], &dp[0][0]+(TIME+4)*2, INF);
		dp[0][0] = 0;
		
		int cur = 0;
		int next = 1;
		int sum = 0;

		for(int i = 0; i < N; i++){
			cin >> a >> b;
			sum += a;
			fill(&dp[next][0], &dp[next][0]+TIME+4, INF);
			
			for(int j = 0; j <= sum; j++){
				if(dp[cur][j]==INF) continue;
				
				// 오븐 a에 넣기
				if(j + a <= TIME)
					dp[next][j+a] = min(dp[next][j+a], dp[cur][j]);
				// 오븐 b에 넣기  
				dp[next][j] = min(dp[next][j], dp[cur][j]+b);
			}
			swap(cur, next);
		}
		
		int ret = INF;
		for(int i = 0; i <= TIME; i++){
			ret = min(ret, max(i, dp[cur][i]));
		}
		cout << ret << "\n";
	}
	
	
	
	
}