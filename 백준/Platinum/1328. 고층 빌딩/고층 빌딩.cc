#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
ll N, L, R, dp[104][104][104];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R;
	
	//dp[건물개수][왼쪽보이는수][오른쪽보이는수] 
	dp[1][1][1] = 1;
	
	for(int i = 2; i <= N; i++){
		for(int j = 1; j <= L; j++){
			for(int k = 1; k <= R; k++){
				dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k] * (i-2);
				dp[i][j][k] %= MOD;
			}
		}
	}
	
	cout << dp[N][L][R] ;
}