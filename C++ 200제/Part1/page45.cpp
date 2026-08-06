#include <bits/stdc++.h>
using namespace std;

namespace t1{
	string country = "신라";
	int year = 935;
}
namespace t2{
	string country = "백제";
	int year = 660;
	
}
using namespace t1;
using namespace t2;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << t1::country << "중심지 : 경상도 \n";
	cout << t1::country << "멸망연도 : " << t1::year << "\n"; 
	
	cout << t2::country << "중심지 : 충청도 \n";
	cout << t2::country << "멸망연도 : " << t2::year << "\n"; 
 } 
