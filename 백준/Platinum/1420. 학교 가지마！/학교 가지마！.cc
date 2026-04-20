#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M, dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, ret, S, E;
int p[20008], board[208][208], edgeidx[20008];
string s;

struct Edge{
	int to, capacity, flow, reverse;
};
vector <Edge> adj[20008];

void addEdge(int from, int to, int capacity){
	adj[from].push_back({to, capacity, 0, (int)adj[to].size()});
	adj[to].push_back({from, 0, 0, (int)adj[from].size()-1});
}

int getNum(int y, int x){
	return y*M+x;
}

void bfs(){
	while(1){
		memset(p, -1, sizeof(p));
		memset(edgeidx, -1, sizeof(edgeidx));
	 	queue <int> q;
		q.push(S);
		p[S] = S;
		
		while(q.size()){
			int here = q.front(); q.pop();
			for(int i = 0; i < adj[here].size(); i++){
				Edge &e = adj[here][i];
				if(e.capacity-e.flow>0 && p[e.to]==-1){
					p[e.to]=here;
					q.push(e.to);
					edgeidx[e.to] = i;	//방문시 선택한 인덱스 저장  
				}
				if(p[E]!=-1) break;
			}
			if(p[E]!=-1) break;
		}
		
		if(p[E]==-1) break;
		
		int minflow = INF;
		
		for(int here=E; here != S; here = p[here]){
			int pre = p[here];
			int idx = edgeidx[here];
			minflow = min(minflow, adj[pre][idx].capacity-adj[pre][idx].flow);
		}
		ret += minflow;
		
		for(int here=E; here != S; here = p[here]){
			int pre = p[here];
			int idx = edgeidx[here];
			int revidx = adj[pre][idx].reverse;
			
			adj[pre][idx].flow += minflow;
			adj[here][revidx].flow -= minflow;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < M; j++){
			//in : here*2, out : here*2+1
			board[i][j] = s[j];
			int here = getNum(i, j);
			if(board[i][j]=='K'){
				S = here*2+1;
			}
			else if(board[i][j]=='H'){
				E = here*2;
			}
			
			if(board[i][j]=='.'){
				// S -> . -> E
				addEdge(here*2, here*2+1, 1);
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(board[i][j]=='#') continue;
			
			int here = getNum(i, j);
			for(int k = 0; k < 4; k++){
					int ny = i + dy[k], nx = j + dx[k];
					if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
					if(board[ny][nx]=='#') continue;
					if(board[i][j] == 'K' && board[ny][nx]=='H'){
						cout << -1;
						return 0;
					}
					
					int next = getNum(ny ,nx);
					addEdge(here*2+1, next*2, INF);
			}
		}
	}
	
	
	bfs();
	
	cout << ret;
}