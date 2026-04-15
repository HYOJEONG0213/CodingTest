#include <bits/stdc++.h>
using namespace std;

int board[14][14], paper[10], ret = 987654321;

//해당 색종이 붙일 수 있는가 
int check(int y, int x, int cnt){
	//여기서 부등호를 >= 라고 하면 안되넹;;
	//(0,5)번째에서 5개짜리 색종이 붙이면 (0,10)까지 붙여짐 ㅎㅎ; 
	if(y + cnt > 10 || x + cnt > 10) return 0;
	
	for(int i = 0; i < cnt; i++){
		for(int j = 0 ;  j< cnt; j++){
			int ny = y + i, nx = x + j;
			if(board[ny][nx]==0) return 0;
		}
	}
	
	return 1;
}

//해당 색종이 붙였다 떼기  
void draw(int y, int x, int _size, int cnt){
	for(int i = 0; i < _size; i++){
		for(int j = 0 ;  j< _size; j++){
			int ny = y + i, nx = x + j;
			board[ny][nx] = cnt;
		}
	}
}

//cnt : 몇번 색종이 사용?  
void go(int y, int x, int cnt){
	//백트래킹 : 가지치기 
	if(ret <= cnt) return ;
	//기저사례  
	if(x == 10){
		go(y+1, 0, cnt);
		return;
	}
	if(y == 10){
		ret = min(ret, cnt);
		return;
	}
	if(board[y][x] == 0){
		go(y, x+1, cnt);
		return;
	}
	
	for(int i = 5; i > 0; i--){
		if(paper[i] == 5) continue;
		
		//해당 크기의 색종이를 붙일 수 있다면
		//붙였다 뗐다 원복 필요   
		if(check(y, x, i) == 1){
			draw(y, x, i, 0);
			paper[i]++;
			go(y, x+i, cnt+1);
			draw(y, x, i, 1);
			paper[i]--;
		}
	} 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 0; i < 10; i++){
		for(int j = 0 ; j < 10 ; j++){
			cin >> board[i][j];
		}
	}
	
	go(0, 0, 0);
	
	cout << (ret==987654321 ? -1 : ret);
}