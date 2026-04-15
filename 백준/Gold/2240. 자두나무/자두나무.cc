#include <bits/stdc++.h>
using namespace std;
int T, W, a, A[1004], dp[2][1004][33];
//dp : 나무 인덱스 , 시간, 움직임 횟수

int go(int tree, int t, int move){
	if(t == T) return 0;
	if(move > W) return 0;
	
	int &ret = dp[tree][t][move];
	if(ret != -1) return ret;
	
	ret = max(go(tree^1, t+1, move+1), go(tree, t+1, move))+(tree == A[t]);		
	return ret;
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> T >> W ;
	for(int i = 0; i < T; i++){
		cin >> a;
		a--;
		A[i] = a;
	}
	
	cout << max(go(0, 0, 0), go(1, 0, 1));
}