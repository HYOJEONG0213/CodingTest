#include <iostream>
using namespace std;

int score;

int main(){
	cin >> score;
	if(score >= 80) cout << "수";
	else if(score >= 70) cout << "우";
	else if(score >= 60) cout << "미";
	else cout << "재시도";
}
