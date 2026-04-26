#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N;

struct Dot{
	ll x, y;
	
	bool operator<(const Dot &other) const{
		if(y == other.y) return x < other.x;
		return y < other.y;
	}
};
Dot pivot;

ll getccw(Dot &a, Dot &b, Dot &c){
	return a.x*b.y+b.x*c.y+c.x*a.y - (a.x*c.y+c.x*b.y+b.x*a.y);
}

ll getdist(Dot &a, Dot &b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

ll getVecCcw(Dot &a, Dot &b, Dot &c, Dot &d){
	Dot V1, V2;
	V1.x = (b.x-a.x);
	V1.y = (b.y-a.y);
	V2.x = (d.x-c.x);
	V2.y = (d.y-c.y);
	
	return V1.x*V2.y - V2.x*V1.y;
}

bool compare(Dot &a, Dot &b){
	ll ccw = getccw(pivot, a, b);
	if(ccw != 0) return ccw < 0;	// 시계방향 
	return getdist(pivot, a) < getdist(pivot, b); 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector <Dot> dot(N);
	for(int i = 0; i < N; i++){
		cin >> dot[i].x >> dot[i].y;
	}
	sort(dot.begin(), dot.end());
	pivot = dot[0];
	sort(dot.begin()+1, dot.end(), compare);
	
	stack <Dot> stk;
	stk.push(dot[0]);
	stk.push(dot[1]);
	for(int i = 2; i < N; i++){
		while(stk.size() >= 2){
			Dot second = stk.top(); stk.pop();
			Dot first = stk.top();
			
			// 시계방향 탐색  
			if(getccw(first, second, dot[i]) < 0){
				stk.push(second);
				break;
			}
		}
		stk.push(dot[i]);
	}
	
	vector <Dot> v;
	while(stk.size()){
		v.push_back(stk.top()); stk.pop();
	}
	reverse(v.begin(), v.end());
	
	
	// 회전하는 캘리퍼스 ㄱㄱ
	ll j = 1;
	ll mx = 0;
	ll sz = v.size(); 
	for(int i = 0 ; i < sz; i++){
		while(1){
			// sin a < 0 : 180도 초과  
			if(getVecCcw(v[i], v[(i+1)%sz], v[j%sz], v[(j+1)%sz]) < 0){
				j++;
				mx = max(mx, getdist(v[i], v[j%sz]));
			}
			else{
				break;
			}
		}
		mx = max(mx, getdist(v[i], v[j%sz]));
	} 
	
	cout << mx;
}