#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, A[1004], B[1004], C[1004], cntB, cntC, ret, dpB[1004], dpC[1004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0 ; i < N; i++){
		cin >> A[i];
	}
	
	fill(B, B+1004, INF);
	for(int i = 0 ; i < N; i++){
		auto iter = lower_bound(B, B+cntB, A[i]);
		if(*iter==INF) cntB++;
		*iter = A[i];
		dpB[i] = cntB;
	}
	
	
	fill(C, C+1004, INF);
	for(int i = N-1 ; i >= 0; i--){
		auto iter = lower_bound(C, C+cntC, A[i]);
		if(*iter==INF) cntC++;
		*iter = A[i];
		
		dpC[i] = cntC;
	}
	
	for(int i = 0; i < N; i++){
		ret = max(ret, dpB[i]+dpC[i]-1);
	}
	
	
	cout << ret;
	
}