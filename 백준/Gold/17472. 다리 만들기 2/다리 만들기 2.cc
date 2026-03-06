#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef tuple<int, int, int> tt;
int N, M, board[14][14], visited[14][14], cnt, ret, p[104], level[104];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector <pp> islands[104];
vector <tt> adj;

void dfs(int y, int x, int cnt){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i], nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if(visited[ny][nx]!=0 || board[ny][nx] != board[y][x]) continue;
		visited[ny][nx] = cnt;
		islands[cnt].push_back({ny, nx});
		dfs(ny, nx, cnt);
	}
}

int find(int x){
	if(p[x] == -1) return x;
	return p[x] = find(p[x]);
}

void merge(int y, int x){
	y = find(y), x = find(x);
	if(y==x) return;
	if(level[x] < level[y]){
		p[x] = y;
	}
	else{
		if(level[x]==level[y]) level[x]++;
		p[y] = x;
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(board[i][j]!=0 && visited[i][j]==0){
				cnt++;
				visited[i][j] = cnt;
				islands[cnt].push_back({i, j});
				dfs(i, j, cnt);
			}
		}
	}
	
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < M; j++){
//			cout << visited[i][j] << ' ';
//		}
//		cout << "\n";
//	}

	for(auto island : islands){
		for(auto is : island){
			int y, x;
			tie(y, x) = is;
			for(int i = 0; i < 4; i++){
				int dir = 1;
				int next = -1;
				while(1){
					int ny = y + dy[i]*dir;
					int nx = x + dx[i]*dir;
					if(ny < 0 || nx < 0 || ny >= N || nx >= M) break;
					if(visited[ny][nx]==visited[y][x]) break;
					if(visited[ny][nx]!=0) {
						next = visited[ny][nx];
						break;
					}
					
					
					dir++;
				}
				dir--;
				if(dir < 2 || next==-1) continue;
				adj.push_back(make_tuple(dir, visited[y][x], next));
			}
		}
	}
	
	sort(adj.begin(), adj.end());
	for(auto i : adj){
		int dir, idx1, idx2;
		tie(dir, idx1, idx2) = i;
		//cout << dir << " " << idx1 << " " << idx2 << '\n';
		idx1 = find(idx1), idx2 = find(idx2);
		if(idx1==idx2) continue;
		
		//cout << dir << "\n\n";
		ret += dir;
		merge(idx1, idx2);
	}
	
	int root = find(1);
	for(int i = 2; i <= cnt; i++){
		if(find(i)!=root){
			cout << "-1";
			return 0;
		}
	}
	
	cout << ret;
	
}