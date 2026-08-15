#include <bits/stdc++.h>
using namespace std;

struct Test{
	string a ;
	string b ;
	string c ;
} Animal[2];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test test;
	test.a = "¿ø¼şÀÌ"; test.b = "½Ò½Ò"; test.c = "¿ì¿ì";
	cout << test.a << " " << test.b << " " << test.c << "\n";
	
	Animal[0].a = "Åä³¢"; Animal[0].b = "°í¾çÀÌ"; Animal[0].c = "°³";
	Animal[1].a = "bunny"; Animal[1].b = "cat"; Animal[1].c = "dog";
	for(int i = 0; i < 2; i++){
		cout << Animal[i].a << " " << Animal[i].b << " " << Animal[i].c << "\n";
	}
}
