#include <bits/stdc++.h>
using namespace std;

int a, c, N, M;
vector <int> A, B, ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> c;
		A.push_back(c);
	}
	cin >> M;
	for(int i = 1; i <= M; i++){
		cin >> c;
		B.push_back(c);
	}
	
	
	int aidx = 0, bidx = 0;
	while(aidx < N && bidx < M){
		int a = aidx, b = bidx, mx = 0;
		for(int i = aidx; i < N; i++){
			for(int j = bidx; j < M; j++){
				if(A[i]==B[j] && mx < A[i]){
					mx = A[i];
					a = i;
					b = j;
				}
			}
		}
		
		if(mx == 0) break;
		ret.push_back(mx);
		aidx = a + 1;
		bidx = b + 1;
	}
	
	
	cout << ret.size() << "\n";
	for(int i = 0; i < ret.size(); i++){
		cout << ret[i] << " ";
	} 
}