#include <bits/stdc++.h>
using namespace std;

const int INF = 1111111111;
int N, M, A[100004], a, b;
pair <int,int> tree[1<<18];

pair <int,int> init(int s, int e, int node){
	if(s == e) return tree[node] = make_pair(A[s], A[s]);
	
	int mid = (s + e) / 2;
	auto l = init(s, mid, node*2);
	auto r = init(mid+1, e, node*2+1);
	
	return tree[node] = {min(l.first, r.first), max(l.second, r.second)};
}

pair<int,int> getMaxMin(int s, int e, int node, int left, int right){
	// 범위 확인 
	if(e < left || s > right) return {INF, -INF};
	if(left <= s && right >= e) return tree[node];
	
	//두부분으로 나누기
	int mid = (s+e)/2;
	auto l = getMaxMin(s, mid, node*2, left, right);
	auto r = getMaxMin(mid+1, e, node*2+1, left, right);
	return make_pair(min(l.first, r.first), max(l.second, r.second));
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	} 
	
	init(0, N-1, 1);
	
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		a--; b--;
		auto ret = getMaxMin(0, N-1, 1, a, b);
		cout << ret.first << " " << ret.second << "\n";
		
	}
}