#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, A[1000004], B[1000004], p[1000004], cnt;
vector <int> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(B, B+1000004, INF);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		auto iter = lower_bound(B, B+cnt, A[i]);
		if(*iter==INF) 
			cnt++;
		*iter = A[i];
		p[i] = iter-B;
	}
	
	
	cout << cnt << "\n";
	for(int i = N-1; i >= 0; i--){
		if(p[i]==cnt-1) {
			v.push_back(A[i]);
			cnt--;
		}
	}
	reverse(v.begin(), v.end());
	for(int i : v) cout << i << " ";
}