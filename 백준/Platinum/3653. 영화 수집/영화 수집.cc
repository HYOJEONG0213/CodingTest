#include <bits/stdc++.h>
using namespace std;


int T, N, M, tree[200004], temp;
map <int, int> mp;

void update(int idx, int value){
	while(idx < 200004){
		tree[idx] += value;
		idx += idx & -idx;
	}
}

int sum(int idx){
	int ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		// 초기화 
		memset(tree, 0, sizeof(tree));
		mp.clear();
		int MAXVALUE = 100001;
		
		cin >> N >> M;
		for(int i = 1; i <= N; i++){
			int index = i + MAXVALUE;
			mp[i] = index;
			update(index, 1); 
		}
		
		for(int i = 0; i < M; i++){
			cin >> temp;
			int index = mp[temp];
			cout << sum(index) -1 << " ";
			update(index, -1);
			
			MAXVALUE--;
			update(MAXVALUE, 1);
			mp[temp] = MAXVALUE;
		}
		cout << "\n";
	}
}