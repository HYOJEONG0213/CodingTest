#include <bits/stdc++.h>
using namespace std;

struct Animal{
	string a ;
	string b ;
	string c ;
} ;

void f(Animal *A){
	cout << A->a << " " << A->b << " " << A->c << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Animal animal;
	animal.a = "¿ø¼þÀÌ"; animal.b = "½Ò½Ò"; animal.c = "¿ì¿ì";
	f(&animal);
}
