#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, D[2000004], A[1000004];
vector <int> T;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	T.push_back(0);
	for(int i = 0; i < N; i++){
		T.push_back(A[i]);
		T.push_back(0);
	}
	
	int R=0, C=0; 	//R:팰린드롬 가장 오른쪽, C: 팰린드롬 가운데  
	
	for(int i = 0; i < T.size(); i++){
		if(i <= R){
			int mirror = 2*C - i;
			D[i] = min(D[mirror], R-i);
		} 
		else{
			D[i] = 0;
		}
		
		// 범위 체크 및 팰린드롬 여부 확인  
		while(i-1-D[i]>=0 && i+1+D[i]<T.size() && T[i-1-D[i]]==T[i+1+D[i]]){
			D[i]++;
		}
		
		if(R < i + D[i]){
			R = i + D[i];
			C = i;
		}
	}
	
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		a--;
		b--;
		// T에선 a번째가 2a+1에 저장되므로
		// (2a+1 + 2b+1) / 2 이므로  
		if(D[a+b+1] >= b-a+1){
			cout << 1 << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
}