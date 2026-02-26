#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXNUM = 1000004;
const int INF = 987654321;
int N, A, B, C, tree[4000004];

void update(int index, int value){
	while(index < MAXNUM){
		tree[index] += value;
		index += index & -index;
	}
}

int sum(int index){
	int ret = 0;
	while(index > 0){
		ret += tree[index];
		index -= index&-index;
	}
	return ret;
}

int getIndex(int value){
	int s = 1, e = MAXNUM;
	int ret = 0;
	
	while(s <= e){
		int mid = (s+e)/2;
		if(sum(mid) >= value){
			ret = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0 ; i < N; i++){
		cin >> A;
		if(A == 1){
			cin >> B;
			int index = getIndex(B);
			cout << index << "\n"; 
			update(index, -1);
		}
		else{
			cin >> B >> C;
			update(B, C);
		}
	}
}