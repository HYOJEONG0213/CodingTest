#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, ret;

struct Dot{
	ll x, y, visited;
	
	bool operator<(const Dot &other) const{
		if(y==other.y) return x < other.x;
		return y < other.y;
	}
};
Dot pivot, P;

ll getccw(Dot &a, Dot &b, Dot &c){
	return a.x*b.y+b.x*c.y+c.x*a.y - (a.x*c.y+c.x*b.y+b.x*a.y);
}

ll getDist(Dot &a, Dot &b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool compare(Dot &a, Dot &b){	
	ll ccw = getccw(pivot, a, b);
	if(ccw != 0) return ccw > 0;	// 반시계 탐색 
	return getDist(pivot, a) < getDist(pivot, b); 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P.x >> P.y;
	vector <Dot> dot(N);
	for(int i = 0; i < N; i++){
		cin >> dot[i].x >> dot[i].y;
	}
	
	
	
	while(dot.size() >= 3){
		//볼록 껍질  
		sort(dot.begin(), dot.end());
		pivot = dot[0];
		sort(dot.begin()+1, dot.end(), compare);
		
		stack <Dot> stk;
		stk.push(dot[0]);
		stk.push(dot[1]);
		
		for(int i = 2; i < dot.size(); i++){
			while(stk.size()>=2){
				Dot second = stk.top(); stk.pop();
				Dot first = stk.top();
				if(getccw(first, second, dot[i]) > 0){
					stk.push(second);
					break;
				}
			}
			stk.push(dot[i]);
		}
		
		if(stk.size() < 3) break;
		
		vector <Dot> v;
		while(stk.size()){
			v.push_back(stk.top()); 
			stk.top().visited=1;
			stk.pop();
		}
		reverse(v.begin(), v.end());
		
		// 감옥 안에 있나 확인  
		bool flag = true;
		for(int i = 0; i < v.size(); i++){
			if(getccw(v[i], v[(i+1) % v.size()], P) <= 0){
				flag = false;
				break;
			}
		}
		if(flag==false) break;
		
		ret++;
		
		// 쓴거 제외시키기  
		vector <Dot> temp;
		for(int i = 0; i < dot.size(); i++){
			bool flag = true;
			for(int j = 0; j < v.size(); j++){
				if(dot[i].x==v[j].x && dot[i].y==v[j].y){
					flag = false;
					break;
				}
			}
			if(flag == false) continue;
			temp.push_back(dot[i]);
		}
		
		dot = temp;
		
	}
	
	cout << ret;
}