#include <bits/stdc++.h>
using namespace std;

int N, L[24], J[24], dp[104];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0 ; i  < N; i++){
		cin >> L[i];
	}
	for(int i = 0 ; i  < N; i++){
		cin >> J[i];
	}
	for(int i = 0 ; i  < N; i++){
		for(int j = 99; j >= L[i]; j--){
			dp[j] = max(dp[j], dp[j-L[i]]+J[i]);
		}
	}
	
	cout << dp[99];
}