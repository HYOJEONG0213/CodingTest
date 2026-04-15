#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
string s;
int dp[2504][2504], dp2[2504];

int go(int here){
	if(here >= s.size()) return 0;
	int &ret = dp2[here];
	if(ret != INF) return ret;
	
	for(int i = 1; here + i <= s.size(); i++){
		if(dp[here][i]){
			ret = min(ret, go(here + i) + 1);
		}
	}
	
	return ret;
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(dp2, dp2+2504, INF);
	cin >> s;
	for(int i = 0 ; i < s.size(); i++){
		dp[i][1] = 1;
	}
	for(int i = 0;  i < s.size()-1; i++){
		if(s[i]==s[i+1])
			dp[i][2] = 1;
	}
	for(int inter = 3; inter <= s.size(); inter++){
		for(int i = 0; i + inter <= s.size(); i++){
			if(s[i]==s[i + inter-1] && dp[i+1][inter-2]){
				dp[i][inter] = 1;
			}
		}
	}
	
//	for(int i = 0; i < s.size(); i++){
//		for(int j = 0; j < s.size(); j++){
//			if(dp[i][j]){
//				cout << i << " " << j << "\n";
//			}
//		}
//	}
	
	cout << go(0);
}