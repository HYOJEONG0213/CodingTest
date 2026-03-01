#include <bits/stdc++.h>
using namespace std;

int N;
char board[7000][7000];

void merge(int y, int x, int size){
	if(size==1){
		board[y][x] = '*';
		return;
	}
	
	int nextSize = size/3;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == 1 && j == 1) continue;
			
			merge(y+(i*nextSize), x+(j*nextSize), nextSize);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(&board[0][0], &board[0][0]+7000*7000, ' ');
	cin >> N;
	
	merge(0, 0, N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j];
		}
		cout << "\n";
	}
}