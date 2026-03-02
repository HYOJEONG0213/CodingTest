#include <bits/stdc++.h>
using namespace std;

int N, board[4000][4000], ret[3];

void go(int y, int x, int _size){
	if(_size==1){
		ret[board[y][x]+1]++;
		return;
	}
	
	int temp = board[y][x];
	int inter = _size/3;
	bool flag = false;
	for(int i = 0; i < _size; i++){
		for(int j = 0; j < _size; j++){
			if(board[y+i][x+j] != temp){
				flag = true;
				break;
			}
		}
		if(flag == true) break;
	}
	
	if(flag == true){
		go(y, x, inter);
		go(y, x+inter, inter);
		go(y, x+2*inter, inter);
		go(y+inter, x, inter);
		go(y+inter, x+inter, inter);
		go(y+inter, x+2*inter, inter);
		go(y+inter*2, x, inter);
		go(y+inter*2, x+inter, inter);
		go(y+inter*2, x+2*inter, inter);
		return;
	}
	
	ret[temp+1]++;
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