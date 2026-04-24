#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Dot{
	ll x, y;
	bool operator <(const Dot &other){
		if(y == other.y) return x < other.x;
		return y < other.y;
	}
};

Dot pivot;

ll N, L;
double ret;
vector <Dot> v;
stack <Dot> stk;

ll getCCW(Dot &a, Dot &b, Dot &c){
	return a.x*b.y+b.x*c.y+c.x*a.y - (a.x*c.y+c.x*b.y+b.x*a.y);
}

ll getdir(Dot &a, Dot &b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}


bool compare(Dot &a, Dot &b){
	ll ccw = getCCW(pivot, a, b);
	if(ccw != 0) return ccw > 0;
	return getdir(pivot, a) < getdir(pivot, b);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	vector <Dot> dot(N);
	for(int i = 0; i < N; i++){
		cin >> dot[i].x >> dot[i].y;
	}
	sort(dot.begin(), dot.end());
	
	pivot = dot[0];
	sort(dot.begin(), dot.end(), compare);
	
	stk.push(dot[0]);
	stk.push(dot[1]);
	
	// 볼록 다각형 만들기
	for(int i = 2; i < dot.size(); i++){
		while(stk.size()>=2){
			Dot first = stk.top(); stk.pop();
			Dot second = stk.top();
			
			if(getCCW(second, first, dot[i]) > 0){
				stk.push(first);
				break;
			}
		}
		stk.push(dot[i]);
	} 
	stk.push(pivot);
	while(stk.size()){
		v.push_back(stk.top());
		stk.pop();
	}
	
	for(int i = 0; i < v.size()-1; i++){
		ret += sqrt(getdir(v[i], v[i+1]));
	}
	ret += 2*3.141592*L;
	
	cout << round(ret);
}