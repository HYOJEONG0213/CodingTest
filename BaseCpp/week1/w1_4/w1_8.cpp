#include <iostream>
using namespace std;

int main(){
	int a;
	cin >> a;
	if(a > 5){
		for(int i = 1; i <= 10; i++) cout << i << "\n";
	}
	else{
		for(int i = 5; i >= 1; i--) cout << i << "\n";
	}
}

