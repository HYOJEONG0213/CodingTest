#include <bits/stdc++.h>
using namespace std;

enum ex{
	a = 10,
	b = 20,
	c = 30,
	close,
};

enum class Test : int{
	a = 10,
	b = 20,
	c = 30,
	close,
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << static_cast<int> (Test::close);
}
