#include <bits/stdc++.h>
using namespace std;

int M, N, a[54][54], visited[54][54], dy[4] = {0, -1, 0, 1}, dx[4] = {-1, 0, 1, 0};
int ret1, ret2[2504], ret3;
//ret2 크기를 길~~게 해야하는구나  

int dfs(int y, int x, int cnt){
	int ret = 1;
	
	for(int i= 0; i < 4; i++){
		if((a[y][x] & (1 << i)) == 0){
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if(ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
			if(visited[ny][nx] != 0) continue;
			
			visited[ny][nx] = cnt;
			ret += dfs(ny, nx, cnt);
		}
	}
	
	return ret;
}




int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cin >> a[i][j];
		}
	}
	
	//dfs 돌리기 부분  
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(visited[i][j] == 0){
				ret1++;
				visited[i][j] = ret1;
				ret2[ret1] = dfs(i, j, ret1);
			}
		}
	}
	
	//벽 합치기 
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(i+1 < M){
				if(visited[i][j] != visited[i+1][j]){
					int temp = ret2[visited[i][j]] + ret2[visited[i+1][j]];
					ret3 = max(ret3, temp);
				}
			}
			if(j+1 < N){
				if(visited[i][j] != visited[i][j+1]){
					int temp = ret2[visited[i][j]] + ret2[visited[i][j+1]];
					ret3 = max(ret3, temp);
				}
			}
		}
	}

	
	cout << ret1 << "\n";
	cout << *max_element(ret2, ret2+50) << "\n";
	cout << ret3;
	
	//for(auto i : ret2) cout << i << " ";
}