#include <bits/stdc++.h>
using namespace std;

int n, c, M, P, dp[10004];
double m, p;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while(1){
		memset(dp, 0, sizeof(dp));
		cin >> n >> m;
		if(n == 0 && m == 0.00) return 0;
		
		M = (m*100.0f) + 0.0005f;
		
		for(int i = 0; i < n; i++){
			cin >> c >> p;
			P = (p*100.0f) + 0.0005f;
			
			for(int j = P; j <= M; j++){
				dp[j] = max(dp[j-P]+c, dp[j]); 
			}
		}
		
		cout << dp[M] << "\n";
	}
}