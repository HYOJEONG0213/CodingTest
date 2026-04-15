#include <bits/stdc++.h>
using namespace std;

int N, p, d, ret, visited[10004];
vector <pair<int,int>> a;
priority_queue <int, vector<int>, greater <int>> pq;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> p >> d;
		a.push_back({d, p});
	}
	sort(a.begin(), a.end());

	
	//일단 집어놓고 만약 day일보다 일이 많아지면 
	//가장 낮은 임금 탈락  
	//왜? 큰거 두개 있으면 앞선 날에 처리해도 되잖아 
	for(int i = 0; i< N; i++){
		pq.push(a[i].second);
		if(pq.size() > a[i].first)
			pq.pop();
	}
	
	while(pq.size()){
		ret += pq.top();
		pq.pop();
	}
	
	cout << ret;
}

