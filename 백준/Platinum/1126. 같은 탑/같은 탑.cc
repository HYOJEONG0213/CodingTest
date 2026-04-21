#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, dp[500004], temp[500004], H[54];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(dp, dp+500004, -INF);
	dp[0] = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> H[i];
		
		fill(temp, temp+500004, -INF);
		for(int j = 0; j <= 500000; j++){
			if(dp[j] < 0) continue;
			// 선택하지 않는 경우
			temp[j] = max(temp[j], dp[j]);
			
			// 높은거에 포함시키기
			if(j+H[i] <= 500000) 	
				temp[j+H[i]] = max(temp[j+H[i]], dp[j]+H[i]);
			
			// 낮은거에 포함시키기  
			if(j < H[i]){
				// 기존 낮은탑 높이 : dp[j] - j 
				temp[H[i]-j] = max(temp[H[i]-j], dp[j]-j + H[i]);
			}
			else{
				temp[j-H[i]] = max(temp[j-H[i]], dp[j]);
			}
		}
		copy(temp, temp+500004, dp);
	}
	
	cout << (dp[0] <= 0 ? -1 : dp[0]);
}