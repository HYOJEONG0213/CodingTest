#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pp;
int n, h, o, ret;
vector <pp> v;
priority_queue <int, vector<int>, greater<int>> pq;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> h >> o;
		if(h > o){
			v.push_back({h, o});
		}
		else
			v.push_back({o, h});
	}
	cin >> h;
	// 도착 위치 순서로 오름차순  
	sort(v.begin(), v.end());
	
	
	for(int i = 0; i < n; i++){
		int s = v[i].second;
		int e = v[i].first;
		if(e - s <= h) {
			pq.push(s);
		}
		
		while(pq.size()){
			int t = pq.top();
			if(t < e - h) {
				pq.pop();
				continue;
			}
			ret = max(ret, (int)pq.size());
			break;
		}
	}
	
	cout << ret;
}