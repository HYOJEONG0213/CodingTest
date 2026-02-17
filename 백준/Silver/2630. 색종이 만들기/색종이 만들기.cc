#include <bits/stdc++.h>
using namespace std;

int N, board[130][130], ret[2];

void go(int y, int x, int _size){
	int temp = board[y][x];
	for(int i = y; i < y+_size; i++){
		for(int j = x; j < x+_size; j++){
			if(board[i][j] != temp){
				go(y, x, _size/2);
				go(y, x+_size/2, _size/2);
				go(y+_size/2, x, _size/2);
				go(y+_size/2, x+_size/2, _size/2);
				return;
			}
		}
	}
	
	// 다 같은 색인가 보네!
	ret[temp]++; 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	
	go(0, 0, N);
	cout << ret[0] << "\n";
	cout << ret[1] ;
}