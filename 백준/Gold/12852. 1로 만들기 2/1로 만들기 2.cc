#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1000004];
const int INF = 987654321;

void go(int here){
	if(here == 0) return;
	cout << here << " ";
	if(here%3 == 0 && dp[here/3]+1 == dp[here])
		go(here/3);
	else if(here%2 == 0 && dp[here/2]+1 == dp[here])
		go(here/2);
	else if(dp[here-1]+1 == dp[here])
		go(here-1);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(dp, dp+1000004, INF);
	dp[1] = 0;
	cin >> N;
	
	for(int i = 2; i <= N; i++){
		if((i%3)==0) dp[i] = min(dp[i], dp[i/3] + 1);
		if((i%2)==0) dp[i] = min(dp[i], dp[i/2] + 1);
		dp[i] = min(dp[i-1]+1, dp[i]);
	}
	
	cout << dp[N]<<"\n";
	go(N);
}