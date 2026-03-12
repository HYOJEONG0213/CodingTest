#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
const int MAXNUM = 1000000000;
int N, A[500004], ret[500004], tree[500004];
vector <pp> sortA;

void update(int index, int value){
	while(index <= N){
		tree[index] += value;
		index += index&-index;
	}
}

int sum(int index){
	int num = 0;
	while(index > 0){
		num += tree[index];
		index -= index&-index;
	}
	return num;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		sortA.push_back({A[i], i});
	}
	sort(sortA.begin(), sortA.end());
	
	for(int i = 0; i < sortA.size(); i++){
		int value = sortA[i].first;
		int index = sortA[i].second;
		ret[index] = index - sum(index);
		update(index, 1);
	}
	
	for(int i = 1; i <= N; i++){
		cout << ret[i] << "\n";
	}
}