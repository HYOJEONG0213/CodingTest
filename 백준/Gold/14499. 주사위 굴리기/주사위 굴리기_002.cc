#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, K, screen[24][24], dir;
int dy[4] = {0,0,-1,1}, dx[4] = {1,-1,0,0};
int dice[7] = {0,0,0,0,0,0,0};
int roll_index[4][4] = {
	{1,3,6,4},
	{1,4,6,3},
	{1,2,6,5},
	{1,5,6,2}
};


void roll(int dir){
	int temp = dice[1];
	for(int i = 0 ; i < 3; i++) swap(dice[roll_index[dir][i]], dice[roll_index[dir][i+1]]);
	swap(dice[roll_index[dir][3]], temp);
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