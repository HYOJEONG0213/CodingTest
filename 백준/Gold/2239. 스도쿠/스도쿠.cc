#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
string s;
int board[12][12], row[12][12], col[12][12], squre[12][12];

int getCnt(int y, int x){
	return 3*(y/3) + x/3;
}

void print(int (*board)[12]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << board[i][j];
		}
		cout << "\n";
	}
}

void go(int idx){
	if(idx >= 81) {
		print(board);
		exit(0);
	}
	
	int y = idx / 9;
	int x = idx % 9;
	if(board[y][x]!=0) return go(idx+1);
	
	for(int i = 1; i <= 9; i++){
		if(row[y][i]==0 && col[x][i]==0 && squre[getCnt(y,x)][i]==0){
			row[y][i]=1;
			col[x][i]=1;
			squre[getCnt(y,x)][i]=1;
			board[y][x]=i;
			go(idx+1);
			
			row[y][i]=0;
			col[x][i]=0;
			squre[getCnt(y,x)][i]=0;
			board[y][x]=0;
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 0; i < 9; i++){
		cin >> s;
		for(int j = 0; j < 9; j++){
			board[i][j] = s[j] - '0';
			if(board[i][j] == 0) continue;
			row[i][board[i][j]] = 1;
			col[j][board[i][j]] = 1;
			squre[getCnt(i, j)][board[i][j]] = 1;
		}
	}
	
	
//	for(int i = 0; i < 9; i++){
//		for(int j = 1; j <= 9; j++){
//			cout << col[i][j] << " ";
//		}
//		cout << "\n";
//	}

	go(0);
}