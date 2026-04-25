#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
struct Dot{
	ll x, y;
	
	bool operator <(const Dot &other) const{
		if(y == other.y) return x < other.x;
		return y < other.y;
	}
};

Dot pivot;
stack <Dot> stk;

ll getccw(Dot &a, Dot &b, Dot &c){
	return a.x*b.y + b.x*c.y + c.x*a.y - (a.x*c.y + c.x*b.y + b.x*a.y);
}

ll dist(Dot &a, Dot &b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool compare(Dot &a, Dot &b){
	ll ccw = getccw(pivot, a, b);
	if(ccw!=0) return ccw < 0;	// 반시계
	return dist(pivot, a) < dist(pivot, b); 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vector <Dot> dot(n);
	for(int i = 0; i < n; i++){
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
	ll ret = 0;
	for(int i = 2; i < v.size(); i++){
		Dot second = v[i];
		Dot first = v[i-1];
		ret += abs(getccw(pivot, first, second));
	}
	
	cout << ret/100;
}