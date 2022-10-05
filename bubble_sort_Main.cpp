#include <iostream>

using namespace std;

void bubble_sort(int *input,int size) {
	int n = size;
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (input[j] > input[j + 1]) {
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}

		// i번째 정렬 결과 출력
		for (int c = 0; c < n; c++) {
			cout << input[c] << " ";
		}
		cout << endl;
	}
}
int main() {
	int size;
	int * input;
	cin >> size;
	input = new int[size];
	for (int idx = 0; idx < size; idx++) {
		cin >> input[idx];
	}

	bubble_sort(input,size);
	// cout << endl;
		// for (int i = 0; i < size; i++) {
		// 	cout << input[i] << " ";
		// }

	delete[] input;
	return 0;
}