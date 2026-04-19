#include <bits/stdc++.h>
using namespace std;

int T, N, M, visited[150], assigned[104], ret;
int dy[6] = {-1, 0, 1, -1, 0, 1}, dx[6] = {-1, -1, -1, 1, 1, 1};
string s;
char board[14][14];

vector <int> L, R[150];

int getNum(int y, int x){
	return y*M + x;
}

bool dfs(int idx){
	// idx: L 노드 , i : R노드  
	for(int i : R[idx]){
		if(visited[i]) continue;
		visited[i] = 1;
		if(assigned[i]==-1 || dfs(assigned[i])){
			assigned[i] = idx;
			return true;
		}
	}
	
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){	
		// 초기화 필요  
		memset(assigned, -1, sizeof(assigned));
		L.clear();
		ret = 0;
		for(int i = 0; i < 150; i++){
			R[i].clear();
		}
		
		cin >> N >> M;
		for(int i = 0; i < N; i++){
			cin >> s;
			for(int j = 0; j < M; j++){
				board[i][j] = s[j];
				if(board[i][j]=='.'){
					if(j % 2 == 0)
						L.push_back(getNum(i, j));
					ret++;
				}
			}
		}
		
		for(int i : L){
			int y, x;
			y = i/M; x = i%M;
			for(int j = 0; j < 6; j++){
				int ny = y + dy[j], nx = x + dx[j];
				if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if(board[ny][nx]=='x') continue;
				R[i].push_back(getNum(ny, nx));
			}
		}
		
		for(int i : L){
			memset(visited, 0, sizeof(visited));
			if(dfs(i)){
				ret--;
			} 
		}
		
		cout << ret << "\n";
	}
}