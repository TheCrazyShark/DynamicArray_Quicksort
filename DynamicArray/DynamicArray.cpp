#include <iostream>
using namespace std;

int partition(int* arr, int start, int end);
void quicksort(int* arr, int start, int end);
void sortAsc(int* arrAsc, int num);
void sortDesc(int* arrAsc, int num);
double calcAvg(int* arr, int num);
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
    This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right of pivot 
************/
int partition(int* arr, int start, int end) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/************
    The main function that implements QuickSort
    arr[] --> Array to be sorted,
    low  --> Starting index,
    high  --> Ending index 
 ***********/
void quicksort(int* arr, int start, int end) {

}

/************

************/
void sortAsc(int *arrAsc, int num) {
    int *arrAsc = new int[num];

}

/************

************/
void sortDesc(int *arrDesc, int num) {
    int* arrAsc = new int[num];

}

/************
    Calculates average of array and returns it
************/
double calcAvg(int* arr, int num) {
    double avg = 0, int sum = 0;

    for (int i = 0; i < num; i++) {
        sum += arr[i];
    }
    avg = sum / num;

    return avg;
}

/************

************/
void insert(int* arr) {

}

int main() {
    int x, num;
    cout << "How many numbers will you type? ";
    cin >> num;
    int* arr = new int[num];
    cout << "Enter " << num << " numbers:" << endl;

    // Take in the numbers
    for (x = 0; x < num; x++) {
        cin >> arr[x];
    }

    // Display input numbers
    cout << "Input numbers: ";
    for (x = 0; x < num; x++) {
        cout << arr[x] << " ";
    }
    sortAsc(arr, num-1);
    sortDesc(arr, num-1);
    cout << "Average: " << calcAvg(arr, num) << endl;

    delete[]arr;
    return 0;
}