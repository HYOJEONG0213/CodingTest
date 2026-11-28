#include <bits/stdc++.h>
using namespace std;

const int MAXNUMBER = 987654321;
int H, W, arr[504], mx, mxidx, ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W;
	for(int i = 0; i < W; i++){
		cin >> arr[i];
	}
	
	int idx = 0;
	mx = arr[0];
	
	for(idx = 1; idx < W; idx++){
		// 왼 < 오 (갱신)  
		if(mx <= arr[idx]){
			for(int j = mxidx+1; j < idx; j++){
				ret += mx - arr[j];
				//cout << mx - arr[j] << " ";
				arr[j] = mx;
			}
			mx = arr[idx];
			mxidx = idx;
		}
	}
	
	idx = 0;
	mx = arr[W-1];
	mxidx = W-1;
	for(idx = W-2; idx >= 0; idx--){
		// 왼 > 오 (갱신)  
		if(mx <= arr[idx]){
			for(int j = mxidx-1; j > idx; j--){
				ret += mx - arr[j];
				//cout << mx - arr[j] << " ";
				arr[j] = mx;
			}
			mxidx = idx;
			mx = arr[idx];
		}
	}
	
	
	
	cout << ret;
}