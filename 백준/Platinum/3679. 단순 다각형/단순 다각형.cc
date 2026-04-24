#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Dot{
	ll x, y, idx;
	
	bool operator <(const Dot &other) const{
		if(y == other.y){
			return x < other.x;
		}
		return y < other.y;
	}
} ;


Dot pivot;
ll T, N; 

ll getCCW(Dot &a, Dot &b, Dot &c){
	return a.x*b.y + b.x*c.y + c.x*a.y - (a.x*c.y + c.x*b.y + b.x*a.y);
}

ll getDist(Dot a, Dot b){
	return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
}

bool compare(Dot a, Dot b){
	ll ccw = getCCW(pivot, a, b);
	
	if(ccw != 0){
		return ccw > 0;
	}
	
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
			dot[i].idx = i;
		}
		
		sort(dot.begin(), dot.end());
		pivot = dot[0];
		sort(dot.begin()+1, dot.end(), compare);
		
		int i = N-1;
		while(i > 1 && getCCW(pivot, dot[N-1], dot[i-1]) == 0){
			i--;
		}
		
		reverse(dot.begin()+i, dot.end());
		
		for(auto i : dot){
			cout << i.idx << " ";
		}
		cout << "\n";
	} 
}