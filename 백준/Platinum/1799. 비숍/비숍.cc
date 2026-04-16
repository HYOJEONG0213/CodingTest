#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int N, board[14][14], visited1[30], visited2[30];
int ret[2];
vector<pp> pos[2];

void dfs(int idx, int cnt, int color){
	if(idx == pos[color].size()){
		ret[color] = max(ret[color], cnt);
		return;
	}
	
	int y, x;
	tie(y, x) = pos[color][idx];
	
	// y-x + N 한 이유: 배열 마이너스 되면 안돼.. 
	if(visited1[y+x]==0 && visited2[y-x + N]==0){
		visited1[y+x] = visited2[y-x+N] = 1;
		dfs(idx+1, cnt+1, color);
		visited1[y+x] = visited2[y-x+N] = 0;
	}
	
	dfs(idx+1, cnt, color);
}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(board[i][j]==0) continue;
			pos[(i+j)%2].push_back({i, j});
		}
	}
	
	dfs(0, 0, 0);
	dfs(0, 0, 1);
	cout << ret[0]+ret[1];
}