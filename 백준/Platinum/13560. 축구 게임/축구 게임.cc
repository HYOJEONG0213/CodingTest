#include <bits/stdc++.h>
using namespace std;

int n, A[10004], psum[10004], psum2[10004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	sort(A+1, A+n+1);
	for(int i = 1; i <= n; i++){
		psum[i] = psum[i-1] + A[i];
		psum2[i] = (i*(i-1))/2;
		if(psum[i] < psum2[i]){
			cout << -1;
			return 0;
		}
	}
	
	if(psum[n] != psum2[n]){
		cout << -1;
	}
	else{
		cout << 1;
	}
	
}