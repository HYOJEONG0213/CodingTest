#include <bits/stdc++.h>
using namespace std;
int N, board[18][18], dp[18][18][3];

int go(int y, int x, int dir){
	if(y == N-1 && x == N-1) return 1;
	if(y >= N || x >= N) return 0;
	
	int &ret = dp[y][x][dir];
	if(ret != -1) return ret;
	
	ret = 0;
	//가로로 
	if(dir != 1 && board[y][x+1] == 0){
		ret += go(y, x+1, 0);
	}
	//세로로 
	if(dir != 0 && board[y+1][x] == 0){
		ret += go(y+1, x, 1);
	}
	//대각선으로 
	if(board[y+1][x] == 0 && board[y][x+1] == 0 && board[y+1][x+1] ==0)
		ret += go(y+1, x+1, 2);
	
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	
	cout << go(0, 1, 0);
}