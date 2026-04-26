#include <bits/stdc++.h>
using namespace std;

string s;
const int INF = 987654321;
int board[14][14], ret=INF;

int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void toggle(int y, int x, int temp[][14]){
	temp[y][x] ^=1;
	for(int d = 0; d < 4; d++){
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || nx < 0 || ny >= 10 || nx >= 10) continue;
		temp[ny][nx] ^=1;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 0; i < 10; i++){
		cin >> s;
		for(int j = 0; j < 10; j++){
			if(s[j]=='O')
				board[i][j] = 1;
			else
				board[i][j] = 0;
		}
	}
	
	for(int i = 0; i < (1<<10); i++){
		int temp[14][14];
		memcpy(temp, board, sizeof(board));
		int cnt = 0;
		
		// 첫째줄만 스위치 온오프  
		for(int j = 0; j < 10; j++){
			if(i&(1<<j)){
				toggle(0, j, temp);
				cnt++;
			}
		}
		
		// 2~10번째 줄 스위치 온오프
		for(int j = 1; j < 10; j++){
			for(int k = 0; k < 10; k++){
				if(temp[j-1][k]==1){
					toggle(j, k, temp);
					cnt++;
				}
			}
		} 
		
		bool flag = true;
		
		for(int j = 0; j < 10; j++){
			if(temp[9][j]==1){
				flag = false;
				break;
			}
			if(flag == false) break;
		}
		
		if(flag==false) continue;
		ret = min(ret, cnt);
	}
	
	cout << (ret==INF ? -1 : ret);
}