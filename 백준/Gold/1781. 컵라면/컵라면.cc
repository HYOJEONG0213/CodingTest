#include <bits/stdc++.h>
using namespace std;

int N, day, cup, ret;
vector <pair<int,int>> v;
priority_queue <int, vector <int>, greater <int>> pq;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i =0;i<N;i++){
		cin >> day >> cup;
		v.push_back({day, cup});
	}
	
	//day순 오름차순 
	sort(v.begin(), v.end());
	
	for(auto i : v){
		pq.push(i.second);
		if(pq.size() > i.first){
			//없애는 부분 
			pq.pop(); 
		}
	}
	
	while(pq.size()){
		ret += pq.top();
		pq.pop();
	}
	
	cout << ret;
}