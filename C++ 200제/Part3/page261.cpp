#include <bits/stdc++.h>
using namespace std;

void Print(int a, double b, string c){
	cout << a << " " << b << " " << c << "\n";
}

template <typename... T>
void Test(T... t){
	Print(t...);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test<int, double, string> (1, 2.2, "Rabbit");
}
