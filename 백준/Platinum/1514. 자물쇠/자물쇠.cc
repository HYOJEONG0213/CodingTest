#include <bits/stdc++.h>
using namespace std;

int N;
string state, password;
int dp[104][10][10][10][2];

int ro(int a, int cnt, int flag){
	if(flag == 1){
		return (a+10 - cnt) % 10;
	}
	else{
		return (a+cnt) % 10;
	}
}

int go(int idx, int a, int b, int c, int dir){
	if(idx >= N) return 0;
	int &ret = dp[idx][a][b][c][dir];
	if(ret != -1) return ret;

	if(a == password[idx] - '0') {
		return ret = min(go(idx+1, b, c, state[idx+3]-'0', 0), 
					go(idx+1, b, c, state[idx+3]-'0', 1));
	}
		
	ret = 987654321;
	for(int i = 1; i <= 3; i++){
		//1개만 돌리기
		ret = min(ret, go(idx, ro(a, i, dir), b, c, dir)+1);
		//2개 돌리기 
		ret = min(ret, go(idx, ro(a, i, dir), ro(b, i, dir), c, dir)+1);
		//3개 돌리기
		ret = min(ret, go(idx, ro(a, i, dir), ro(b, i, dir), ro(c, i, dir), dir)+1);
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> state >> password;
	
	
	state += "0000";
	cout << min(go(0, state[0] - '0', state[1] - '0', state[2] - '0', 1),
		go(0, state[0] - '0', state[1] - '0', state[2] - '0', 0));

}