#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int N, M, board[1004][1004], visited[1004][1004];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int _size[1004*1004];
string s;

void dfs(int y, int x, int idx){
	queue <pp> q;
	q.push({y, x});
	visited[y][x] = idx;
	int count = 1;
	
	while(q.size()){
		int y, x;
		tie(y, x) = q.front(); q.pop();
			for(int i = 0; i < 4; i++){
			int ny = y + dy[i], nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if(visited[ny][nx]!=0 || board[ny][nx]==1) continue;
			visited[ny][nx] = idx;
			count++;
			q.push({ny, nx});
		}
	}
	_size[idx] = count;
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < M; j++){
			board[i][j] = s[j] - '0';
		}
	}
	int idx = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(board[i][j]==0 && visited[i][j]==0){
				visited[i][j] = idx;
				dfs(i, j, idx);
				idx++;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int ret = 0;
			if(board[i][j]==1){
				int adj[4] = {0};
				int adj_size = 0;
				
				for(int k = 0; k < 4; k++){
					int ny = i + dy[k], nx = j + dx[k];
					if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
					if(board[ny][nx]==1) continue;
					
					bool flag = false;
					for(int p = 0; p < adj_size; p++){
						if(adj[p]==visited[ny][nx]){
							flag = true;
							break;
						}
					}
					
					if(flag==false){
						adj[adj_size++] = visited[ny][nx];
						ret += _size[visited[ny][nx]];
					}
				}
				
				ret++;
			}
			cout << ret % 10;
		}
		cout << "\n";
	}
}