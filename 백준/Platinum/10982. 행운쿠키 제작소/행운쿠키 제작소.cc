#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int TIME= 100000;
int T, N, a, b;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		cin >> N;
		vector <int> dp(TIME+4, INF);
		dp[0] = 0;

		
		for(int i = 0; i < N; i++){
			cin >> a >> b;
			
			// 반죽 하나당 하나만 넣어야하므로  
			vector <int> temp(TIME+4, INF);
			
			for(int j = 0; j <= TIME; j++){
				if(dp[j]==INF) continue;
				
				// 오븐 a에 넣기
				if(j + a <= TIME)
					temp[j+a] = min(temp[j+a], dp[j]);
				// 오븐 b에 넣기  
				temp[j] = min(temp[j], dp[j]+b);
			}
			dp = temp;
		}
		
		int ret = INF;
		for(int i = 0; i <= TIME; i++){
			ret = min(ret, max(i, dp[i]));
		}
		cout << ret << "\n";
	}
	
	
	
	
}