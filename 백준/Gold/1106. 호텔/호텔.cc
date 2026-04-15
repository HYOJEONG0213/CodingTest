#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int max_n = 1104;
int C, N, price, cus, dp[max_n], ret=INF;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> C >> N;
	fill(dp, dp+max_n, INF);
	dp[0] = 0;
	for(int i = 0; i < N; i++){
		cin >> price >> cus;
		for(int j = cus; j < max_n; j++){
			dp[j] = min(dp[j], dp[j-cus] + price);
			if(j>=C) ret = min(ret, dp[j]);
		}
	}
	
	
	cout << ret;
}