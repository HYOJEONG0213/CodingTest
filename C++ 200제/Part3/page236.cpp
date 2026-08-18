#include <bits/stdc++.h>
using namespace std;

class Building{
public:
	void Test1(){
		cout << "빌딩을 가진다!" << "\n";
	}
};

class Tenant{
public:
	void Test2(){
		cout <<  "세입자다! \n";
	}
};

class Everyone : Building, Tenant{
public:
	void Who(){
		if(bOwner==true){
			Test1();
		}
		else{
			Test2();
		}
	}
	
public:
	bool bOwner	;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Everyone every;
	every.bOwner = true;
	every.Who();
}
