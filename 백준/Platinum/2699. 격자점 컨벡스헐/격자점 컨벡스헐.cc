#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Dot{
	ll x, y;
	
	bool operator <(const Dot &other) const{
		if(y == other.y) return x < other.x;
		return y > other.y;
	}
};

Dot pivot;


ll T, N;
stack <Dot> stk;

ll getCCW(Dot &a, Dot &b, Dot &c){
	return a.x*b.y + b.x*c.y + c.x*a.y - (a.x*c.y + c.x*b.y + b.x*a.y);
}

ll getDist(Dot &a, Dot &b){
	return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}

bool compare(Dot &a, Dot &b){
	ll ccw = getCCW(pivot, a, b);
	if(ccw != 0) return ccw < 0;
	return getDist(pivot, a) < getDist(pivot, b);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		cin >> N;
		vector <Dot> dot(N);
		for(int i = 0; i < N; i++){
			cin >> dot[i].x >> dot[i].y; 
		}
		sort(dot.begin(), dot.end());
		pivot = dot[0];
		sort(dot.begin()+1, dot.end(), compare);
		
		stk.push(dot[0]);
		stk.push(dot[1]);
		
		for(int i = 2; i < N; i++){
			while(stk.size() >= 2){
				Dot pre1 = stk.top();
				stk.pop();
				Dot pre2 = stk.top();
				
				if(getCCW(pre2, pre1, dot[i]) < 0){
					stk.push(pre1);
					break;
				}
			}
			stk.push(dot[i]);
		}
		
		cout << stk.size() << "\n";
		vector <Dot> ret;
		while(stk.size()){
			ret.push_back(stk.top());
			stk.pop();
		}
	
		reverse(ret.begin(), ret.end());
		
		for(int i = 0; i < ret.size() ; i++){
			cout << ret[i].x << " " << ret[i].y << "\n";
		}
	}
}