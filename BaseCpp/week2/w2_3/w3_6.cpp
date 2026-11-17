#include <iostream>
using namespace std;

int a; 

int main(){
	for(int i = 0 ; i < 4; i++){
		cin >> a;
		if(a < 20){
			cout << "더 큰 수를 입력하세요\n";
		}
		else if(a > 20){
			cout << "더 작은 수를 입력하세요\n";
		}
		else if(a==20){
			cout << "정답입니다.\n";
		}
	}
}

