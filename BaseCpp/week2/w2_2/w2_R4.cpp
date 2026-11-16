#include <iostream>
using namespace std;

char input;

int main(){
	cin >> input;
	if(input >= 'a' && input <= 'z') cout << "소문자 입력";
	else if(input >= 'A' && input <= 'Z') cout << "대문자 입력";
	else if(input >= '0' && input <= '9') cout <<"숫자문자입력";
}
