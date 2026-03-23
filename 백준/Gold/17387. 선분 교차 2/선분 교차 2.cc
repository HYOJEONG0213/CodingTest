#include <bits/stdc++.h>
using namespace std;
#define y1 yyyyy

typedef long long ll; 
typedef pair<ll, ll> pp;
pp p1,p2,p3,p4;

int ccw(pp a1, pp a2, pp a3){
    ll cross_product 
	= (a1.first * a2.second + a2.first * a3.second + a3.first * a1.second) 
    - (a2.first * a1.second + a3.first * a2.second + a1.first * a3.second);
    
	if (cross_product > 0) return 1;
    if (cross_product < 0) return -1;
    return 0;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;
    
    
	ll cross1 = ccw(p1, p2, p3);
	ll cross2 = ccw(p1, p2, p4);
	
	ll cross3 = ccw(p3, p4, p1);
	ll cross4 = ccw(p3, p4, p2);
	
	ll temp1 = cross1*cross2;
	ll temp2 = cross3*cross4;
	
	
	if(temp1 > 0 || temp2 > 0){
		cout << 0;
		return 0;
	}
	else if(temp1 == 0 && temp2 == 0){
		// 비교 
		if(p1 > p2) swap(p1, p2);
		if(p3 > p4) swap(p3, p4);
		
		if(p1 <= p4 && p3 <= p2){
			cout << 1;
			return 0;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	else if(temp1 <= 0 || temp2 <= 0){
		cout << 1;
		return 0;
	}
	else{
		cout << 0;
		return 0;
	}
}