#include <bits/stdc++.h>
using namespace std;

int N, a[24][24], ret;

void check(int b[24][24]){
	for(int i = 0 ; i < N; i++){
		for(int j = 0; j < N; j++){
			ret = max(ret, b[i][j]);
		}
	}
}

void print(int b[24][24]){
	for(int i = 0 ; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << b[i][j] << " ";
		}
		cout << "\n\n";
	}
}

void rotate90(int b[24][24]){
	int temp[24][24] = {0};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			//temp[i][j] = b[N-1-j][i];
			temp[i][j] = b[j][N-i-1];
		}
	}
	memcpy(b, temp, sizeof(temp));
}

void move(int b[24][24]){
	int temp[24][24];
	memset(temp, 0, sizeof(temp));
	
	for(int i = 0; i < N; i++){
		int cnt = 0;
		for(int j = 0; j < N; j++){
			if(b[i][j] == 0) continue;
			
			if(temp[i][cnt] == 0){
				temp[i][cnt] = b[i][j];
			}
			else if(temp[i][cnt] == b[i][j]){
				temp[i][cnt] *= 2;
				cnt++;
			}
			else{
				cnt++;
				temp[i][cnt] = b[i][j];
			}
		}
		
//		while(cnt < N){
//			cnt++;
//			temp[i][cnt] = 0;
//		}
	}

	memcpy(b, temp, sizeof(temp));

	//print(b);
}


void go(int b[24][24], int here){
	if(here == 5){
		check(b);
		return;
	}
	
	for(int i = 0; i < 4; i++){
		int cpy[24][24];
		//memset(cpy, 0, sizeof(cpy));
		memcpy(cpy, b, sizeof(cpy));
		move(cpy);
		go(cpy, here+1);
		rotate90(b);
		//print(cpy);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for(int i = 0 ; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> a[i][j];
		}
	}
	
	go(a, 0);
	
	cout << ret;
}