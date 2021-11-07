#include <iostream>
using namespace std;

int partition(int* arr, int start, int end);
void quicksort(int* arr, int start, int end);
void sortAsc(int* arrAsc, int num);
void sortDesc(int* arrAsc, int num);
int calcAvg(int* arr);
void insert(int* arr);

int partition(int* arr, int start, int end) {

}

void quicksort(int* arr, int start, int end{

}

void sortAsc(int *arrAsc, int num) {
    int *arrAsc = new int[num];

}

void sortDesc(int *arrDesc, int num) {
    int* arrAsc = new int[num];

}

int calcAvg(int* arr) {
    int avg = 0;

    return avg;
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
    sortAsc(arr, num);

    delete[]arr;
    return 0;
}