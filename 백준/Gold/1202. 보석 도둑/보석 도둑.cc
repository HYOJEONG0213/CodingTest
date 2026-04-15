#include <bits/stdc++.h>
using namespace std;

int N, K, a, b, c;
long long ret;
vector <pair<int,int>> v;
vector <int> vv;
priority_queue <int> pq;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	
	for(int i = 0; i < K; i++){
		cin >> c;
		vv.push_back(c);
	}
	sort(vv.begin(), vv.end());
	
	int j = 0;
	for(int i = 0; i < K; i++){
		while(j < N && vv[i] >= v[j].first){
			pq.push(v[j].second);
			j++;
		}
		
		if(pq.size()){
			ret += pq.top();
			pq.pop();
		}
	}
	
	cout << ret;
}