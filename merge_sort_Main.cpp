#include <iostream>

using namespace std;

void printArray(int *A, int left, int right)
{		
    for (auto i = left; i<= right; i++){
			// if(A[i]==0){
			// 	continue;
			// }
        cout << A[i] << " ";
			}
		cout<<" "<<endl;
}

void merge(int *input, int const left ,int const mid, int const right) {

    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid ;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = input[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = input[mid + 1 + j];
 
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 		// printArray(input, right);

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            input[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            input[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;

    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        input[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        input[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
		printArray(input,left, right);
		// cout<<"left : "<<left << " mid : "<<mid <<" right :"<<right<<endl;
		
    delete[] leftArray;
    delete[] rightArray;
}


void mergesort(int *input, int const begin, int const end){
	if(begin>=end){
		return;
	}
	auto mid = (begin + end) /2;
	// cout<<"begin : "<<begin << " mid : "<<mid <<" end :"<<end<<endl;

	mergesort(input,begin,mid); // 좌측 정렬

	mergesort(input,mid +1 ,end); // 우측 정렬
	// cout<<"merge run"<<endl;
	merge(input,begin,mid,end);

}

int main() {
	int size;
	int * input;
	cin >> size;
	input = new int[size];
	for (int idx = 0; idx < size; idx++) {
		cin >> input[idx];
	}


	
	// cout << "Given array is \n";
	// printArray(input, size);

	mergesort(input, 0, size-1);

	// cout << "\nSorted array is \n";
	// printArray(input, size);


	delete[] input;
	return 0;
}