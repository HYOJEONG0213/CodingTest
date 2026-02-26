#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
const int MAXNUM = 1000000;
const int INF = 987654321;
int N, A, B, C;
pp tree[4000004];

pp sum(int s, int e, int value, int node){
	if(s==e) return tree[node];
	
	int mid = (s+e)/2;
	
	if(tree[node*2].first >= value){
		return sum(s, mid, value, node*2);
	}
	else{
		return sum(mid+1, e, value - tree[node*2].first, node*2+1);
	}
}

pp update(int s, int e, int target, int value, int node){
	if(s > target || e < target) return tree[node];
	if(s==e) {
		tree[node].first += value;
		if(tree[node].first > 0)
			tree[node].second = target;
		else
			tree[node].second = 0;
		return tree[node];
	}
	
	int mid = (s+e)/2;
	pp l = update(s, mid, target, value, node*2);
	pp r = update(mid+1, e, target, value, node*2+1);
	tree[node].first = l.first+r.first;
	tree[node].second = max(l.second, r.second);
	return tree[node];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0 ; i < N; i++){
		cin >> A;
		if(A == 1){
			cin >> B;
			int index = sum(1, MAXNUM, B, 1).second;
			cout << index << "\n"; 
			update(1, MAXNUM, index, -1, 1);
		}
		else{
			cin >> B >> C;
			update(1, MAXNUM, B, C, 1);
		}
	}
}