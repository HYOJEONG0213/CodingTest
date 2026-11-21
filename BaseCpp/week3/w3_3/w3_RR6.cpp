#include <iostream>
using namespace std;

struct BBQ{
	int x, data[3];
};

BBQ g;

int main(){
	cin >> g.x;
	cin >> g.data[0] >> g.data[1] >> g.data[2];
	int sum = 0;
	for(int i = 0 ; i < 3; i++){
		sum += g.data[i];
	}
	cout << sum << " " << g.x;
}
