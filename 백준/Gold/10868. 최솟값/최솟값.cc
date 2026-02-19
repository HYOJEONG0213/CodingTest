#include <bits/stdc++.h>
using namespace std;

const int INF = 1111111111;
int N, M, a, b, A[100004], tree[1<<20];

int init(int s, int e, int index){
	if(s == e) return tree[index] = A[s];
	
	int mid = (s+e)/2;
	int l = init(s, mid, index*2);
	int r = init(mid+1, e, index*2+1);
	
	return tree[index] = min(l, r);
}

int getMin(int s, int e, int left, int right, int index){
	// 범위 완전 밖, 내부인지 확인  
	if(e < left || s > right) return INF;
	if(left <= s && e <= right) return tree[index];
	
	int mid = (s+e)/2;
	int l = getMin(s, mid, left, right, index*2);
	int r = getMin(mid+1, e, left, right, index*2+1);
	
	return min(l, r);
	
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
		cout << getMin(0, N-1, a, b, 1) << "\n";
	}
}