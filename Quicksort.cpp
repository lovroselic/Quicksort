// https://www.codeabbey.com/index/task_view/quicksort
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <cmath>
#include <cassert>
#include <limits>
#include <numeric>
#include <tuple>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

void QuickSort(vector<int>& array, int left, int right, vector<string>& solution);
int Partition(vector<int>& a, int L, int R);

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Quicksort v" << VERSION << "!\n\n";
	//string path = "Test0.txt";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	vector<int> data = splitToInt(raw_data[1], " ");
	//printVector(data);

	vector<string> solution;

	cout << "Initial: " << joinVector(data, " ") << endl;
	QuickSort(data, 0, data.size() - 1, solution);
	cout << "Sorted: " << joinVector(data, " ") << endl;

	cout << "\nSolution: " << joinVector(solution, " ") << endl;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}

void QuickSort(vector<int>& array, int left, int right, vector<string>& solution) {
	solution.push_back(to_string(left) + "-" + to_string(right));
	int pivot_pos = Partition(array, left, right);
	if (pivot_pos - left > 1) QuickSort(array, left, pivot_pos - 1, solution);
	if (right - pivot_pos > 1) QuickSort(array, pivot_pos + 1, right, solution);
}

int Partition(vector<int>& a, int L, int R) {
	int pivot = a[L];
	string dir = "left";
	while (L < R) {
		if (dir == "left") {
			if (a[R] > pivot) {
				R--;
			}
			else {
				swap(a[L], a[R]);
				L++;
				dir = "right";
			}
		}
		else {
			if (a[L] < pivot) {
				L++;
			}
			else {
				swap(a[R], a[L]);
				R--;
				dir = "left";
			}
		}
	}

	return L;
}
