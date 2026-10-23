#include "iostream"
using namespace std;

int main(){
	int a, x;
	cin >> a >> x;
	for(int i = a-1; i >= a-x; i--) cout << i << " "; 
}

