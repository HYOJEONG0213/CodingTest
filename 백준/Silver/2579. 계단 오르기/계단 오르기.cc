#include <bits/stdc++.h>
using namespace std;

int N, A[304], dp[304];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	
	dp[1] = A[1];
	dp[2] = A[1] + A[2];
	dp[3] = max(A[1] + A[3] , A[2] + A[3]);
	
	for(int i = 4; i <= N; i++){
		dp[i] = max(dp[i-2]+A[i] , dp[i-3]+A[i-1]+A[i]);
	}
	
	cout << dp[N];
}