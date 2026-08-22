#include <bits/stdc++.h>
using namespace std;

template <class T>
class Test{
public:
	void get(T t){
		this->t = t;
	}
	
	void print(){
		cout << t << "\n";
	}
	
private:
	T t;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test<int> test1;
	test1.get(1);
	test1.print();
	
	test1.get(2);
	test1.print();
	
	Test<string> test2;
	test2.get("Hello");
	test2.print();
	
	test2.get("World");
	test2.print();
	
	test2.get("!!");
	test2.print();
}
