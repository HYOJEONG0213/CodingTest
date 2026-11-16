#include <iostream>
using namespace std;

int arr[6], a;

int main(){
	cin >> arr[0] >> arr[1] >> arr[2];
	cin >> a;
	for(int i = 3; i < 6; i++)
		arr[i] = a++;
		
	for(int i = 0 ; i < 6 ; i++) cout << arr[i] << " ";
}
