#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int MAXTIME = 72500;
// dp[a의 시간] = b의 최소 시간  
vector <int> dp(MAXTIME+4, INF);
int n, a, b;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[0] = 0;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		
		vector <int> temp(MAXTIME+4, INF);
		for(int j = 0; j <= MAXTIME; j++){
			if(dp[j]==INF) continue;
			
			// a 에 할당 
			if(j+a <= MAXTIME) 	
				temp[j+a] = min(temp[j+a], dp[j]);
			// b에 할당 
			temp[j] = min(temp[j], dp[j]+b);
		}
		dp = temp;
	}
	
	int ret = INF;
	for(int j = 0; j <= MAXTIME; j++){
		ret = min(ret, max(j, dp[j]));
	}
	cout << ret;
	
}