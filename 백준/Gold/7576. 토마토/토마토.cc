#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int M, N, board[1004][1004], visited[1004][1004], ret;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
queue <pp> q;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];
			if(board[i][j]==1) q.push({i,j});
		}
	}
	
	while(q.size()){
		auto f = q.front(); q.pop();
		int y = f.first, x = f.second;
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i], nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if(board[ny][nx]!=0) continue;
			board[ny][nx] = board[y][x]+1;
			q.push({ny,nx});
		}
		ret = max(board[y][x], ret)-1;
	}
	
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(board[i][j]==0){
				cout << -1;
				return 0;
			}
		}
	}
	cout << ret;
}