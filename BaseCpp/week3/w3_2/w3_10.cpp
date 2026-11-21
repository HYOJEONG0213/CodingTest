#include <iostream>
using namespace std;

char arr[5];

void checkChar(char c){
	if(isupper(c)) cout << "´ë";
	else cout << "¼Ò";
}

int main(){
	for(int i = 0; i < 5; i++) cin >> arr[i];
	for(int i = 0;  i <5; i++){
		checkChar(arr[i]);
	}
}
