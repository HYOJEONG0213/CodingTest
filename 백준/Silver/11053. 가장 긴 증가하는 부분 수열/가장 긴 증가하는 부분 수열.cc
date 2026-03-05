#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int N, A[1004], B[1004], cnt;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(B, B+1004, INF);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		auto iter = lower_bound(B, B+cnt, A[i]);
		if(*iter == INF) cnt++;
		*iter = A[i];
	}
	
	cout << cnt;
}