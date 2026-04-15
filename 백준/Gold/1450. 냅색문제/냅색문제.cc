#include <bits/stdc++.h>
using namespace std;

int N, C, A[34], ret;

void go(int start, int end, vector <int> &v, int sum){
	if(sum > C) return;
	if(start > end) {
		v.push_back(sum);
		return;
	}
	
	go(start+1, end, v, sum + A[start]);
	go(start+1, end, v, sum);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	vector <int> v1;
	vector <int> v2;
	go(0, N/2 - 1, v1, 0);
	go(N/2, N - 1, v2, 0);
	
	//for(int i : v1) cout << i << " ";
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	for(int i = 0; i < v1.size(); i++){
		int num = C - v1[i];
		if(num < 0) continue;
		auto iter = upper_bound(v2.begin(), v2.end(), num);
		ret += iter - v2.begin();
	}
	
	cout << ret;
}