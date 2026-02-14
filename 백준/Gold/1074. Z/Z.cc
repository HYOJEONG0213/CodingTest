#include <bits/stdc++.h>
using namespace std;

int N, r, c, ret;
int dy[4] = {0,0,1,1}, dx[4] = {0,1,0,1};

void go(int sy, int ey, int sx, int ex){
	if(ey-sy == 1){
		for(int i = 0; i < 4; i++){
			int ny = sy + dy[i];
			int nx = sx + dx[i];
			if(ny == r && nx == c) {
				cout << ret;
				exit(0);
			}
			else ret++;
		}
		return;
	}
	
	int midy = (sy+ey)/2;
	int midx = (sx+ex)/2; 
	int cnt  = (midy-sy+1)*(midx-sx+1);
	
	
	if(sy <= r && r <= midy && sx <= c && c <= midx){
		go(sy, midy, sx, midx);
	}
	
	else if(sy <= r && r <= midy && midx+1 <= c && c <= ex){
		ret += cnt;
		go(sy, midy, midx+1, ex);
	}
		
	else if(midy+1 <= r && r <= ey && sx <= c && c <= midx){
		ret += cnt*2;
		go(midy+1, ey, sx, midx);
	}
		
	else if(midy+1 <= r && r <= ey && midx+1 <= c && c <= ex){
		ret += cnt*3;
		go(midy+1, ey, midx+1, ex);
	}
		
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> r >> c;
	go(0, pow(2, N)-1, 0, pow(2, N)-1);
}