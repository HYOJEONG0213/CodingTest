#include <bits/stdc++.h>
using namespace std;

string s;
int wheel[4][8], K, idx, dir, ret;

void Rotate(int(&arr)[8], int d) {
	if (d == 1)
		rotate(rbegin(arr), rbegin(arr) + 1, rend(arr));
	else
		rotate(begin(arr), begin(arr) + 1, end(arr));
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			wheel[i][j] = s[j] - '0';
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> idx >> dir;
		idx--;

		int temp[4][8];
		memcpy(temp, wheel, sizeof(wheel));
		int d = dir * (-1);
		for (int j = idx - 1; j >= 0; j--) {
			if (temp[j][2] == temp[j + 1][6]) break;
			Rotate(wheel[j], d);
			d *= -1;
		}

		d = dir * (-1);
		for (int j = idx + 1; j < 4; j++) {
			if (temp[j - 1][2] == temp[j][6]) break;
			Rotate(wheel[j], d);
			d *= -1;
		}

		Rotate(wheel[idx], dir);
	}

	for (int i = 0; i < 4; i++)
		ret += (wheel[i][0] == 1 ? (1 << i) : 0);

	cout << ret;
}
