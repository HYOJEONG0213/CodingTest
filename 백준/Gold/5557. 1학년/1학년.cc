#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, dp[104][24], A[104];

ll go(ll idx, ll sum){
	if(idx == N-2){
		if(sum == A[N-1]) return 1;
		else return 0;
	}
	if(sum < 0 || sum > 20) return 0;
	
	ll &ret = dp[idx][sum];
	if(ret != -1) return ret;
	
	ret = 0;
	ret += go(idx+1, sum+A[idx+1]);
	ret += go(idx+1, sum-A[idx+1]);
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> A[i];
	}
	
	cout << go(0, A[0]);
}