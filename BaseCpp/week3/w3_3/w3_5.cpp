#include <iostream>
using namespace std;

int GOP(){
	int a, b;
	cin >> a >> b;
	return a*b;
}

int SUM(){
	int a, b;
	cin >> a >> b;
	return a+b;
}

int main(){
	int a = GOP();
	int b = SUM();
	cout << "GOP" ;
	if(a>b){
		cout << ">";
	}
	else if(a==b){
		cout << "==";
	}
	else cout << "<"; 
	cout << "SUM";
}
