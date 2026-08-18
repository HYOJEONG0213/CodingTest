#include <bits/stdc++.h>
using namespace std;

class School{
public:
	virtual int Plus(int a, int b){
		cout << "학교입니당";
		return a+b;
	}
};

class MiddleSchool : School{
public:
	int Plus(int a, int b) override{
		cout << "중학교입니당";
		return a+a+b+b;
	}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	School school;
	cout << school.Plus(2, 3) << "\n";
	
	MiddleSchool middle;
	cout << middle.Plus(2, 3);
}
