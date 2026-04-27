#include <bits/stdc++.h>
using namespace std;

int n, board[20][20], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int ret = 987654321;

void operate(int y, int x, int b[20][20]){
	b[y][x] ^= 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i], nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		b[ny][nx] ^= 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	
	for(int i = 0; i < (1<<n); i++){
		int temp[20][20];
		int cnt = 0;
		memcpy(temp, board, sizeof(board));
		// 맨 윗줄 (j : x)  
		for(int j = 0; j < n; j++){
			if(i & (1<<j)){
				operate(0, j, temp);
				cnt++;
			}
		}
		
		// 몸통 (j : y)  
		for(int j = 1; j < n; j++){
			for(int k = 0; k < n; k++){
				if(temp[j-1][k]==1){
					operate(j, k, temp);
					cnt++;
				}
			}
		}
		
		// 전체 1 확인
		bool flag = true;  
		for(int j = 0; j < n; j++){
			if(temp[n-1][j]==1){
				flag = false; 
				break;
			}
		}
		if(flag == false) continue;
		ret = min(ret, cnt);
	}
	cout << (ret==987654321? -1 : ret);
}