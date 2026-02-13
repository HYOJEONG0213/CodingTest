#include <bits/stdc++.h>
using namespace std;

int N, K, A[14], ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = N-1; i >= 0; i--){
		ret += K / A[i];
		K %= A[i];
	}
	
	cout << ret;
	
}