#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, A[10004], r, l, ret, sum, ret_sum;

void show(ll mid){
	for(int i = 0; i < M; i++){
		ll sum = mid / A[i];
		cout << sum + 1 << " ";
	}
	cout << "\n";
}

ll check(ll mid){
	ll cnt = 0;
	for(int i = 0; i < M; i++){
		cnt += mid / A[i];
		cnt++;
	}
	
	//cout << cnt << "\n";
	return cnt;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> A[i];
	}
	
	if(N <= M){
		cout << N;
		return 0;
	}
	
	l = 1, r = 1e15;
	while(l <= r){
		sum = 0;
		ll mid = (l+r)/2;
		//cout << mid << " ";
		
		sum = check(mid);
		if(sum < N){
			l = mid + 1;
			ret = max(ret, mid);
		}
		else if(sum >= N){
			r = mid - 1;
		}
	}
	
	//show(ret);
	ret_sum = check(ret);
	//cout << ret << " " << ret_sum << "\n";
	
	
	//숫자 세기 
	while(1){
		ret++;
		for(int j = 0; j < M ; j++){
			if(ret % A[j] == 0){
				ret_sum++;
				
				if(ret_sum == N) {
					cout << j+1;
					exit(0);
				}
			}
		}
	}
		
	
	
}