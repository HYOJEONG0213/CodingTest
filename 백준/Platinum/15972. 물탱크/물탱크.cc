#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int N, M, H, a, hole[1004][1004][4], board[1004][1004], ret;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
priority_queue <pp, vector<pp>, greater<pp>> pq;



void go(int height, int ny, int nx){
	if(board[ny][nx] > height){
		board[ny][nx] = height;
		pq.push({height, ny*1004+nx});
	}
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> H;
	
	//벽면을 위해 맨위 1칸, 맨왼쪽 1칸씩 이후로 시작하자! 
	for(int i = 1; i <= (N+1); i++){
		for(int j = 1; j <= M; j++){
			cin >> a;
			hole[i-1][j][2] = a;
			hole[i][j][0] = a; 
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= (M+1); j++){
			cin >> a;
			hole[i][j-1][1] = a;
			hole[i][j][3] = a; 
		}
	}
	
	//fill 쓰면 안됌! 
	//fill(&board[0][0], &board[0][0]+1004*1004, H);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			board[i][j] = H;
		}
	}
	
	
	//위 아래에서 물통 바라보기  
	for(int i = 0; i <= M+1; i++){
		if(hole[0][i][2] != -1) go(hole[0][i][2], 1, i);
		if(hole[N+1][i][0] != -1) go(hole[N+1][i][0], N, i);
	}
	//왼쪽 오른쪽  
	for(int i = 0; i <= N+1; i++){
		if(hole[i][0][1] != -1) go(hole[i][0][1], i, 1);
		if(hole[i][M+1][3] != -1) go(hole[i][M+1][3], i, M);
	}
	
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		int cost = f.first;
		int y = f.second / 1004;
		int x = f.second % 1004;
		if(board[y][x] != cost) continue;
		
		for(int i = 0; i < 4; i++){
			if(hole[y][x][i] == -1) continue;
			
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 1 || nx < 1 || ny > N || nx > M) continue;
			
			int next = min(hole[y][x][i], board[ny][nx]);
			next = max(board[y][x], next);
			if(board[ny][nx] > next){
				board[ny][nx] = next;
				pq.push({next, ny*1004+nx});
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			ret += board[i][j];
		}
	}
	
	cout << ret;
	
}