#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Dot{
	ll x, y;
	bool operator<(const Dot &other){
		if(y==other.y) return x < other.x;
		return y < other.y;
	}
};
Dot pivot, ret1, ret2;
ll T, n;


ll dist(Dot &a, Dot &b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

ll getccw(Dot &a, Dot &b, Dot &c){
	return a.x*b.y+b.x*c.y+c.x*a.y-(a.x*c.y+c.x*b.y+b.x*a.y);
}

bool compare(Dot &a, Dot &b){
	ll ccw = getccw(pivot, a, b);
	if(ccw != 0) return ccw > 0;	// 시계반대방향
	return dist(pivot, a) < dist(pivot, b); 
}

ll Vecccw(Dot &a, Dot &b, Dot &c, Dot &d){
	Dot A, B;
	A = {b.x-a.x, b.y-a.y};
	B = {d.x-c.x, d.y-c.y};
	return A.x*B.y-B.x*A.y;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		ll ret=0; 
		
		cin >> n;
		vector <Dot> dot(n);
		for(int i = 0; i < n; i++){
			cin >> dot[i].x >> dot[i].y;
		}
		sort(dot.begin(), dot.end());
		pivot = dot[0];
		sort(dot.begin()+1, dot.end(), compare);
		
		// 최대 볼록 다각형 그리기  
		stack <Dot> stk;
		stk.push(dot[0]);
		stk.push(dot[1]);
		for(int i = 2; i < n; i++){
			while(stk.size() >= 2){
				Dot second = stk.top();
				stk.pop();
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
		
		// 회전하는 캘리퍼스 
		int j = 1;
		int sz = v.size();
		for(int i = 0; i < sz; i++){
			while(1){
				// sin a > 0 : 180도 이하다  
				if(Vecccw(v[i], v[(i+1)%sz], v[j%sz], v[(j+1)%sz]) > 0){
					j++;
				}
				else{
					break;
				}
			}
			ll temp =dist(v[i], v[j%sz]);
			if(ret < temp){
				ret = temp;
				ret1 = v[i];
				ret2 = v[j%sz];
			}
		} 
		
		cout << ret1.x << " " << ret1.y << " " << ret2.x << " " << ret2.y << "\n";
	}
}