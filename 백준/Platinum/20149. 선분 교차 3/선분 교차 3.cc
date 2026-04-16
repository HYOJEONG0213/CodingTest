#include <bits/stdc++.h>
using namespace std;

#define y1 yyyy
typedef long long ll;

struct Point{
	ll x, y;
	
	bool operator < (const Point &p) const{
		if(x == p.x) return y < p.y;
		return x < p.x;
	}
	bool operator <= (const Point &p) const{
		if(x == p.x) return y <= p.y;
		return x <= p.x;
	}
	bool operator == (const Point &p) const{
		return x == p.x && y == p.y;
	}
};

ll x1, y1, x2, y2, x3, y3, x4, y4;
Point p1, p2, p3, p4;

int getccw(Point a, Point b, Point c){
	ll temp = a.x*b.y + b.x*c.y + c.x*a.y - (a.x*c.y + c.x*b.y + b.x*a.y);
	if(temp < 0) return -1;
	if(temp > 0) return 1;
	return 0;	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	p1 = {x1, y1};
	p2 = {x2, y2};
	p3 = {x3, y3};
	p4 = {x4, y4};
	
	int ccw1 = getccw(p1, p2, p3);
	int ccw2 = getccw(p1, p2, p4);
	int ccw3 = getccw(p3, p4, p1);
	int ccw4 = getccw(p3, p4, p2);
	
	int temp1 = ccw1 * ccw2, temp2 = ccw3 * ccw4;
	
	if(temp1 > 0 || temp2 > 0){
		cout << 0;
		return 0;
	}
	
	if(ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0){
		if(p2 < p1) swap(p1, p2);
		if(p4 < p3) swap(p3, p4);
		
		if(p1 <= p4 && p3 <= p2){
			cout << 1 << "\n";
			
			if(p2 == p3){
				cout << p2.x << " " << p2.y;
			}
			else if(p1 == p4){
				cout << p1.x << " " << p1.y ;
			}
			
			return 0 ;
		}
		
		cout << 0;
		return 0;
	}
	
	if(temp1 <= 0 && temp2 <= 0){
		ll a1 = p2.y - p1.y;
		ll b1 = p1.x - p2.x;
		ll c1 = a1 * p1.x + b1 * p1.y;
		
		ll a2 = p4.y - p3.y;
		ll b2 = p3.x - p4.x;
		ll c2 = a2 * p3.x + b2 * p3.y;
		
		ll det = a1*b2 - b1*a2;
		double x = (double)(c1*b2 - b1*c2) / det;
		double y = (double)(a1*c2 - c1*a2) / det;
		
		cout << "1 \n";
		cout << fixed;
		cout.precision(9);
		cout << x << " " << y ;
		
		
		
		return 0;
	}
	
	cout << 0;
	return 0;
}