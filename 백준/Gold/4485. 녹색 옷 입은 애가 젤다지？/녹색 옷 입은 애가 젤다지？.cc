#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
typedef pair<int,int> pp;
int N, dist[130][130], board[130][130], dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T = 1;
	while(T){
		//초기화 필요 
		cin >> N;
		if(N == 0) return 0;
		
		fill(&dist[0][0], &dist[0][0]+130*130, INF);
		memset(board, 0, sizeof(board));
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> board[i][j];
			}
		}
		
		dist[0][0] = board[0][0];
		priority_queue <pp, vector <pp>, greater <pp>> pq;
		pq.push(make_pair(board[0][0], 0));
		
		while(pq.size()){
			int cost, temp;
			tie(cost, temp) = pq.top(); pq.pop();
			int y = temp / 1000;
			int x = temp % 1000;
			
			if(dist[y][x] != cost) continue;
			
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				int next = cost + board[ny][nx];
				if(dist[ny][nx] > next){
					dist[ny][nx] = next;
					pq.push(make_pair(next, ny*1000 + nx));
				}
			}
		}
		
		cout << "Problem " << T <<": "<< dist[N-1][N-1] << "\n";
		T++;
	}
	
}