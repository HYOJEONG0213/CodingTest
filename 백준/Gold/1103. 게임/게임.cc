#include <bits/stdc++.h>
using namespace std;

int N, M, board[54][54], dp[54][54], visited[54][54];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
string s;

int go(int y, int x){
	if(y < 0 || x < 0 || y >= N || x >= M || board[y][x]==-100) return 0;
	if(visited[y][x]) {
		cout << -1;
		exit(0);
	}
	int &ret = dp[y][x];
	if(ret != -1) return ret;
	
	visited[y][x] = 1;
	for(int i = 0 ; i < 4; i++){
		int ny = y + dy[i] * board[y][x];
		int nx = x + dx[i] * board[y][x];
		ret = max(ret, go(ny, nx)+1);
	}
	
	visited[y][x] = 0;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for(int i = 0 ; i < N ; i++){
		cin >> s;
		for(int j = 0 ; j < M; j++){
			if(s[j]=='H') board[i][j] = -100;
			else{
				board[i][j] = s[j] - '0';
			}
		}
	}
	
	cout <<	go(0, 0);
	
}