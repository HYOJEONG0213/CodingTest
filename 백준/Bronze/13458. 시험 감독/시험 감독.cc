#include <bits/stdc++.h>
using namespace std;

int N, A[1000004],  B , C;
long long ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i< N; i++){
		cin >> A[i];
	}
	cin >> B >> C;
	
	for(int i = 0 ; i < N ; i++){
		ret++;
		int remain = A[i]-B;
		if(remain < 0) continue;
		 
		ret += (remain+C-1) / C;
	}
	
	cout << ret;	
}