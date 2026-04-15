#include <bits/stdc++.h>
using namespace std;
int N , ret, dp[1000004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= N; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % 15746;
	}
	
	cout << dp[N];
}