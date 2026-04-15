#include <bits/stdc++.h>
using namespace std;

int dp[100], M;
string s = "Messi Gimossi";

void fibo(){
	dp[1] = 5;
	dp[2] = 13;
	for(int i = 3; i <= 40; i++){
		dp[i] = dp[i-1] + dp[i-2] + 1;
	}
	
	//cout << dp[40] << "\n";
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fibo();
	cin >> M;
	M--;
	
	for(int i = 40; i >= 2; i--){
		if(M >= dp[i]){
			M -= dp[i] + 1;
		}
	}
	if(M == 5 || M == -1) cout << "Messi Messi Gimossi";
	else cout << s[M];
	
}