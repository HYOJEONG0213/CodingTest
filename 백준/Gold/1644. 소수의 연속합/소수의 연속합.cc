#include <bits/stdc++.h>
using namespace std;

int N, ret, p, sum, a[4000001];
bool che[4000001];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	for(int i = 2; i <= N; i++){
		if(che[i]) continue;
		for(int j = 2*i; j <= N; j+= i){
			che[j] = 1;
		}
	}
	
	for(int i = 2; i <= N; i++){
		if(che[i] == 0){
			a[p] = i;
			p++;
		}
	}
	
	int start = 0, end = 0;
	while(1){
		if(sum >= N){
			sum -= a[start];
			start++;
		}
		else if(end == p)
			break;
		else{
			sum += a[end];
			end++;
		}
		
		if(sum == N)
			ret++;
	}
	
	cout << ret;
}