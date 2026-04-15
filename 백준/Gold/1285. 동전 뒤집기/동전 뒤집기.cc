#include <bits/stdc++.h>
using namespace std;

int N, a[25], ret = 987654321;
char c;

void go(int here){
	if(here == N){
		int sum = 0;
		
		for(int i = 1; i < (1 << N); i*=2){
			int cnt = 0;
			for(int j = 0; j < N; j++){
				if(i & a[j]) cnt++;
			}
			
			sum += min(cnt, N - cnt);
		}
		
		ret = min(sum, ret);
		
		return;
	}
	
	go(here+1);
	a[here] = ~a[here];
	go(here+1);
	
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> c;
			if(c == 'T')
				a[i] += 1 << j;
		}
	}
	
	
	go(0);
	
	cout << ret;
}