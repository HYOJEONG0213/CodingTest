#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
const int INF = 1111111111;
int N, A[100004], a, b, c, M;
pp tree[400004];

pp init(int s, int e, int index){
	if(s==e) return tree[index] = {A[s], s};
	//if(e < index || s > index) return
	
	int mid = (s+e)/2;
	pp l = init(s, mid, index*2);
	pp r = init(mid+1, e, index*2+1);

	if(l.first <= r.first)
		return tree[index] = {l.first, l.second};
	else
		return tree[index] = {r.first, r.second};
}

pp update(int s, int e, int index, int target, int value){
	if(target < s || target > e) return tree[index];
	if(s==e){
		tree[index].first = value;
		return tree[index];
	}
	
	int mid = (s+e)/2;
	pp l = update(s, mid, index*2, target, value);
	pp r = update(mid+1, e, index*2+1, target, value);
	if(l.first <= r.first)
		return tree[index] = {l.first, l.second};
	else
		return tree[index] = {r.first, r.second};
}

pp sum(int s, int e, int index, int left, int right){
	if(e < left || s > right) return {INF, -1};
	
	if(left <= s && e <= right) return tree[index];
	
	int mid = (s+e)/2;
	pp l = sum(s, mid, index*2, left, right);
	pp r = sum(mid+1, e, index*2+1, left, right);
	
	if(l.first <= r.first)
		return l;
	else
		return r;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(tree, tree+400004, make_pair(INF, -1));
	cin >> N;
	for(int i = 1 ; i <= N; i++){
		cin >> A[i];
	}
	init(1, N, 1);
	cin >> M;
	for(int i = 1 ; i <= M; i++){
		cin >> a >> b >> c;
		if(a==1){
			update(1, N, 1, b, c);
			A[b] = c;
		}
		else{
			cout << sum(1, N, 1, b, c).second << "\n";
		}
	}
}