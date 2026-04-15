#include <bits/stdc++.h>
using namespace std;

int N, M, A[100004], ret=987654321, sum, mx;

int check(int interval){
	if(mx > interval) return 0;
	int cnt = 0;
	int temp = interval;
	
	for(int i = 0 ; i < N ; i++){
		if(interval - A[i] >= 0)
			interval -= A[i];
		else{
			interval = temp;
			interval -= A[i];
			cnt++;
		}
	}
	
	if(temp != interval) cnt++;
	return cnt <= M;
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0 ; i < N; i++){
		cin >> A[i];
		sum += A[i];
		mx = max(mx, A[i]);
	}
	
	int l = 1, r = sum;
	while(l <= r){
		int mid = (l+r)/2;
		if(check(mid) == 1){
			r = mid - 1;
			ret = min(ret, mid);
		}
		else{
			l = mid + 1;
		}
	}
	
	cout << ret;
}