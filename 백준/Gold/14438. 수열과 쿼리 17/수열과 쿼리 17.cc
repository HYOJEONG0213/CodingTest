#include <bits/stdc++.h>
using namespace std;

const int INF = 1987654321;
int N, M, A[100004], a, b, c, tree[400004];

void Init(int s, int e, int node){
	if(s==e) {
		tree[node] = A[s];
		return;
	}
	
	int mid = (s+e)/2;
	Init(s, mid, node*2);
	Init(mid+1, e, node*2+1);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}

void update(int s, int e, int node, int target, int value){
	if(e < target || s > target) return;
	if(s==e){
		tree[node] = value;
		return;
	}
	
	int mid = (s+e)/2;
	update(s, mid, node*2, target, value);
	update(mid+1, e, node*2+1, target, value);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}

int getMin(int s, int e, int node, int left, int right){
	if(e < left || s > right) return INF;
	if(left <= s && e <= right) return tree[node];
	
	int mid = (s+e)/2;
	int l = getMin(s, mid, node*2, left, right);
	int r = getMin(mid+1, e, node*2+1, left, right);
	return min(l, r);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	cin >> M;
	
	Init(0, N-1, 1);
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;
		if(a == 1){
			b--;
			update(0, N-1, 1, b, c);
		}
		else{
			b--; c--;
			cout << getMin(0, N-1, 1, b, c) << "\n";
		}
	}
}