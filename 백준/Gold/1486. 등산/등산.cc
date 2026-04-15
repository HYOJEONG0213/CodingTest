#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M, T, D, board[30][30], b[2530][2530], ret;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
string s;
vector <int> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(&b[0][0], &b[0][0] + 2530*2530, INF);
	cin >> N >> M >> T >> D;
	for(int i = 0 ; i < N; i++){
		cin >> s;
		for(int j = 0 ; j < M; j++){
			if(s[j] <= 'Z')
				board[i][j] = s[j]-'A';
			else{
				board[i][j] = s[j]-'a'+26;
			}
			v.push_back(i*100+j);
		}
	}
	
	ret = board[0][0];
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < 4; k++){
				int ny = i + dy[k], nx = j + dx[k];
				if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				int num = board[i][j] - board[ny][nx];
				if(abs(num) > T) continue;
				//더 높은 산을 오르는 경우  
				if(num < 0){
					b[i*100+j][ny*100+nx] = num*num;
				}
				else{
					b[i*100+j][ny*100+nx] = 1;
				}
			}
		}
	}
	
	//b의 첫번째를 굳이 왜 0으로 초기화 안해도 맞는가..
	//그거슨 처음에 ret = a[0][0]으로 했기때문에 굳이? 이기 때문..  
	b[0][0] = 0;
	for(int k : v){
		for(int i : v){
			for(int j : v){
				b[i][j] = min(b[i][j], b[i][k]+b[k][j]);
			}
		}
	}
	//cout << b[0][0];
	
	for(int i : v){
		if(b[0][i] + b[i][0] <= D){
			ret = max(ret, board[i/100][i%100]);
		}
	}
	
	cout << ret;
}