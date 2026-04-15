#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, C, a, b, board[54][54], dp[54][54][54][54], ret[54][54][54];
ll dy[2] = {0,1}, dx[2] = {1,0};
vector <pair<ll,ll>> c;

void show(){
	cout << "\n\n";
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k <= C; k++){
				cout << dp[i][j][k] << " ";
			}
			cout << "\t";
		}
		cout << " \n";
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> C;
	for(int i = 1 ; i <= C; i++){
		cin >> a >> b;
		a--, b--;
		c.push_back({a, b});
		board[a][b] = i;
	}
	
	if(board[0][0] != 0){
		dp[0][0][1][board[0][0]] = 1;
	}
	else{
		dp[0][0][0][0] = 1;
	}
		
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < 2; k++){
				int ny = i + dy[k];
				int nx = j + dx[k];
				if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if(board[ny][nx] != 0){
					for(int idx = 0; idx < board[ny][nx]; idx++){
						//cout << i << " " << j << "\n";
						for(int cnt = 0; cnt < C; cnt++){
							dp[ny][nx][cnt+1][board[ny][nx]] += dp[i][j][cnt][idx];
							dp[ny][nx][cnt+1][board[ny][nx]] %= 1000007;
						}
					}
				}
				else{
					for(int idx = 0; idx <= C; idx++){
						for(int cnt = 0; cnt <= C; cnt++){
							dp[ny][nx][cnt][idx] += dp[i][j][cnt][idx];
							dp[ny][nx][cnt][idx] %= 1000007;
						}
					}
				}
			}
		}
	}
	
	//show();
	
	for(int i = 0; i <= C; i++){
		for(int j = 0; j <= C; j++){
			ret[N-1][M-1][i] += dp[N-1][M-1][i][j];
		}
	}
	
	for(int i = 0; i <= C; i++){
		cout << ret[N-1][M-1][i] % 1000007 << " ";
	}
}