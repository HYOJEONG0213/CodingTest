#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
int N, a, A[500004], B[1000004];
ll tree[500004];
vector <int> C;
ll ret;

void update(int idx, int value){
	while(idx <= N){
		tree[idx] += value;
		idx += idx&-idx;
	}
}

ll sum(int idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= idx&-idx;
	}
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	for(int i = 1; i <= N; i++){
		cin >> a;
		B[a] = i;
	}

	for(int i = 1; i <= N; i++){
		//1-based
		ret += sum(N) - sum(B[A[i]]);
		update(B[A[i]], 1);
	}
	
	cout << ret;
}