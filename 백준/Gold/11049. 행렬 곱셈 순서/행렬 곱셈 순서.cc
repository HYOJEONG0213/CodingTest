#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, dp[504][504], matrix[504][2];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(&dp[0][0], &dp[0][0]+504*504, INF);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> matrix[i][0] >> matrix[i][1];
		dp[i][i] = 0;
	}
	for(int inter = 0; inter < N; inter++){
		for(int i = 0; i+inter < N; i++){
			for(int p = i; p < (i+inter); p++){
				dp[i][i+inter] = min(dp[i][i+inter], 
				dp[i][p]+dp[p+1][i+inter]
				+matrix[i][0]*matrix[p][1]*matrix[i+inter][1]);
			}
		}
	}
	cout << dp[0][N-1];
}