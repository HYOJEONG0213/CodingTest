#include <bits/stdc++.h>
using namespace std;

int N, M, board[1004][1004], visited[1004][1004], ret;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
string s;
map <char, int> mp = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

void dfs(int y, int x){
	visited[y][x] = 1;
	
	int ny = y + dy[board[y][x]];
	int nx = x + dx[board[y][x]];
	if(visited[ny][nx]==0) {
		dfs(ny, nx);
	}
	else if(visited[ny][nx]==1){
		ret++;
	}
	
	visited[y][x] = 2;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < M; j++){
			board[i][j] = mp[s[j]];
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(visited[i][j]==0) {
				dfs(i, j);
			}
			
			dfs(i, j);
		}
	}
	
	cout << ret;
}