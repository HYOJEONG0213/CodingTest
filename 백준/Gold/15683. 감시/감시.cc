#include <bits/stdc++.h>
using namespace std;
struct {
	int y, x;
	vector <int> dir;
} CCTV[10];
int N, M, ret =987654321, board[10][10], cctvCnt;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void show(int Board[10][10]){
	cout << "\n";
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << Board[i][j] << " ";
		}
		cout <<"\n";
	}
	cout <<"\n";
}

void check(int Board[10][10]){
	int num = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(Board[i][j]==0){
				num++;
			}
		}
	}
	
	//show(Board);
	ret = min(num, ret);
}

void go(int Board[10][10], int idx){
	if(idx == cctvCnt){
		check(Board);
		return;
	}
	
	int tempBoard[10][10];
	memcpy(tempBoard, Board, sizeof(tempBoard));
	
	int y = CCTV[idx].y;
	int x = CCTV[idx].x;
	vector <int> dir = CCTV[idx].dir;
	
	for(int j = 0; j < 4; j++){
		for(int i : dir){
			int cnt = 0;
			while(1){
				int ny = y + dy[i] * cnt;
				int nx = x + dx[i] * cnt;
				if(ny < 0 || nx < 0 || ny >= N || nx >= M || board[ny][nx]==6){
					break;
				}
				
				tempBoard[ny][nx] = 8;
				cnt++;
			}
		}
		
		go(tempBoard, idx+1);
		memcpy(tempBoard, Board, sizeof(tempBoard));
		
		if(dir.size()==4) break;
		if(dir.size()==2 && j==1 && abs(dir[0] - dir[1])==2) break;
		
		for(int i = 0; i < dir.size(); i++){
			dir[i] = (dir[i] + 1) % 4;
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];
			if(board[i][j]==1){
				CCTV[cctvCnt].y = i;
				CCTV[cctvCnt].x = j;
				CCTV[cctvCnt].dir.push_back(1);
				cctvCnt++;
			}
			else if(board[i][j]==2){
				CCTV[cctvCnt].y = i;
				CCTV[cctvCnt].x = j;
				CCTV[cctvCnt].dir.push_back(1);
				CCTV[cctvCnt].dir.push_back(3);
				cctvCnt++;
			}
			else if(board[i][j]==3){
				CCTV[cctvCnt].y = i;
				CCTV[cctvCnt].x = j;
				CCTV[cctvCnt].dir.push_back(0);
				CCTV[cctvCnt].dir.push_back(1);
				cctvCnt++;
			}
			else if(board[i][j]==4){
				CCTV[cctvCnt].y = i;
				CCTV[cctvCnt].x = j;
				CCTV[cctvCnt].dir.push_back(0);
				CCTV[cctvCnt].dir.push_back(1);
				CCTV[cctvCnt].dir.push_back(3);
				cctvCnt++;
			}
			else if(board[i][j]==5){
				CCTV[cctvCnt].y = i;
				CCTV[cctvCnt].x = j;
				CCTV[cctvCnt].dir.push_back(0);
				CCTV[cctvCnt].dir.push_back(1);
				CCTV[cctvCnt].dir.push_back(2);
				CCTV[cctvCnt].dir.push_back(3);
				cctvCnt++;
			}
			
		}
	}
	
	go(board, 0);
	
	cout << ret;
}