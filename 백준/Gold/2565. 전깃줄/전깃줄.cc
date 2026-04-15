#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, a, b, cnt, B[104];
vector <pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(B, B+104, INF);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	
	for(int i = 0; i < N; i++){
		auto iter = lower_bound(B, B+cnt, v[i].second);
		if(*iter == INF) cnt++;
		*iter = v[i].second;
	}
	
	cout << N - cnt;
}