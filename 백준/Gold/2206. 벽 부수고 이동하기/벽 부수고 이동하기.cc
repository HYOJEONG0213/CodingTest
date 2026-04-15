#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
const int INF = 987654321;
int N, M, visited[1004][1004][2], board[1004][1004], ret = INF;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
string s;
vector <pp> list1;

void bfs(){
	queue <tuple<int,int,int>> q;
	q.push(make_tuple(0, 0, 0));
	visited[0][0][0] = 1;
	while(q.size()){
		auto f = q.front(); q.pop();
		int y, x, broken;
		tie(y, x, broken) = f;
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i], nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if(visited[ny][nx][broken]!=0) continue;
			
			if(ny == N-1 && nx == M-1){
				cout << visited[y][x][broken]+1;
				exit(0);
			}
			
			if(board[ny][nx]==0){
				visited[ny][nx][broken] = visited[y][x][broken]+1;
				q.push(make_tuple(ny, nx, broken));
			}
			else{
				if(broken==1) continue;
				visited[ny][nx][1] = visited[y][x][0]+1;
				q.push(make_tuple(ny, nx, 1));
			}
			
			
		}
	}
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
	
	if(N-1==0 && M-1 == 0){
		cout << 1;
		return 0;
	}
	bfs();
	
	cout << -1;
}