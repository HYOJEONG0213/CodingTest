#include <bits/stdc++.h>
using namespace std;
int N, K, A[104], dp[10004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	fill(dp, dp+10004, 987654321);
	dp[0] = 0;
	for(int i = 0 ; i < N; i++){
		cin >> A[i];
		for(int j = A[i]; j <= K; j++){
			dp[j] = min(dp[j], dp[j - A[i]] + 1);
		}
	}
	cout << (dp[K] == 987654321 ? -1 : dp[K]);
}