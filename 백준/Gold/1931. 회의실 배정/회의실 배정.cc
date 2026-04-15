#include <bits/stdc++.h>
using namespace std;

int N, a, b, ret = 1;
vector <pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		v.push_back({b, a});
	}
	sort(v.begin(), v.end());
	
	int end = v[0].first;
	for(int i = 1; i < N; i++){
		if(v[i].second >= end){
			end = v[i].first;
			ret++;
		}
	}
	
	cout << ret;
}