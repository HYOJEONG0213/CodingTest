#include <bits/stdc++.h>
using namespace std;

int N, M, sy, sx, d, board[54][54], visited[54][54], ret;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

bool search(int y, int x){
	bool flag = false;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i], nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if(board[ny][nx]==1 || visited[ny][nx]==1) continue;
		
		flag = true;
		break;
	}
	
	return flag;
}

bool check(int y, int x){
	if(y < 0 || x < 0 || y >= N || x >= M) return false;
	if(board[y][x]==1 || visited[y][x]==1) return false;
	
	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cin >> sy >> sx >> d;
	visited[sy][sx] = 1;
	ret++;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];
		}
	}
	
	
	while(1){
		if(!search(sy, sx)){
			int temp = (d+2)%4;
			int ny = sy + dy[temp], nx = sx + dx[temp];
			if(board[ny][nx]==1){
				break;
			}
			sy = ny, sx = nx;
		}
		else{
			while(1){
				d = (d+3)%4;
				int ny = sy + dy[d], nx = sx + dx[d];
				if(check(ny, nx)){
					ret++;
					sy = ny, sx = nx;
					visited[sy][sx] = 1;
					break;
				}
			}
		}
	}
	cout << ret;
}