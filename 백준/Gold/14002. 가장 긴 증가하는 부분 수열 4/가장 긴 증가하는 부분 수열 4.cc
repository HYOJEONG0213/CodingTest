#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int N, a, B[1004], cnt;
pair <int, int> A[1004];
vector <int> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(B, B+1004, INF);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a;
		auto iter = lower_bound(B, B+cnt, a);
		if(*iter == INF) cnt++;
		*iter = a;
		A[i] = {a, (iter - &B[0])};
	}
	
	cout << cnt << "\n";
	
	cnt--;
	for(int i = N-1; i >= 0; i--){		
		if(A[i].second == cnt){
			v.push_back(A[i].first);
			cnt--;
		}
	}
	
	reverse(v.begin(), v.end());
	
	for(int i : v) cout << i << " ";
}