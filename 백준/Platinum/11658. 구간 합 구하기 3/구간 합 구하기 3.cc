#include <bits/stdc++.h>
using namespace std;
#define y1 yyyyy

int N, M, board[1030][1030], w, c, tree[1030][1030];


void update(int y, int x, int num){
	int yidx = y;
	while(yidx <= N){
		int xidx = x;
		while(xidx <= N){
			tree[yidx][xidx] += num;
			xidx += xidx & -xidx;
		}
		yidx += yidx & -yidx;
	}
}

int _sum(int y, int x){
	int ret = 0;
	int yidx = y;
	while(yidx > 0){
		int xidx = x;
		while(xidx > 0){
			ret += tree[yidx][xidx];
			xidx -= xidx & -xidx;
		}
		yidx -= yidx & -yidx;
	}
	
	return ret;
}

int sum(int y1, int x1, int y2, int x2){
	return _sum(y2, x2) - _sum(y1-1, x2) - _sum(y2, x1-1) + _sum(y1-1, x1-1);
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, y, x1, x2, y1, y2;
	
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> board[i][j];
			update(i, j, board[i][j]);
		}
	}
	
	for(int i = 0; i < M; i++){
		cin >> w;
		if(w == 0){
			cin >> y >> x >> c;
			int num = c - board[y][x];
			update(y, x, num);
			board[y][x] = c;
		}
		else{
			cin >> y1 >> x1 >> y2 >> x2;
			cout << sum(y1, x1, y2, x2) << "\n";
		}
	}
}