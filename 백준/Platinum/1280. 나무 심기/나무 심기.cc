#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxNum = 200004; 
ll N, a, rret=1;
vector <ll> treeCnt, treeSum;

ll sum(vector <ll> &tree, ll idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= idx & -idx;
	}
	
	return ret;
}

ll getQuery(vector <ll> &tree, ll a, ll b){
	if(a > b) return 0; 
	return sum(tree, b) - sum(tree, a-1);
}

void update(vector <ll> &tree, ll idx, ll value){
	while(idx < maxNum){
		tree[idx] += value;
		idx += idx&-idx;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	treeCnt.resize(maxNum, 0);
	treeSum.resize(maxNum, 0);
	
	cin >> a;
	//a가 0이 들어올 경우 첫번째 배열에 업데이트 되는데,
	//첫번째 배열은 0으로 둬야하므로 1씩 더함
	a++; 
	update(treeCnt, a, 1);
	update(treeSum, a, a);
	
	for(int i = 0; i < N-1; i++){
		cin >> a;
		a++;
		
		//현재꺼가 큰 경우의 합 = value * 개수 - 이전꺼의 합  
		ll left = a * getQuery(treeCnt, 1, a-1) - getQuery(treeSum, 1, a-1);
		//현재꺼가 작은 경우의 합  
		ll right = getQuery(treeSum, a+1, maxNum) - a * getQuery(treeCnt, a+1, maxNum);
		rret *= (left+right) % 1000000007;
		rret %= 1000000007;
		
		
		update(treeCnt, a, 1);
		update(treeSum, a, a);
	}
	
	cout << rret;
}