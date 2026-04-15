#include <bits/stdc++.h>
using namespace std;

int N, M, a, ret;
vector <int> A, B;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0 ; i < N; i++){
		cin >> a;
		A.push_back(a);
	}
	for(int i = 0 ; i < M; i++){
		cin >> a;
		B.push_back(a);;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	for(int i = 0 ; i < M; i++){
		auto temp = lower_bound(A.begin(), A.end(), B[i]);
		if(*temp == B[i]) ret++;
	}
	
	
	cout << N+M - ret*2;
}