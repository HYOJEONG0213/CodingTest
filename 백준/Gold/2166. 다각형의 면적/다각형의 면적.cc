#include <bits/stdc++.h>
using namespace std;

int N, x[200004], y[200004];
double ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x[i] >> y[i];
		x[i] += 100000;
		y[i] += 100000;
	}
	int sx = x[0], sy = y[0];
	
	//ax + by + c = 0
	//기울기 : -a/b = (y[i]-sy) / (x[i]-sx)
	for(int i = 2; i < N; i++){
		double a = (y[i]-sy);
		double b = -(x[i]-sx);
		double c = -(a*sx) - (b*sy);
		double h = (a * x[i-1] + b * y[i-1] + c) / sqrt(a*a + b*b);
		ret += h * sqrt(a*a+b*b) / 2;
		//cout << h * sqrt(a*a+b*b) / 2 << " ";
	}	
	
	cout << fixed << setprecision(1) << abs(ret);
}