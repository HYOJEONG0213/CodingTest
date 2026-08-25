#include <bits/stdc++.h>
#include <atomic>
using namespace std;

enum State{
	kOpen,
	kClose,
	kDisconnect
};

typedef State state_;

struct Status{
	state_ machine1;
	state_ machine2;
} status_;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	status_.machine1 = kOpen;
	status_.machine2 = kClose;
	
	cout << status_.machine1 << " " << status_.machine2;
}
