#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, K, screen[24][24], dir;
int dy[4] = {0,0,-1,1}, dx[4] = {1,-1,0,0};
int dice[7] = {0,0,0,0,0,0,0};

void roll(int dir){
	// 동쪽 회전 
	if(dir == 0){
		int temp = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = dice[1];
		dice[1] = temp;
	}
	// 서쪽 회전 
	else if(dir == 1){
		int temp = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = temp;
	}
	// 북쪽 회전 
	else if(dir == 2){
		int temp = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = temp;
	}
	// 남쪽 회전  
	else if(dir == 3){
		int temp = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}
}


int main(){
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> y >> x >> K;

	for(int i = 0 ; i < N; i++){
		for(int j = 0 ;  j < M; j++){
			cin >> screen[i][j];
		}
	}
		
		
	for(int i = 0  ; i < K; i++) {
		cin >> dir; 
		dir--;
		
		int ny = y + dy[dir], nx = x+ dx[dir];
		if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		
		roll(dir); 
		
		if(screen[ny][nx]==0){
			screen[ny][nx] = dice[6];
		}
		else{
			dice[6] = screen[ny][nx];
			screen[ny][nx] = 0;
 		}
		cout << dice[1] << "\n";
		x = nx, y = ny;
	}

}