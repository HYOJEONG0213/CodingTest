#include <bits/stdc++.h>
using namespace std;

int N, M, board[1004][1004], p[1004*1005], level[1004*1005], visited[1004*1005], ret;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
string s;
map <char, int> mp = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

int find(int x){
	if(p[x]==-1){
		return x;
	}
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	
	if(x==y) return;
	
	if(level[x] < level[y]){
		p[x] = y;
	}
	else{
		if(level[x] == level[y]){
			level[x]++;
		}
		p[y] = x;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < M; j++){
			board[i][j] = mp[s[j]];
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int idx = M * i + j;
			int temp = find(idx);
			if(p[temp] != -1) continue;
			
			int ny = i + dy[board[i][j]];
			int nx = j + dx[board[i][j]];
			merge(idx, ny * M + nx);
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int idx = M * i + j;
			int temp = find(idx);
			if(visited[temp] != 0) continue;
			visited[temp] = 1;
			ret++;
		} 
	}
	
	cout << ret;
}