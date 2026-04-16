#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pp;
typedef long long ll;
const ll INF = 1e18;
struct Point{
	int x, y;
};

bool compX(const Point& a, const Point& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

struct CompY{
	bool operator()(const Point& a, const Point& b) const {
	    if (a.y == b.y) return a.x < b.x;
	    return a.y < b.y;
	}
}; 


ll N, a, b, mn = INF;
Point p[100004];
set<Point, CompY> s;

ll getdir(const Point &a, const Point &b){
	ll tempa = b.x - a.x;
	ll tempb = b.y - a.y;
	return tempa * tempa + tempb * tempb;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		p[i] = {a, b};
	}
	
	sort(p, p+N, compX);
	mn = getdir(p[0], p[1]);
	
	s.insert(p[0]);
	s.insert(p[1]);
	
	int start = 0;
	
	for(int i = 2; i < N; i++){
		Point here = p[i];
		
		// x축 기준 필터링  
		while(start < i){
			Point startP = p[start];
			ll dir = here.x - startP.x;
			
			// 가장 오래된 점과 나와의 위치보다 작은것들 삭제  
			if(dir * dir >= mn){
				s.erase(startP);
				start++;
			}
			else{
				break;
			}
		}
		
		//y축 기준 필터링
		int d = (int) sqrt(mn) + 1;	//반올림 해주고
		Point lowerP = {-100000, here.y - d};
		Point upperP = {100000, here.y + d};
		 
	 	auto lower = s.lower_bound(lowerP);
	 	auto upper = s.upper_bound(upperP);
		 
		 for(auto it=lower; it != upper; it++){
		 	ll dir = getdir(here, *it);
		 	mn = min(mn, dir);
		 } 
		
		s.insert(here);
	}
	
	
	cout << mn;
}