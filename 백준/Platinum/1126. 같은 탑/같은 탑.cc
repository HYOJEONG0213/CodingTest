#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, dp[54][500004], H[54];

int f(int idx, int diff){
	if(idx == N) {
		if(diff == 0) return 0;
		else return -INF; 
	}
	int &ret = dp[idx][diff];
	if(ret != -1) return ret;
	
	ret = -INF;
	
	ret = max(ret, f(idx+1, diff));		// 안쌓는 경우
	if(diff+H[idx] <= 500000){
		ret = max(ret, f(idx+1, diff+H[idx])+H[idx]);	//높은 탑에 쌓는 경우 
	}
	
	// 낮은 탑에 쌓는 경우  
	if(diff - H[idx] < 0){
		ret = max(ret, f(idx+1, H[idx]-diff)+H[idx]-diff);
	}
	else{
		ret = max(ret, f(idx+1, diff-H[idx]));
	}
	
	return ret;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> H[i];
	}
	
	int ret = f(0, 0);
	cout << (ret <= 0 ? -1 : ret);
}