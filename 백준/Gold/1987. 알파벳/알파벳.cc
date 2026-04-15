#include <bits/stdc++.h>
using namespace std;

int R, C, a[24][24], ret;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
string s;

void dfs(int y, int x, int num, int cnt){
	ret = max(ret, cnt);
	
	for(int i = 0; i < 4; i++){
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		
		if(num & (a[ny][nx])) continue;
		
		
		dfs(ny, nx, num | a[ny][nx], cnt+1);
	}
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for(int i = 0; i < R; i++){
		cin >> s;
		for(int j = 0; j < C; j++){
			a[i][j] =  1 << (int)(s[j] - 'A');
			//cout << a[i][j] << " ";
		}
		//cout << "\n";
	}
	
	dfs(0, 0, a[0][0], 1);
	
	cout << ret;
}