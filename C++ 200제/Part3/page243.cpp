#include <bits/stdc++.h>
using namespace std;

class Bank{
public:
	friend void getNum(Bank bank){
		cout << bank.password;
	}
	void SetNum(string s){
		password = s;
	}
	
private: 
	string password;
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Bank b;
	b.SetNum("1234kr");
	getNum(b);
}
