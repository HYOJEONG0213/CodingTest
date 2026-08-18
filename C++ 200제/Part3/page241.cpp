#include <bits/stdc++.h>
using namespace std;

class GoodKing;
class BadKing;

class Info{
	friend class GoodKing;
	
private:	
	string name;
};

class GoodKing : Info{
public:
	GoodKing(){
		name = "세종대왕";
	}
	
	void print(){
		cout << name << "\n";
	}
};


class BadKing : Info{
public:
	BadKing(){
		//name = "연산군";
	}
};



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	GoodKing good;
	good.print();
}
