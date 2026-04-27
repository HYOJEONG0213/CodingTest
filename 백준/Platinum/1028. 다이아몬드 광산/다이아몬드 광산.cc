#include <bits/stdc++.h>
using namespace std;

int R, C, board[754][754], LD[754][754], RD[754][754], ret;
string s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for(int i = 0; i < R; i++){
		cin >> s;
		for(int j = 0; j < C; j++){
			board[i][j] = s[j]-'0'; 
		}
	}
	
	// 누적 
	for(int i = R-1; i >= 0; i--){
		for(int j = 0; j < C; j++){
			if(board[i][j]==0) continue;
			
			// 왼쪽 아래 확인  
			LD[i][j] = (i+1 < R && j-1 >= 0) ? LD[i+1][j-1]+1 : 1;
			// 오른쪽 아래 확인  
			RD[i][j] = (i+1 < R && j+1 < C) ? RD[i+1][j+1]+1 : 1; 
		}
	}
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(board[i][j]==0) continue;
			
			int mn = min(LD[i][j], RD[i][j]);
			// 왼쪽아래에선 RD, 오른쪽아래에선 LD 검사  
			for (int k = mn; k > ret; k--){
				int leftR = i + k-1;
				int leftC = j - k+1;
				int rightR = i + k-1;
				int rightC = j + k-1;
				
				if(RD[leftR][leftC] >= k && LD[rightR][rightC] >= k){
					ret = max(ret, k);
					break;
				}
			}
		}
	}
	
	cout << ret;
}