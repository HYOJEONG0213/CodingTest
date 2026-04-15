#include <bits/stdc++.h>
using namespace std;
int N, M, S, E, dp[2004][2004], A[2004];

void setDp(){
	for(int i = 0; i < 2000; i++) {
		dp[i][i] = 1;
	}
	for(int i = 0; i < 2000; i++) {
		if(A[i]==A[i+1])
			dp[i][i+1] = 1;
	}
	
	for(int inter = 2; inter < 2000; inter++){
		for(int i = 0; i < 2000; i++){
			if(dp[i+1][i+inter-1] == 1 && A[i]==A[i+inter]){
				dp[i][i+inter] = 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	setDp();
	
	cin >> M;
	while(M--){
		cin >> S >> E;
		S--; E--;
		
		cout << dp[S][E] << "\n";
	}
}