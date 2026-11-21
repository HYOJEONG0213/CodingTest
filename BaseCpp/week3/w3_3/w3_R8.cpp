#include <iostream>
using namespace std;

string s = "StructPointer";
char c;
bool flag = false;

int main(){
	cin >> c;
	for(int i = 0 ; i < s.size(); i++){
		if(s[i]==c) {
			flag = true;
			break;
		}
	}
	
	cout << (flag ? "발견" : "미발견");
}
