#include <bits/stdc++.h>
using namespace std;

int Plus(int a, int b){
	return a+b;
}
double Plus(double a, double b, double c){
	return a+b+c;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << Plus(1, 2) << " " << Plus(1.1, 2.2, 3.3);
}
