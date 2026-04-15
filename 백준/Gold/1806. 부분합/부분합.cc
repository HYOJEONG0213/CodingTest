#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, A[100004], ret = INF;
long long S, psum[100004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> S;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		psum[i] = psum[i-1] + A[i];
	}
	
	int start = 0, end = 1;
		
	while(end <= N){
		if(psum[end] - psum[start] < S){
			end++;
		}
		else{
			ret = min(ret, end-start);
			start++;
		}
	}
	
	
	cout << (ret == INF ? 0 : ret);
}