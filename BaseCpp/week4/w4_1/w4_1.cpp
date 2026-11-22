#include <iostream>
using namespace std;

void ABC(int a, int b, int *sum , int *gop){
	*sum = a+b;
	*gop = a*b;
}


int main(){
	int a, b;
	cin >> a >> b;
	int sum=0, gop = 0;
	ABC(a, b, &sum, &gop);
	cout << sum << " " << gop;
}
