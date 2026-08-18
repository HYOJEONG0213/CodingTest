#include <bits/stdc++.h>
using namespace std;

int Plus(int a = 3, int b = 5, int c = 5){
	return a+b+c;
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << Plus() << "\n";
	cout << Plus(10,10) << "\n";
	cout << Plus(10,10,10);
}
