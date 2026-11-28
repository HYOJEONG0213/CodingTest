#include <bits/stdc++.h>
using namespace std;

const int MAXNUMBER = 987654321;
int H, W, arr[504], L[504], R[504], ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W;
	for(int i = 0; i < W; i++){
		cin >> arr[i];
	}
	
	L[0] = arr[0];
	R[W-1] = arr[W-1];
	for(int i = 1; i < W; i++) L[i] = max(L[i-1], arr[i]);
	for(int i = W-2; i >= 0; i--) R[i] = max(R[i+1], arr[i]);
	
	for(int i = 0 ; i < W; i++)
		ret += min(L[i], R[i]) - arr[i];
	
	cout << ret;
}