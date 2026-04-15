#include <bits/stdc++.h>
using namespace std;

int N, K, board[14][14], dy[4] = {0,0,-1,1}, dx[4] = {1,-1,0,0};
vector <int> v[14][14]; 

struct {
	int y, x, dir;
}mal[14];


void move(int y, int x, int ny, int nx, vector <int> temp){
	for(int idx : temp){
		v[ny][nx].push_back(idx);
		mal[idx].y = ny;
		mal[idx].x = nx;
	}
	
}

bool check(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(v[i][j].size()>=4) return true;
		}
	}
	
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	
	for(int i = 0; i < K; i++){
		int y, x, dir;
		cin >> y >> x >> dir;
		y--; x--; dir--;
		mal[i].y = y;
		mal[i].x = x;
		mal[i].dir = dir;
		v[y][x].push_back(i);
	}
	
	int T = 1;
	while(T<=1000){
		for(int i = 0; i < K; i++){
			int y = mal[i].y;
			int x = mal[i].x;
			int dir = mal[i].dir;
			
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			//파란색 
			if(ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx]==2){
				mal[i].dir ^= 1;
				dir = mal[i].dir;
				ny = y + dy[dir];
				nx = x + dx[dir];
				if(ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx]==2) continue;
			}
			//흰색 
			if(board[ny][nx]==0){
				auto idx = find(v[y][x].begin(), v[y][x].end(), i);
				vector <int> temp(idx, v[y][x].end());
				v[y][x].erase(idx, v[y][x].end());
				move(y, x, ny, nx, temp);
			}
			//빨간색  
			if(board[ny][nx]==1){
				auto idx = find(v[y][x].begin(), v[y][x].end(), i);
				vector <int> temp(idx, v[y][x].end());
				reverse(temp.begin(), temp.end());
				v[y][x].erase(idx, v[y][x].end());
				move(y, x, ny, nx, temp);
			}
			
			if(check()){
				cout << T ;
				exit(0);
			}
		}
		
		T++;
	}
	
	cout << (T>1000 ? -1 : T);
}