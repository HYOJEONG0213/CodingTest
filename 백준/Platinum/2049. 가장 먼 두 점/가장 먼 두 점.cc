#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, mx;

struct Dot{
	ll x, y;
	bool operator<(const Dot &other){
		if(y==other.y) return x < other.x;
		return y < other.y;
	}
};

Dot pivot;

ll getccw(Dot &a, Dot &b, Dot &c){
	return a.x*b.y+b.x*c.y+c.x*a.y - (a.x*c.y+c.x*b.y+b.x*a.y);
}

ll getDist(Dot &a, Dot &b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

ll getccwVector(Dot &a, Dot &b, Dot &c, Dot &d){
	Dot v1, v2;
	v1.x = b.x - a.x;
	v1.y = b.y - a.y;
	v2.x = d.x - c.x;
	v2.y = d.y - c.y;
	return v1.x*v2.y - v2.x*v1.y;
}


bool compare(Dot &a, Dot &b){
	ll ccw = getccw(pivot, a, b);
	if(ccw != 0) return ccw > 0;	// 반시계 탐색  
	return getDist(pivot, a) < getDist(pivot, b);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vector <Dot> dot(n);
	for(int i = 0; i < n ; i++){
		cin >> dot[i].x >> dot[i].y;
	}
	sort(dot.begin(), dot.end());
	pivot = dot[0];
	sort(dot.begin()+1, dot.end(), compare);
	
	stack <Dot> stk;
	stk.push(dot[0]);
	stk.push(dot[1]);
	for(int i = 2; i < n; i++){
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
		v.push_back(stk.top());
		stk.pop();
	}
	reverse(v.begin(), v.end());
	
	// 투포인터처럼 하기  
	int j = 1;
	int sz = v.size();
	for(int i = 0; i < v.size(); i++){
		while(1){
			//sina > 0 : 180도 이하다 
			if(getccwVector(v[i], v[(i+1)%sz], v[(j)%sz], v[(j+1)%sz]) > 0){
				mx = max(mx, getDist(v[i], v[j%sz]));
				j++;
			}
			else{
				break;
			}
		}
		mx = max(mx, getDist(v[i], v[j%sz]));
	}
	
	cout << mx;
}