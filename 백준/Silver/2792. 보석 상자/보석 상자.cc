#include <bits/stdc++.h>
using namespace std;

int N, M, a[300004], maxValue, ret;

int check(int mid){
	int cnt = 0;
	for(int i = 0 ; i < M ; i++){
		cnt += a[i] / mid + (a[i]%mid != 0 ? 1 : 0);
	}
	
	return cnt <= N;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> a[i];
		maxValue = max(maxValue, a[i]);
	}
	
	int l = 1, r = maxValue;
	while(l <= r){
		int mid = (l + r) / 2;
		//cout << mid << " "; 
		if(check(mid)){
			//cout << "성공\n";
			r = mid -1;
			ret = mid;
		}
		else{
			l = mid + 1;
		}
	}
	
	cout << ret;
	
}