#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	stringstream ss;
	double a = 0.0;
	ss << "1.2,2.6-3.8!4.7=8.9";
	
	while(!ss.eof()){
		ss >> a;
		cout << a << " ";
		ss.ignore();
	}
	cout << "\n\n";
	
	ss.clear();
	ss.str("");
	ss << "1," << "2" << 3 << " " << 4;
	
	int b = 0;
	
	while(!ss.eof()){
		ss >> b;
		cout << b << " ";
		ss.ignore();
	}
}
