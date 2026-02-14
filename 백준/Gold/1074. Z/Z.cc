#include <bits/stdc++.h>
using namespace std;

int N, r, c, ret;

void go(int y, int x, int size){
	if(y == r && x == c){
		cout << ret;
		exit(0);
	}
	
	
	if(r >= y && r < y+size && c >= x && c < x+size){
		go(y, x, size/2);
		go(y, x + size/2, size/2);
		go(y + size/2, x, size/2);
		go(y + size/2, x + size/2, size/2);
	}
	else{
		ret += size*size;
	}
		
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> r >> c;
	go(0, 0, pow(2, N));
}