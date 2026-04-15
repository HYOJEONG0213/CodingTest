#include <bits/stdc++.h>
using namespace std;

int N, M, C, A[24], bag[24];

int go(int cnt, int idx){
	if(cnt == idx) return true;
	
	//i : 가방 번째수 
	for(int i = 0; i < M; i++){
		if(bag[i] + A[idx] <= C){
			bag[i] += A[idx];
			if(go(cnt, idx+1) == true) return true;
			//해당 경우에서 실패한 경우 일단 후퇴시키기  
			bag[i] -= A[idx];
		}
		
		//아예 보석 할당 못하는 경우 
		if(bag[i] == 0) return false;
	}
	
	return false;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> C;
	vector <int> V;
	for(int i = 0 ; i < N; i++){
		cin >> A[i];
	}
	
	sort(A, A+N);
	for(int i = N; i >= 0; i--){
		if(go(i, 0)){
			cout << i ;
			return 0;
		}
	}
}