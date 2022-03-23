#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> vt;
bool ro[9][10], col[9][10], arr[9][10];
int sudoku[9][9];

void fill_sudoku(int n) {
	if (n == vt.size()) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << sudoku[i][j] << ' ';
			}
			cout << endl;
		}
		exit(0);
		return;
	}
	int row = vt[n].first;
	int colum = vt[n].second;
	for (int i = 1; i <= 9; ++i) {
		if (ro[row][i] || col[colum][i] || arr[row / 3 * 3 + colum / 3][i]) continue;
		ro[row][i] = true;
		col[colum][i] = true;
		arr[row / 3 * 3 + colum / 3][i] = true;
		sudoku[row][colum] = i;
		fill_sudoku(n + 1);
		sudoku[row][colum] = 0;
		ro[row][i] = false;
		col[colum][i] = false;
		arr[row / 3 * 3 + colum / 3][i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int n;
			cin >> n;
			if (!n) {
				vt.push_back({ i,j });
				continue;
			}
			sudoku[i][j] = n;
			ro[i][n] = true;
			col[j][n] = true;
			arr[(i / 3 * 3) + (j / 3)][n] = true;
		}
	}
	fill_sudoku(0);
}