#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
typedef pair<int,int> pp;
int n, m, board[1004][1004], ret[1004][1004], ey, ex;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void bfs(){
	queue <pp> q;
	q.push({ey, ex});
	ret[ey][ex] = 0;
	
	while(q.size()){
		auto f = q.front(); q.pop();
		int y = f.first; int x = f.second;
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i]; 
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(ny==ey && nx==ex) continue;
			if(board[ny][nx]==0 || ret[ny][nx]!=-1) continue;
			
			ret[ny][nx] = ret[y][x]+1;
			q.push({ny, nx});
			
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(ret, -1, sizeof(ret));
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
			if(board[i][j]==2){
				ey = i; ex = j;
			}
		}
	}
	
	
	bfs();
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j]==0) cout << 0 << " ";
			else cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
}