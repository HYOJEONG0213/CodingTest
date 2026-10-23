#include "iostream"
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int ret;
	if(a > b) ret = a;
	else if(a < b) ret = b;
	else {
		cout << "같은숫자";
		return 0;
	}
	
	cout << "큰수는 "<< ret; 
}
