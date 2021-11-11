#include <iostream>
using namespace std;

int partition(int* arr, int start, int end);
void quicksort(int* arr, int start, int end);
void sortAsc(int* arrAsc, int num);
void sortDesc(int* arrAsc, int num);
void calcAvg(int* arr, int num);
void insert(int* arr);

/***********
    A utility function to swap two elements
***********/ 
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/***********
    This function takes end element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right of pivot 
************/
int partition(int* arr, int start, int end, bool asc) {
    int pivot = arr[end];    // pivot
    int i = (start - 1);  // Index of smaller element

    if (asc) {
        for (int j = start; j <= end - 1; j++) {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot) {
                i++;    // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
    }
    else {
        for (int j = start; j <= end - 1; j++) {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] >= pivot) {
                i++;    // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}

/************
    The main function that implements QuickSort
    arr[] --> Array to be sorted,
    low  --> Starting index,
    high  --> Ending index 
 ***********/
void quickSort(int* arr, int start, int end, bool asc) {
    if (start < end) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, start, end, asc);
        

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, start, pi - 1, asc);
        quickSort(arr, pi + 1, end, asc);
    }
}

/************
    Calls quickSort using a true boolean value in order to sort in ascending order
************/
void sortAsc(int *arr, int num) {
    int* arrAsc = arr;
    
    quickSort(arrAsc, 0, num, true);

    // Display asc order numbers
    cout << endl << "Ascending Order: ";
    for (int x = 0; x <= num; x++) {
        cout << arr[x] << " ";
    }
}

/************
    Calls quickSort using a false boolean value in order to sort in descending order
************/
void sortDesc(int *arr, int num) {
    int* arrDesc = arr;

    quickSort(arrDesc, 0, num, false);

    // Display desc order numbers
    cout << endl << "Descending Order: ";
    for (int x = 0; x <= num; x++) {
        cout << arr[x] << " ";
    }
}

/************
    Calculates average of array and returns it
************/
void calcAvg(int* arr, int num) {
    double avg = 0;
    int sum = 0;

    for (int i = 0; i < num; i++) {
        sum += arr[i];
    }
    avg = (double)sum / (double)num;

    cout << endl << "Average: " << avg << endl;
}

/************
    Inserts more data into the array after the first round of sorting
************/
void insert(int* arr, int originalNum) {
    int num;
    cout << endl << "How many more numbers will you enter? ";
    cin >> num;
    cout << "Enter " << num << " numbers:" << endl;
    int* newArr = new int[num+originalNum];

    // Take numbers in numbers from original array into new array
    for (int x = 0; x < originalNum; x++) {
        newArr[x] = arr[x];
    }

    // Take in the numbers and add it to array
    for (int x = originalNum; x < num+originalNum; x++) {
        cin >> newArr[x];
    }

    // Display total input numbers
    cout << "Input numbers: ";
    for (int x = 0; x < num+originalNum; x++) {
        cout << newArr[x] << " ";
    }

    // Call sort asc for new function
    sortAsc(newArr, (num+originalNum) - 1);

    // Call sort desc
    sortDesc(newArr, (num+originalNum) -1);

    // Calculate Average
    calcAvg(newArr, num);

    delete[]newArr;
}

int main() {
    int num;
    cout << "How many numbers will you enter? ";
    cin >> num;
    int* arr = new int[num];
    cout << "Enter " << num << " numbers:" << endl;

    // Take in the numbers
    for (int x = 0; x < num; x++) {
        cin >> arr[x];
    }

    // Display input numbers
    cout << "Input numbers: ";
    for (int x = 0; x < num; x++) {
        cout << arr[x] << " ";
    }

    // Call sort asc
    sortAsc(arr, num-1);

    // Call sort desc
    sortDesc(arr, num-1);

    // Calculate Average
    calcAvg(arr, num);

    // Add more data
    insert(arr, num);

    delete[]arr;
    return 0;
}