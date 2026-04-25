#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll C;

struct Dot{
	ll x, y;
	// 왼쪽 아래에서 시작해서 반시계 방향으로 할거임  
	bool operator <(const Dot &other) const{
		if(y==other.y) return x < other.x;
		return y < other.y;
	}
};

Dot pivot;
stack <Dot> stk;
ll mx;

ll getccw(Dot &a, Dot &b, Dot &c){
	return a.x*b.y + b.x*c.y + c.x*a.y - (a.x*c.y + c.x*b.y + b.x*a.y);
}

ll getdist(Dot &a, Dot &b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool compare(Dot &a, Dot &b){
	ll ccw = getccw(pivot, a, b);
	if(ccw != 0) return ccw > 0; // 반시계!! 
	return getdist(pivot, a) < getdist(pivot, b);
}

ll getccwV(Dot &a, Dot &b, Dot &c, Dot &d){
	Dot v1 = {b.x - a.x, b.y - a.y};
	Dot v2 = {d.x - c.x, d.y - c.y};
	return v1.x * v2.y - v1.y * v2.x;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> C;
	vector <Dot> dot(C);
	for(int i = 0; i < C; i++){
		cin >> dot[i].x >> dot[i].y;
	}
	sort(dot.begin(), dot.end());
	pivot = dot[0];
	sort(dot.begin()+1, dot.end(), compare);
	
	stk.push(dot[0]);
	stk.push(dot[1]);
	for(int i = 2; i < dot.size(); i++){
		while(stk.size() >= 2){
			Dot second = stk.top(); stk.pop();
			Dot first = stk.top();
			if(getccw(first, second, dot[i]) > 0){
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
	int j = 1;
	int sz = v.size();
	for(int i = 0; i < sz; i++) {
		int ni = (i + 1) % sz;
		while(1){
			int nj = (j+1) % sz;
			if(getccwV(v[i], v[ni], v[j], v[nj]) > 0){
				j = nj;
			}
			else{
				break;
			}
		}
		mx = max(mx, getdist(v[i], v[j]));
	}
	
	double ret = (double) mx;
	cout << fixed << setprecision(6) << sqrt(ret);
}