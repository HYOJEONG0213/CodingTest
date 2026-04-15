#include <bits/stdc++.h>
using namespace std;
int N, K, w[104], payW[104], r[104], payR[104], dp[104][100004];

int go(int idx, int t){
	if(t > K){
		return -1e08;
	}
	if(idx >= N){
		return 0;
	}
	
	int &ret = dp[idx][t];
	if(ret!=-1) return ret;
	ret = -1e08;
	ret = max(go(idx+1, t + w[idx]) + payW[idx], go(idx+1, t + r[idx]) + payR[idx]);
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	for(int i = 0 ; i < N ; i++){
		cin >> w[i] >> payW[i] >> r[i] >> payR[i];
	}
	
	cout << go(0, 0);
}