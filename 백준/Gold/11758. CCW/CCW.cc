#include <bits/stdc++.h>
using namespace std;

#define y1 yyyy

typedef pair<int,int> pp;
int x1, y1, x2, y2, x3, y3;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> x1 >> y1 ;
	cin >> x2 >> y2 ;
	cin >> x3 >> y3 ;
	
	int vx = x2-x1;
	int vy = y2-y1;
	int ux = x3-x2;
	int uy = y3-y2;
	
	int temp = vx*uy - vy*ux;
	if(temp > 0){
		cout << 1;
	}
	else if(temp < 0){
		cout << -1;
	}
	else{
		cout << 0;
	}
} 