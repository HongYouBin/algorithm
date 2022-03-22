#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

int t, v[1005][2], n, arr[1005][2], ans;

void recursion(int Node) {
	for (int i = 0; i < 2; i++) {
		if (v[Node][i] == -1)continue;
		int nxt = v[Node][i];
		arr[Node][i]++;
		recursion(nxt);
		arr[Node][i] += arr[nxt][0] + arr[nxt][1];
	}
	if (arr[Node][0] < arr[Node][1])ans++;
}

int main() {
	ifstream fin;
	fin.open("input.txt");
	if (!fin) {
		cout << "input.txt 파이를 열 수 없습니다.";
		return 0;
	}
	fin >> t;
	while (t--) {
		for (int i = 0; i < 1005; ++i) {
			for (int j = 0; j < 2; ++j) {
				v[i][j] = 0;
				arr[i][j] = 0;
			}
		}
		ans = 0;
		fin >> n;
		for (int i = 0; i < n; ++i) {
			int node, lef, right;
			fin >> node >> lef >> right;
			v[node][0] = lef;
			v[node][1] = right;
		}
		recursion(1);
		cout << ans << '\n';
	}
	fin.close();
}


/*
#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

int t, v[1005][2], n, arr[1005][2], ans;

void recursion(int Node) {
	if (v[Node][0] != -1) {
		int nxt = v[Node][0];
		arr[Node][0]++;
		recursion(nxt);
		arr[Node][0] += arr[nxt][0] + arr[nxt][1];
	}
	if (v[Node][1] != -1) {
		int nxt = v[Node][1];
		arr[Node][1]++;
		recursion(nxt);
		arr[Node][1] += arr[nxt][0] + arr[nxt][1];
	}
	if (arr[Node][0] < arr[Node][1])ans++;
	
	
}

int main() {
	ifstream fin;
	fin.open("input.txt");
	if (!fin) {
		cout << "input.txt 파이를 열 수 없습니다.";
		return 0;
	}
	fin >> t;
	while (t--) {
		for (int i = 0; i < 1005; ++i) {
			for (int j = 0; j < 2; ++j) {
				v[i][j] = 0;
				arr[i][j] = 0;
			}
		}
		ans = 0;
		fin >> n;
		for (int i = 0; i < n; ++i) {
			int node, lef, right;
			fin >> node >> lef >> right;
			v[node][0] = lef;
			v[node][1] = right;
		}
		recursion(1);
		cout << ans << '\n';
	}
	fin.close();
}

#include <iostream>
#include <fstream>
using namespace std;

int v[1000][2], n, arr[1005][2], ans;

void recursion(int Node) {
	if (v[Node][0] != -1) {
		int nxt = v[Node][0];
		arr[Node][0]++;
		recursion(nxt);
		arr[Node][0] += arr[nxt][0] + arr[nxt][1];
	}
	if (v[Node][1] != -1) {
		int nxt = v[Node][1];
		arr[Node][1]++;
		recursion(nxt);
		arr[Node][1] += arr[nxt][0] + arr[nxt][1];
	}
	if (arr[Node][0] < arr[Node][1])ans++;
}

int main() {
	ifstream fin;
	fin.open("input.txt");
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int node, lef, right;
		cin >> node >> lef >> right;
		v[node][0] = lef;
		v[node][1] = right;
	}
	recursion(1);
	cout << ans;
}
*/
