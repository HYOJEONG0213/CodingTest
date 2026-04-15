#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, ret, l, r, a[100004], sum;

int check(ll mid){
	int cnt = 1, temp = 0;
	for(int i = 0; i < N; i++){
		if(temp + a[i] <= mid){
			temp += a[i];
		}
		else{
			cnt++;
			temp = a[i];
		}
	}
	
	return cnt <= M;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> a[i];
		sum += a[i];
		l = max(l, a[i]);
	}
	
	r = sum;
	
	while(l <= r){
		ll mid = (l+r)/2;
		if(check(mid)){
			r = mid - 1;
			ret = mid;
		}
		else{
			l = mid + 1;
		}
	}
	
	cout << ret;
}