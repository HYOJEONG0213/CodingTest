#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
int N, a, tree[500004];
vector <int> A, sortA;
ll ret;

void update(int index, int value){
	while(index <= N){
		tree[index] += value;
		index += index&-index;
	}
}

ll sum(int index){
	ll ret = 0;
	while(index > 0){
		ret += tree[index];
		index -= index&-index;
	}
	return ret;
}

int getRank(int value){
	int index = lower_bound(sortA.begin(), sortA.end(), value) - sortA.begin();
	// tree[0] 은 비워줘야하므로  
	return index + 1;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a;
		A.push_back(a);
		sortA.push_back(a);
	}
	sort(sortA.begin(), sortA.end());
	
	for(int i = 0; i < N; i++){
		// 좌표 압축  
		int index = getRank(A[i]);
		// 내 인덱스번호 - 내앞에 나보다 작거나 같은수 
		ret += i - sum(index);
		update(index, 1);	//나를 트리에 등록  
	}
	
	cout << ret;
}