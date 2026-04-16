#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pp;
ll N, a, b, sy, sx;
vector <pp> v;
stack <pp> stk;

int getccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
	ll temp = x1*y2 + x2*y3 + x3*y1 - (x1*y3 + x3*y2 + x2*y1);
	if(temp < 0) return -1;
	if(temp == 0) return 0;
	if(temp > 0) return 1;
}

ll dist(ll x1, ll y1, ll x2, ll y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

bool compare(pp &a, pp &b) {
	int ccw = getccw(sx, sy, a.second, a.first, b.second, b.first);
	if(ccw != 0) return ccw > 0;	// 양수인것만 true  
	
	return dist(sx, sy, a.second, a.first) < dist(sx, sy, b.second, b.first);	//일직선 거리 짧은것순 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		v.push_back({b, a});
	}
	
	for(int i = 0; i < N; i++){
		if(v[i].first < v[0].first || (v[i].first == v[0].first && v[i].second < v[0].second)) {
			swap(v[0], v[i]);
		}
	}
	
	tie(sy, sx) = v[0];
	
	sort(v.begin()+1, v.end(), compare);
	
	stk.push({v[0].first, v[0].second});
	stk.push({v[1].first, v[1].second});
	
	for(int i = 2; i < N; i++){
		ll herey, herex;
		tie(herey, herex) = v[i];
		
		while(stk.size() >= 2){
			auto f = stk.top(); stk.pop();	
			ll secondy, secondx;
			tie(secondy, secondx) = f;
			
			f = stk.top();;	
			ll firsty, firstx;
			tie(firsty, firstx) = f;
				
			int ccw = getccw(firstx, firsty, secondx, secondy,  herex, herey);
			if(ccw > 0){
				stk.push({secondy, secondx});
				break;
			}
		}
		
		stk.push({herey, herex});
	}
	
	cout << stk.size();
}