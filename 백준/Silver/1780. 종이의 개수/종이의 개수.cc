#include <bits/stdc++.h>
using namespace std;

int N, board[2200][2200], ret[3];

bool check(int y, int x, int _size){
	int temp = board[y][x];
	
	for(int i = y; i < y+_size; i++){
		for(int j = x; j < x+_size; j++){
			if(board[i][j] != temp){
				return false;
			}
		}
	}
	
	return true;
}

void go(int y, int x, int _size){
	if(_size==1){
		ret[board[y][x]+1]++;
		return;
	}
	
	if(check(y, x, _size)==true){
		ret[board[y][x]+1]++;
		return;
	}
	
	int inter = _size/3;	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			go(y + i * inter, x + j * inter, inter);
		}
	}
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
	for(int i = 0; i < 3; i++){
		cout << ret[i] << "\n";
	}
}