#include <bits/stdc++.h>
using namespace std;

int N, a, dp[504][504], ret;
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	cin >> a;
	dp[0][0] = a;
	ret = a;
	for(int i = 1; i < N; i++){
		for(int j = 0; j < i+1; j++){
			cin >> a;
			if(j-1 >= 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+a);
			}
			
			dp[i][j] = max(dp[i][j], dp[i-1][j]+a);
			ret = max(dp[i][j], ret);
		}
	}
	
	cout << ret;
}