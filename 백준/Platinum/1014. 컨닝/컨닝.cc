#include <bits/stdc++.h>
using namespace std;

int T, N, M, c[150][150], f[150][150], ret, S = 120, E = 121, maxflow, p[150];
int dy[6] = {-1, 0, 1, -1, 0, 1}, dx[6] = {-1, -1, -1, 1, 1, 1};
string s;
char board[14][14];

vector <int> adj[150];

int getNum(int y, int x){
	return y*M + x;
}

void bfs(){
	while(1){
		memset(p, -1, sizeof(p));
		queue <int> q;
		q.push(S);
		
		while(q.size()){
			int here = q.front(); q.pop();
			for(int i : adj[here]){
				if(c[here][i] - f[here][i] > 0 && p[i] == -1){
					q.push(i);
					p[i] = here;
				}
			}
			if(p[E] != -1) break;
		}
		
		if(p[E]==-1) break;
		
		for(int here = E; here != S; here = p[here]){
			int pre = p[here];
			f[pre][here]++;
			f[here][pre]--;
		}
		maxflow++;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){	
		// 초기화 필요  
		ret = 0;
		maxflow = 0;
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		for(int i = 0; i < 150; i++){
			adj[i].clear();
		}
		
		cin >> N >> M;
		for(int i = 0; i < N; i++){
			cin >> s;
			for(int j = 0; j < M; j++){
				board[i][j] = s[j];
				if(board[i][j]=='.'){
					ret++;
					if(j % 2 == 0){
						adj[S].push_back(getNum(i, j));
						adj[getNum(i, j)].push_back(S);
						c[S][getNum(i, j)] = 1;
					}
					else{
						adj[getNum(i, j)].push_back(E);
						adj[E].push_back(getNum(i, j));
						c[getNum(i, j)][E] = 1;
					}	
					
				}
			}
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j+=2){
				if(board[i][j]=='x') continue;
				
				int here = getNum(i, j);
				for(int k = 0; k < 6; k++){
					int ny = i + dy[k], nx = j + dx[k];
					if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
					if(board[ny][nx]=='x') continue;
					
					// 짝수열에서 홀수열 가는거 만들기 
					int next = getNum(ny, nx);
					adj[here].push_back(next);
					adj[next].push_back(here);
					c[here][next] = 1; 
				}
			}
		}
		
		bfs();
		
		cout << ret - maxflow<< "\n";
	}
}