#include <bits/stdc++.h>
using namespace std;

int R, C, board[1004][1004], mn = 1004, mnX, mnY;
string ret;

void avoid(){
	// 둘다 짝수라면 흰발판에서의 최솟값 제외하고 나아나가기
	// ㄹ 자 형태  
	for(int i = 0; i < (mnY/2)*2; i+=2){
		for(int j = 0; j < C-1; j++) ret += 'R';
		ret += 'D';
		for(int j = 0; j < C-1; j++) ret += 'L';
		ret += 'D';
	}
	
	// 위아래 형태  
	int here = 0;	// 0 : 위쪽행, 1 : 아래쪽 행  
	for(int j = 0; j < C; j++){
		if(j==mnX){
			if(j < C-1) ret += 'R';
		}
		else{
			if(here==0){
				ret += 'D';
				here = 1;
			}
			else{
				ret += 'U';
				here = 0;
			}
			
			if(j < C-1) ret += 'R';
		}
	}
	
	// _| 
	//|_ 자 형태  
	for(int i = (mnY/2)*2+2; i < R; i+=2){
		ret += 'D';
		for(int j = 0; j < C-1; j++) ret += 'L';
		ret += 'D';
		for(int j = 0; j < C-1; j++) ret += 'R';
	}
}

void normal(){
	if(R%2 == 1){
		for(int i = 0; i < R/2; i++){
			for(int j = 0; j < C-1; j++) ret += 'R';
			ret += 'D';
			for(int j = 0; j < C-1; j++) ret += 'L';
			ret += 'D';
		}
		for(int j = 0; j < C-1; j++) ret += 'R';
	} 
	else{
		for(int i = 0; i < C/2; i++){
			for(int j = 0; j < R-1; j++) ret += 'D';
			ret += 'R';
			for(int j = 0; j < R-1; j++) ret += 'U';
			ret += 'R';
		}
		for(int j = 0; j < R-1; j++) ret += 'D';
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> board[i][j];
			if(((i+j) % 2 == 1) && mn > board[i][j]){
				mn = board[i][j];
				mnY = i;
				mnX = j;
			}
		}
	}
	
	if(R%2==0 && C%2==0){
		avoid();
	}
	else{
		normal();
	}
	
	cout << ret;
}