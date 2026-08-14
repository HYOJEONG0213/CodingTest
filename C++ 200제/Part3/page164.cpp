#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string myPet = "Rabbit";
	string yourPet = "Cat";
	string const *p1 = &myPet;
	cout << *p1 << "\n";
	
	string *const p2 = &myPet;
	*p2 = "Dog";
	cout << *p2;
}
