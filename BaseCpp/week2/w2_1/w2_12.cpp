#include <iostream>
using namespace std;

int arr[3], sum;

void QTR(){
	cout << "QTR100%";
}

void BBQ(){
	cout << "BBQ100%";
}


int main(){
	for(int i = 0 ; i < 3; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	
	if(sum >= 10) QTR();
	else BBQ();
}
