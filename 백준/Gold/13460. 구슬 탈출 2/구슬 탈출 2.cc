#include <bits/stdc++.h>
using namespace std;

int N, M, ey, ex, Ry, Rx, By, Bx;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int visited[14][14][14][14];
string s;
char board[14][14];

struct Node{
	int Ry, Rx;
	int By, Bx;
};

Node node;
typedef pair<Node, int> pp;
queue <pp> q;

void move(int &y, int &x, int &cnt, int dir){
	int ny = y + dy[dir], nx = x + dx[dir];
	for(int i = 0; i <= max(N, M); i++){
		if(board[ny][nx] == '#' || board[y][x] == 'O') return;
		
		y += dy[dir];
		x += dx[dir];
		ny = y + dy[dir], nx = x + dx[dir];
		cnt++;
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < M; j++){
			board[i][j] = s[j];
			if(board[i][j]=='R'){
				node.Ry = i, node.Rx = j;
				board[i][j] = '.';
			}
			else if(board[i][j]=='B'){
				node.By = i, node.Bx = j;
				board[i][j] = '.';
			}
		}
	}
	visited[node.Ry][node.Rx][node.By][node.Bx] = 1;
	
	q.push({node, 0});
	while(q.size()){
		auto f = q.front(); q.pop();
		Node tempNode = f.first;
		int idx = f.second;
		
		if(idx >= 10){
			continue;
		}
		
		for(int i = 0; i < 4; i++){
			int nRy = tempNode.Ry;
			int nRx = tempNode.Rx;
			int nBy = tempNode.By;
			int nBx = tempNode.Bx;
			int cntR = 0, cntB = 0;
			
			move(nRy, nRx, cntR, i);
			move(nBy, nBx, cntB, i);
			
			if(board[nBy][nBx]=='O') continue;
			if(board[nRy][nRx]=='O'){
				cout << idx+1;
				return 0;
			}
			
			if(nRy == nBy && nRx == nBx){
				if(cntR < cntB){
					nBy -= dy[i];
					nBx -= dx[i];
				}
				else{
					nRy -= dy[i];
					nRx -= dx[i];
				}
			}
			
			if(visited[nRy][nRx][nBy][nBx]) continue;
			visited[nRy][nRx][nBy][nBx] = 1;
			
			node.Ry = nRy;
			node.Rx = nRx;
			node.By = nBy;
			node.Bx = nBx;
			q.push({node, idx+1});
		}
		
	}
	
	cout << -1;
}