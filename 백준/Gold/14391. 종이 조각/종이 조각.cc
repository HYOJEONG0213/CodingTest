#include <bits/stdc++.h>
using namespace std;

int N, M, a[5][5], ret;
string s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for(int i = 0; i<N; i++){
		cin >> s;
		for(int j = 0; j <M; j++){
			a[i][j] = s[j] - '0';
		}
	}
	
	for(int i = 0; i < (1 << (N * M)); i++){
		int sum = 0;
		//가로 검사 : 0 
		for(int j = 0; j < N; j++){
			int cur = 0;
			for(int k = 0; k < M; k++){
				int number = 1 << (j * M + k);
				if((i & number) == 0){
					cur = cur * 10 + a[j][k];
				}
				else{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;	//마지막엔 더해주는것도 해야지! 
		}
		
		//세로 검사 : 1 
		for(int k = 0; k < M; k++){
			int cur = 0;
			for(int j = 0; j < N; j++){
				int number = 1 << (j * M + k);
				// == 1로 하면 안됨. != 0 으로 해야함. 
				if((i & number) != 0){
					cur = cur * 10 + a[j][k];
				}
				else{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur; 
		}
		
		ret = max(ret, sum);
	}
	
	cout << ret;
}