#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, dp[34][34];

ll go(int W, int H){
	if(W + H == 0) return 0;
	ll &ret = dp[W][H];                                                                         
	if(ret != -1) return ret;
	
	ret = 0;
	if(W > 0) ret += go(W-1, H+1);
	if(H > 0) ret += go(W, H-1);
	
	return ret;
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	dp[1][0] = 1;
	dp[0][2] = 1;
	while(1){
		cin >> a;
		if(a == 0) break;
		
		cout << go(a, 0) << "\n";
	}
}