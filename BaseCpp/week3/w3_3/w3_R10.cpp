#include <iostream>
using namespace std;

int vect[2][5] = {3,2,6,2,4,1,4,2,6,5};

bool KFC(int target){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 5; j++){
			if(vect[i][j] == target) return true;
		}
	}
	return false;
}

int main(){
	int target;
	cin >> target;
	cout << (KFC(target) ? "값 존재" : "값 없음");
}
