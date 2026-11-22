#include <iostream>
using namespace std;

int arr[7] = {4,2,5,1,6,7,3};
char ch1, ch2;

int main(){
	cin >> ch1 >> ch2;
	int ch1Idx = ch1 - 'A';
	int ch2Idx = ch2 - 'A';
	int sum = 0;
	if(ch1Idx > ch2Idx) swap(ch1Idx, ch2Idx);
	for(int i = ch1Idx+1; i < ch2Idx ; i++) sum += arr[i];
	
	cout << sum;
	
}
