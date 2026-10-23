#include "iostream"
using namespace std;


int main(){
	int a,b,c,d;
	
	cin >> a >> b >> c>> d;
	int avg = (a+b+c+d)/4;
	
	if(a > avg){
		cout << a << ">" << avg<<"\n";
	}
	else if(a==avg){
		cout << a << "==" << avg<<"\n";
	}
	else{
		cout << a << "<" << avg<<"\n";
	}
	
	if(b > avg){
		cout << b << ">" << avg<<"\n";
	}
	else if(b==avg){
		cout << b << "==" << avg<<"\n";
	}
	else{
		cout << b << "<" << avg<<"\n";
	}
	
	if(c > avg){
		cout << c << ">" << avg<<"\n";
	}
	else if(c==avg){
		cout << c << "==" << avg<<"\n";
	}
	else{
		cout << c << "<" << avg<<"\n";
	}
	
	if(d > avg){
		cout << d << ">" << avg<<"\n";
	}
	else if(a==avg){
		cout << d << "==" << avg<<"\n";
	}
	else{
		cout << d << "<" << avg<<"\n";
	}
}
