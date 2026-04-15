#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
struct{
	int a, b, c;
}A[1004];
int N, dp[1004][3];

int go(int idx, int recent){
	if(idx >= N) return 0;
	
	int &ret = dp[idx][recent];
	if(ret != -1) return ret;
	ret = INF;
	
	for(int i = 0; i < 3; i++){
		if(recent == i) continue;
		if(i == 0)
			ret = min(ret, go(idx+1, i) + A[idx].a);
		else if(i == 1)
			ret = min(ret, go(idx+1, i) + A[idx].b);
		else if(i == 2)
			ret = min(ret, go(idx+1, i) + A[idx].c);
	}
	
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i].a >> A[i].b >> A[i].c;
	}
	
	int ret = min(go(0,0), go(0,1));
	ret = min(ret, go(0,2));
	cout << ret;
}