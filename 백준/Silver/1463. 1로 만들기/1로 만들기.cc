#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int N, dp[1000004];

int go(int n){
	if(n == 1) return 0;
	
	int &ret = dp[n];
	if(ret != -1) return ret;
	
	ret = INF;
	if(n % 2 == 0) ret = min(ret, go(n/2)+1);
	if(n % 3 == 0) ret = min(ret, go(n/3)+1);
	ret = min(ret, go(n-1)+1);
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << go(N);
}