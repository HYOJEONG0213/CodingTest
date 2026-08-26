#include <bits/stdc++.h>
using namespace std;

int GetInt() {
	return 1;
}
double GetDouble(){
	return 1.1;
}
string GetString(){
	return "Rabbit";
}
auto add(int x, int y)->int{
	return x+y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	auto t1 = GetInt();
	auto t2 = GetDouble();
	auto t3 = GetString();
	auto t4 = add(5,4);
	
	cout << typeid(t1).name() << " " << typeid(t2).name() << " " << typeid(t3).name() << " " << typeid(t4).name();
}
