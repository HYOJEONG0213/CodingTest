#include <bits/stdc++.h>
using namespace std;

int N, L, a[104][104], b[104][104], ret;

void go(int arr[104][104]){
	for(int i = 0; i < N; i++){
		int cnt = 1;
		for(int j = 0; j < N-1; j++){
			if(arr[i][j] == arr[i][j+1]) cnt++;
			else if(arr[i][j] == arr[i][j+1] - 1 && cnt >= L) cnt = 1;
			else if(arr[i][j] == arr[i][j+1] + 1 && cnt >= 0) cnt = -L + 1;
			else break;
			
			
			if(j == N-2 && cnt >= 0) ret++;
		}
	}
	
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> L;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}
	
	go(a); go(b); 
	
	cout << ret;
}