#include <bits/stdc++.h>
using namespace std;

int T, N, M, a[20004], b[20004], ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	
	while(T--){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		ret = 0 ;
		cin >> N >> M;
		for(int i =0; i < N; i++){
			cin >> a[i];
		}
		for(int i =0; i < M; i++){
			cin >> b[i];
		}
		sort(&a[0], &a[N]);
		sort(&b[0], &b[M]);
		
		
		for(int i = 0; i < N; i++){
			auto pos = lower_bound(&b[0], &b[M], a[i]) - &b[0];
			//cout << pos << " ";
			ret += pos;
		}
		
		
		
		cout << ret << "\n";
	}
}