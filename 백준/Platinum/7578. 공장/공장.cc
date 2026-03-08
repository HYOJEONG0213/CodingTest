#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
int N, a, A[500004], tree[2000004];
vector <int> C;
vector <pp> B;
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
		B.push_back({a, i});
	}
	sort(B.begin(), B.end());
	
	for(int i = 0; i < N; i++){
		int l = 0, r = B.size()-1;
		while(l <= r){
			int mid = (l+r)/2;
			if(B[mid].first == A[i]){
				C.push_back(B[mid].second);
				break;
			}
			else if(B[mid].first < A[i]){
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
	}

	for(int i = 0; i < N; i++){
		//1-based
		ret += query(1, N, 1, C[i]+2, N);
		update(1, N, 1, C[i]+1);
	}
	
	cout << ret;
}