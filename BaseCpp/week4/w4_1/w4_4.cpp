#include <iostream>
using namespace std;

void KFC(int* upper, int* lower)
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isupper(s[i])) (*upper)++;
		else (*lower)++;
	}
}

int main() {
	int upper = 0, lower = 0;
	KFC(&upper, &lower);
	cout << upper << " " << lower;
}
