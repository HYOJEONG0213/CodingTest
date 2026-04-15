#include <bits/stdc++.h>
using namespace std;

int N, M, a, VIP[44], dp[44];

int go(int idx){
	if(idx >= N) return 1;
	if(VIP[idx] == 1) return go(idx+1);
	
	int &ret = dp[idx];
	if(ret != -1) return ret;
	ret = 0;
	
	if(VIP[idx+1] == 1) return ret += go(idx+1);
	else{
		return ret +=  go(idx+2) + go(idx+1);
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> a;
		VIP[a] = 1;
	}
	
	cout << go(1);
}