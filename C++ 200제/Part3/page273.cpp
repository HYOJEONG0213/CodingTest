#include <bits/stdc++.h>
#include <thread>
using namespace std;


void f1(int t){
	this_thread::sleep_for(chrono::seconds(t));
	cout << t << "ÃÊ ´ë±â \n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	thread t1(f1, 3);
	thread t2(f1, 4);
	thread t3(f1, 5);
	
	t1.join();
	t2.join();
	t3.join();
}
