#include <iostream>
using namespace std;

const double* aver(const double* arr, size_t size, double& average);

int main() {
	double arr[] = {1, 2, 4};

	size_t size = sizeof(arr)/sizeof(arr[0]);

	double average = 0;

	const double* p = aver(arr, size, average);

	cout << *p << " " << average << endl;

	return 0;
}

// the algorithm is wrong!!!
const double* aver(const double* arr, size_t size, double& average) {
	int i;
	int index = 0;
	double sum = 0;
	// set the first elem as max by default
	double max = arr[index];

	for (i = 0; (unsigned)i < size; i++)
		sum += arr[i];

	average = sum / size;

	// get the max value and its index
	for (i = 0; (unsigned)i < size; i++)
		if ((max) < arr[i]) {
			max = arr[i];
			index = i;
		}

	// max number in arr in case there is no match
	double closest = max;

	for (i = 0; (unsigned)i < size; i++) {
		// if greater than current and less than current closest
		if (arr[i] >= average && arr[i] < closest) {
			// updating the closest
			closest = arr[i];
			index = i;
		}
	}

	// return
	return (double*)(arr + index);
}
