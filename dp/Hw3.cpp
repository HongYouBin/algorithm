#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

const int MAX = 105;

int main() {
	
	ifstream fin;
	fin.open("input.txt");
	if (!fin) {
		cout << "no input file exists";
		return 0;
	}
	
	int tc;
	
	fin >> tc;
	while (tc--) {
		int m[MAX][MAX], p[MAX][MAX];
		string x, y;
		int xLen, yLen;

		fin >> xLen >> x >> yLen >> y;
		for (int i = 0; i <= xLen; ++i) m[i][0] = 3 * i;
		for (int i = 0; i <= yLen; ++i) m[0][i] = 3 * i;

		for (int i = 1; i <= xLen; ++i) {
			for (int j = 1; j <= yLen; ++j) {
				int pnt = x[i - 1] == y[j - 1] ? 0 : 1;
				m[i][j] = min({ m[i - 1][j - 1] + pnt, m[i - 1][j] + 3, m[i][j - 1] + 3 });
				if (m[i][j] == m[i - 1][j - 1] + pnt)p[i - 1][j - 1] = 1;
				else if (m[i][j] == m[i - 1][j] + 3)p[i - 1][j - 1] = 2;
				else if (m[i][j] == m[i][j - 1] + 3)p[i - 1][j - 1] = 3;
			}
		}
		stack<char> st[2];
		int len = max(xLen, yLen);
		int i = xLen - 1, j = yLen - 1;
		for (int k = 0; k < len; k++) {
			if (p[i][j] == 1) {
				if (i >= 0)st[0].push(x[i]);
				if (j >= 0)st[1].push(y[j]);
				i--; j--;
			}
			else if (p[i][j] == 2) {
				if (i >= 0)st[0].push(x[i]);
				if (j >= 0)st[1].push('-');
				i--;
			}
			else {
				if (i >= 0)st[0].push('-');
				if (j >= 0)st[1].push(y[j]);
				j--;
			}
		}
		while (!st[0].empty()) {
			cout << st[0].top();
			st[0].pop();
		}
		cout << endl;
		while (!st[1].empty()) {
			cout << st[1].top();
			st[1].pop();
		}
		cout << endl;
		for (int i = 0; i <= xLen; ++i) {
			for (int j = 0; j <= yLen; ++j) {
				cout << m[i][j] << ' ';
			}
			cout << endl;
		}
	}
	fin.close();
}


