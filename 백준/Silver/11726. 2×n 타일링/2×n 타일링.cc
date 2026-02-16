#include <bits/stdc++.h>
using namespace std;

int n, ret, dp[1004];

int go(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	
	return ret = (go(n-1) + go(n-2)) % 10007;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	cin >> n;
	cout << go(n);
}