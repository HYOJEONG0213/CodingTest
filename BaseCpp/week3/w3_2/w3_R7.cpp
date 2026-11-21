#include <iostream>
using namespace std;

struct PROJECT{
	int num;
	char id;
	int vect[4];
};

PROJECT z;

int a;

int main(){
	cin >> a;
	if(a < 10){
		z.num = 5;
		z.id = 'G';
		z.vect[0] = 1;
		z.vect[1] = 2;
		z.vect[2] = 3;
		z.vect[3] = 4;
	}
	else if(a < 100){
		z.num = 8;
		z.id = 'T';
		z.vect[0] = 5;
		z.vect[1] = 1;
		z.vect[2] = 2;
		z.vect[3] = 3;
	}
	else if(a >= 100){
		z.num = 10;
		z.id = 'Q';
		z.vect[0] = 9;
		z.vect[1] = 1;
		z.vect[2] = 6;
		z.vect[3] = 2;
	}
	cout << z.num << "\n" << z.id << "\n";
	for(int i = 0 ; i < 4; i ++){
		cout << z.vect[i] << " ";
	} 
}
