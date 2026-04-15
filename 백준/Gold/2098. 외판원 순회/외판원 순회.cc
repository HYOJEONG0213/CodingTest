#include <bits/stdc++.h>
using namespace std;
const int INF = 1e09;;
int dp[(1<<16)+4][20], N, W[18][18];

int go(int visited, int idx){
	if(visited == (1<<N)-1){
		return W[idx][0] ? W[idx][0] : INF;
	}
	int &ret = dp[visited][idx];
	if(ret != -1) return ret;
	ret = INF;
	
	for(int i = 0; i < N; i++){
		if(visited & (1<<i)) continue;
		if(W[idx][i] == 0) continue;
		ret = min(ret, go(visited | (1<<i), i) + W[idx][i]);
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> W[i][j];
		}
	}
	
	cout << go(1, 0);
}