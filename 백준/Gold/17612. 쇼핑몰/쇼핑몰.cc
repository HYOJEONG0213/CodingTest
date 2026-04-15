#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<ll,ll,ll> pp;
ll N, k, id[100004], w[100004], ret;
vector <ll> ret_list;



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> k;
	for(int i = 0; i < N; i++){
		cin >> id[i] >> w[i];
	}
	
	//입장은 앞에서부터지만 퇴장은 뒤에서부터임  
	priority_queue <pp, vector <pp>, greater <pp>> pq;
	ll prevTime = 30;
	vector <pair<ll,ll>> v;
	ll idx = 0; 
	while(idx < k && idx < N){
		prevTime = min(prevTime, w[idx]);
		pq.push(make_tuple(w[idx], idx, id[idx]));
		idx++;
	}
	
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		ll time, num, userId;
		tie(time, num, userId) = f;
		
		if(time != prevTime){
			prevTime = time;
			
			sort(v.begin(), v.end(), greater<pair<ll,ll>>());
			for(ll i = 0; i < v.size(); i++){
				ret_list.push_back(v[i].second);
			}
			v.clear();
		}
		
		if(idx < N){
			pq.push(make_tuple(time + w[idx], num, id[idx]));
			idx++;
		}
		v.push_back({num, userId});
	}
	
	sort(v.begin(), v.end(), greater<pair<ll,ll>>());
	for(ll i = 0; i < v.size(); i++){
		ret_list.push_back(v[i].second);
	}
	v.clear();
	
	for(ll i = 0; i < N; i++){
		//cout << ret_list[i] << " ";
		ret += (i+1) * ret_list[i];
	}
	
	cout << ret;
}