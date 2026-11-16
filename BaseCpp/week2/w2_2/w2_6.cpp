#include <iostream>
using namespace std;

char a;

int main(){
	cin >> a;
	if (a >= 'A' && a <= 'Z') cout << "대문자입니다.";
	else if (a >= 'a' && a <= 'z') cout << "소문자입니다.";
}
