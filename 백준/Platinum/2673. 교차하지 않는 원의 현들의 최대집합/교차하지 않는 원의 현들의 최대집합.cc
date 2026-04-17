#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int N, a, b, visited[104][104], dp[104][104];


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		visited[a][b] = 1;
		visited[b][a] = 1;
	}
	
	for(int len = 1; len < 100; len++){
		for(int i = 1; i+len <= 100; i++){
			int j = i+len;
			for(int k = i; k < j; k++){
				dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]);
			}
			dp[i][j] += visited[i][j];
		}
	}
	
	cout << dp[1][100];
}