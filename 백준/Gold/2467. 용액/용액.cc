#include <bits/stdc++.h>
using namespace std;

const int INF = 2000000004;
int N, A[100004], ret = INF, ret1, ret2;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	int l = 0, r = N-1;
	while(l < r){
		int temp = A[l] + A[r];
		
		if(abs(temp) < ret){
			ret = abs(temp);
			ret1 = A[l];
			ret2 = A[r];
		}
		
		if(temp < 0){
			l++;
		}
		else{
			r--;
		}
	}
	
	
	cout << ret1 << " " << ret2;
}