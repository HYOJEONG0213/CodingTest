#include <bits/stdc++.h>
using namespace std;

//dp[현재 인덱스][길이] 
int n, A[10004], dp[10004];


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
	}
	
	dp[0] = 0;
	dp[1] = A[1];
	dp[2] = A[1]+A[2];
	for(int i = 3; i <= n; i++){
		//포함 안하는 경우, 2번째 전꺼 포함하는 경우 0 2
		dp[i] = max(dp[i-1], A[i]+dp[i-2]);
		//2번째 전꺼, 이전꺼, 지금꺼 선택하는 경우 0 2 3 
		dp[i] = max(dp[i], A[i] + A[i-1] + dp[i-3]);
	}
	
	cout << dp[n];
}