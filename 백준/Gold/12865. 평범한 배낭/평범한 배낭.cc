#include <bits/stdc++.h>
using namespace std;
int N, W, V, K, dp[100004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for(int i = 0 ; i < N; i++){
		cin >> W >> V;
		for(int j = K; j >= W; j--){
			dp[j] = max(dp[j], dp[j-W] + V) ;
		}
	}
	cout << dp[K];
}