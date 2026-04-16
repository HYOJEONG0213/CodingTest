#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pp;

struct Point {
    ll x, y;
};

ll N, a, b;
Point pivot;
vector <Point> v, stk;

int getccw(Point p1, Point p2, Point p3) {
    ll temp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    if (temp > 0) return 1; 
    if (temp < 0) return -1; 
    return 0;                
}

ll dist(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool compare(const Point &a, const Point &b) {
    int ccw = getccw(pivot, a, b);
    if (ccw != 0) return ccw > 0; 
    return dist(pivot, a) < dist(pivot, b); 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		v.push_back({b, a});
	}
	
	for(int i = 0; i < N; i++){
		if (v[i].y < v[0].y || (v[i].y == v[0].y && v[i].x < v[0].x)) {
            swap(v[0], v[i]);
        }
	}
	
	pivot = v[0];
	
	sort(v.begin()+1, v.end(), compare);
	
	stk.push_back(v[0]);
    stk.push_back(v[1]);
	
	for(int i = 2; i < N; i++){
		while(stk.size() >= 2){
			Point second = stk.back();
            stk.pop_back();
            Point first = stk.back();
				
			if (getccw(first, second, v[i]) > 0) {
                stk.push_back(second);
                break;
            }
			//오목한 점은 버릴거임  
		}
		
		stk.push_back(v[i]);
	}
	
	cout << stk.size();
}