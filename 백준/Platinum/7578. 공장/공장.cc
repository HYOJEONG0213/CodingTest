#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
int N, a, A[500004], B[1000004], tree[2000004];
vector <int> C;
ll ret;

int query(int s, int e, int node, int left, int right){
	if(e < left || s > right) return 0;
	if(left <= s && e <= right) return tree[node];
	
	int mid = (s+e)/2;
	int l = query(s, mid, node*2, left, right);
	int r = query(mid+1, e, node*2+1, left, right);
	return l+r;
}

void update(int s, int e, int node, int target){
	if(e < target || s > target) return;
	tree[node]++;
	if(s==e) return;
	
	int mid = (s+e)/2;
	update(s, mid, node*2, target);
	update(mid+1, e, node*2+1, target);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = 0; i < N; i++){
		cin >> a;
		B[a] = i;
	}

	for(int i = 0; i < N; i++){
		//1-based
		ret += query(0, N-1, 1, B[A[i]]+1, N);
		update(0, N-1, 1, B[A[i]]);
	}
	
	cout << ret;
}