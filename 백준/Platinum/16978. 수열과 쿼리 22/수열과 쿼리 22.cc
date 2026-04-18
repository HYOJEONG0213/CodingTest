#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
ll N, M, A[100004], num, tree[100004];
struct Q1{
	int i, v, idx;
};
struct Q2{
	int k, i, j, idx;
	
	bool operator <(const Q2 &other) const{
		return k < other.k;
	}
};
vector <Q1> q1;
vector <Q2> q2;
vector <pp> ret;

void update(int idx, int value){
	while(idx <= 100000){
		tree[idx] += value;
		idx += idx&-idx;
	}
}

ll sum(int idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= idx&-idx;
	}
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		update(i, A[i]);
	}
	cin >> M;
	Q1 a1;
	Q2 a2;
	for(int i = 0; i < M; i++){
		cin >> num;
		if(num==1){
			cin >> a1.i >> a1.v;
			a1.idx = i+1;
			q1.push_back(a1);
		}
		else{
			cin >> a2.k >> a2.i >> a2.j;
			a2.idx = i+1;
			q2.push_back(a2);
		}
	}
	
	sort(q2.begin(), q2.end());
	int j = 0;
	for(int i = 0; i < q2.size(); i++){
		while(q2[i].k > j){
			update(q1[j].i, q1[j].v - A[q1[j].i]);
			A[q1[j].i] = q1[j].v;
			j++;
		}
		ret.push_back({q2[i].idx, sum(q2[i].j) - sum(q2[i].i-1)});
	}
	
	sort(ret.begin(), ret.end());
	for(auto i : ret){
		cout << i.second << "\n";
	}
}