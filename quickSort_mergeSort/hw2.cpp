#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;
clock_t start, en_time;
double MsTimeArr[4][3], QsTimeArr[4][3];


void partition(int* s, int low, int high, int& pivotpoint) {
	int i, j, pivotItem;

	pivotItem = s[low];
	j = low;
	for (i = low + 1; i <= high; i++) {
		if (s[i] < pivotItem) {
			j++;
			swap(s[i], s[j]);
		}
	}
	pivotpoint = j;
	swap(s[low], s[pivotpoint]);
}

void QuickSort(int* arr, int low, int high) {
	int pivotpoint;
	if (high > low) {
		partition(arr, low, high, pivotpoint);
		QuickSort(arr, low, pivotpoint - 1);
		QuickSort(arr, pivotpoint + 1, high);
	}
}

void merge(int h, int m, int* u, int* v, int* s) {
	int i, j, k;
	i = 0; j = 0; k = 0;
	while (i < h && j < m) {
		if (u[i] < v[j]) {
			s[k] = u[i];
			i++;
		}
		else {
			s[k] = v[j];
			j++;
		}
		k++;
	}
	if (i > h-1) copy(v + j, v + m, s + k);
	else copy(u + i, u + h, s + k);
}

void MergeSort(int n, int* s) {
	if (n > 1) {
		int h = n / 2;
		int m = n - h;
		int* u= new int[h];
		int* v= new int[m];
		copy(s, s+h, u);
		copy(s+h, s+n, v);
		MergeSort(h, u);
		MergeSort(m, v);
		merge(h, m, u, v, s);
	}
}

void print_MS_Clock(int* ar, int r) {
	start = clock();
	MergeSort(r, ar);
	en_time = clock();
	cout << (double)(en_time - start) / CLOCKS_PER_SEC << '\t' << '\t';
}

void print_MS_Clock(int i, int j, int* ar, int r) {
	start = clock();
	MergeSort(r, ar);
	en_time = clock();
	cout << (double)(en_time - start) / CLOCKS_PER_SEC << '\t' << '\t';
	MsTimeArr[i][j] = (double)(en_time - start) / CLOCKS_PER_SEC;
}

void print_QS_Clock(int* ar, int l, int r) {
	start = clock();
	QuickSort(ar, 0, r);
	en_time = clock();
	cout << (double)(en_time - start) / CLOCKS_PER_SEC << '\t' << '\t';
}

void print_QS_Clock(int i, int j, int* ar, int l, int r) {
	start = clock();
	QuickSort(ar, 0, r);
	en_time = clock();
	cout << (double)(en_time - start) / CLOCKS_PER_SEC << '\t' << '\t';
	QsTimeArr[i][j] = (double)(en_time - start) / CLOCKS_PER_SEC;
}

void makeRand(int* ar, int n) {
	for (int i = 0; i < n; ++i) ar[i] = rand();
}

int main() {
	
	ifstream fin;
	fin.open("input.txt");
	if (!fin) {
		cout << "no input file exists";
		return 0;
	}
	int f_key, s_key, t_key;
	fin >> f_key >> s_key >> t_key;
	int* f_arr = new int[f_key];
	int* s_arr = new int[s_key];
	int* t_arr = new int[t_key];
	
	int* pArr[3] = { f_arr, s_arr, t_arr };
	int keyArr[3] = { f_key, s_key, t_key };

	for (int i = 0; i < f_key; ++i) f_arr[i] = i;
	for (int i = 0; i < s_key; ++i) s_arr[i] = i;
	for (int i = 0; i < t_key; ++i) t_arr[i] = i;
	
		
	cout << "sorted" << '\t' << '\t' << "N="<<f_key << '\t' << '\t' << "N="<<s_key << '\t' << '\t' << "N="<<t_key << endl;
	cout << "Merge Sort" << '\t';
	for (int i = 0; i < 3; ++i) {
		print_MS_Clock(pArr[i], keyArr[i]);
	}
	cout << endl << "Quick Sort" << '\t';
	for (int i = 0; i < 3; ++i) {
		print_QS_Clock(pArr[i], 0, keyArr[i] - 1);
	}
	cout << endl << endl;
	delete[] f_arr; delete[] s_arr; delete[] t_arr;
	fin >> f_key >> s_key >> t_key;
	keyArr[0] = f_key; keyArr[1] = s_key; keyArr[2] = t_key;
	
	f_arr = new int[f_key]; pArr[0] = f_arr;
	s_arr = new int[s_key]; pArr[1] = s_arr;
	t_arr = new int[t_key]; pArr[2] = t_arr;
			
	cout<<"random" << '\t' << '\t' << "N=" << f_key << '\t' << '\t' << "N=" << s_key << '\t' << '\t' << "N=" << t_key << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Merge Sort" << ' ' << "data" << i + 1 << ' ';
		for (int j = 0; j < 3; ++j) {
			makeRand(pArr[j], keyArr[j]);
			print_MS_Clock(i, j, pArr[j], keyArr[j]);
		}
		cout << endl;
	}
	MsTimeArr[3][0] = (MsTimeArr[0][0] + MsTimeArr[1][0] + MsTimeArr[2][0]) / 3;
	MsTimeArr[3][1] = (MsTimeArr[0][1] + MsTimeArr[1][1] + MsTimeArr[2][1]) / 3;
	MsTimeArr[3][2] = (MsTimeArr[0][2] + MsTimeArr[1][2] + MsTimeArr[2][2]) / 3;
	cout << '\t' << "average" << ' ' << ' ' << MsTimeArr[3][0] << '\t' << '\t' << MsTimeArr[3][1] << '\t' << '\t' << MsTimeArr[3][2] << endl << endl;
	for(int i = 0; i < 3; ++i) {
		cout << "Quick Sort" << ' ' << "data" << i + 1 << ' ';
		for (int j = 0; j < 3; ++j) {
			makeRand(pArr[j], keyArr[j]);
			print_QS_Clock(i, j, pArr[j], 0, keyArr[j]-1);
		}
		cout << endl;
	}
	QsTimeArr[3][0] = (QsTimeArr[0][0] + QsTimeArr[1][0] + QsTimeArr[2][0]) / 3;
	QsTimeArr[3][1] = (QsTimeArr[0][1] + QsTimeArr[1][1] + QsTimeArr[2][1]) / 3;
	QsTimeArr[3][2] = (QsTimeArr[0][2] + QsTimeArr[1][2] + QsTimeArr[2][2]) / 3;
	cout << '\t' << "average" << ' ' <<' '<< QsTimeArr[3][0] << '\t'<<'\t' << QsTimeArr[3][1] <<'\t'<< '\t' << QsTimeArr[3][2] << endl;
	
}
