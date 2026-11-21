#include <iostream>
using namespace std;

int Input(){
	int a;
	cin >> a;
	return a;
}
void CountDown(int a){
	while(a >= 1) cout << a-- << " ";	
}

int main(){
	CountDown(Input());
}
