#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = pow(3, 12)+4;
char board[MAX];

void go(int s, int size){
	if(size==1){
		board[s] = '-';
		return;
	}
	
	int _size = size/3;
	go(s, _size);
	go(s + 2*_size, _size);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while(cin >> N){
		int size = pow(3, N);
		memset(board, ' ', size);
		board[size] = '\0';
		go(0, size);
		
		cout << board << "\n";
	}
}