#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pp;
int N, M, l[14], r[14], c[14], a;
priority_queue <pp, vector<pp>, greater<pp>> pq;
vector <int> A, uniA, sortA;
map <ll, ll> mp;

ll pack(const vector <int> &v){
	ll res = 0;
	for(int i = 1; i <= N; i++) res = res*10 + v[i];
	return res;
}

vector <int> unpack(ll state){
	vector <int> v(N+1);
	for(int i = N; i > 0; i--){
		v[i] = state % 10;
		state /= 10;
	}
	return v;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(N+1);
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		uniA.push_back(A[i]);
	}
	
	sort(uniA.begin(), uniA.end());
	uniA.erase(unique(uniA.begin(), uniA.end()), uniA.end());
	for(int i = 1; i <= N; i++){
		A[i] = lower_bound(uniA.begin(), uniA.end(), A[i]) - uniA.begin();
	}
	
	sortA = A;
	sort(sortA.begin()+1, sortA.end());
	ll target = pack(sortA);
	
	cin >> M;
	for(int i = 1; i <= M; i++){
		cin >> l[i] >> r[i] >> c[i];
	}
	
	ll s = pack(A);
	mp[s] = 0;
	
	pq.push({0, s});
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		ll herecost, here;
		tie(herecost, here) = f;
		
		if(here==target){
			cout << herecost;
			return 0;
		}
		
		if(mp[here] < herecost) continue;
		
		vector <int> v = unpack(here);
		for(int i = 1; i <= M; i++){
			vector <int> vv = v;
			swap(vv[l[i]], vv[r[i]]);
			ll next = pack(vv);
			ll nextcost = herecost + c[i];
			
			if(mp[next]==0 || mp[next] > nextcost){
				mp[next] = nextcost;
				pq.push({herecost+c[i], next});
			}
		}
	}
	
	cout << "-1";
}