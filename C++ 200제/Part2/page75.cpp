#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	bitset<8> bit1;
	bit1.reset();
	bit1 = 127; // 0111 1111
	
	bitset<8> bit2;
	bit2.reset();
	bit2 = 0x20; // 32
	
	bitset<8> bit3 = bit1 & bit2;
	bitset<8> bit4 = bit1 | bit2;
	bitset<8> bit5 = bit1 ^ bit2;
	bitset<8> bit6 = ~bit1;
	bitset<8> bit7 = bit2 << 1;
	bitset<8> bit8 = bit2 >> 1;
	
	cout << bit3 << " " << bit4 << " " << bit5 << "\n" << bit6 << " " << bit7 << " " << bit8 << "\n";
}
