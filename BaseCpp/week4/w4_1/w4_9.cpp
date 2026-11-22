#include <iostream>
using namespace std;

int arr[3][3] = {'D','A','S','Q','W','V', 'R','T','Y'};

int Find(int y, int x){
	return arr[y][x];
}

int main(){
	int y1, x1, y2, x2;
	cin >> y1 >> x1;
	cin >> y2 >> x2;
	cout << (char)Find(y1, x1) << " ";
	cout << (char)Find(y2, x2);
}
