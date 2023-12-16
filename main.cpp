#include <iostream>
#include <array>

void TDMSplit(int B[], int begin, int end, int A[]);
void TDMSMerge(int A[], int begin, int middle, int end, int B[]);
void TDMergeSort(int A[], int B[], int n);
void Copy(const int A[], int begin, int end, int B[]);


void InsertionSort(double Darr[]);


void PigeonSort(int arr[], int Size);
void PrintPigeonSort(int arr[], int Size);
using namespace std;

void Copy(const int A[], int begin, int end, int B[]) {
    for (int i = begin; i < end; ++i)
        B[i] = A[i];
}

void TDMergeSort(int A[], int B[], int n) {
    Copy(A, 0, n, B);

    TDMSplit(B, 0, n, A);
    cout << "Merge\n";
    int i;
    for (i = 0; i < n; ++i)
        cout << A[i] << " ";
    //LMAO
    cout << "\n";
}

void TDMSplit(int B[], int begin, int end, int A[]) {
    if ((end - begin) <= 1) {
        return;
    }
    int middle = (begin + end) / 2;
    TDMSplit(A, begin, middle, B);

    TDMSplit(A, middle, end, B);

    TDMSMerge(B, begin, middle, end, A);

}

void TDMSMerge(int A[], int begin, int middle, int end, int B[]) {
    int i, j;
    j = middle;
    i = begin;
    for (int k = begin; k < end; ++k) {
        if (i < middle && ((j >= end) || A[i] <= A[j])) {
            B[k] = A[i];
            i += 1;
        }
        else {
            B[k] = A[j];
            j += 1;
        }
    }
}

void InsertionSort(double Darr[]) {
    double k;
    int l, i2;
    for (l = 1; l <= 5; ++l) {
        i2 = l - 1;
        k = Darr[l];
        while ((i2 >= 0) && (Darr[i2] > k)) {
            Darr[l] = Darr[i2];
            Darr[i2] = k;
            --i2, --l;
        }
    }
    cout << "Insertion\n";
    for (l = 0; l <= 5; ++l) {
        cout << Darr[l] << " ";
    }
}
void PigeonSort(int arr[], int Size) {
    int h, min, max, q, index;
    min = arr[0];
    max = arr[0];

    for (h = 0; h <= 5; ++h) {
        if (min > arr[h]) {
            min = arr[h];
        }
        if (max < arr[h]) {
            max = arr[h];
        }
    }
    int range = max - min + 1;
    int* tempArr = new int[range]{0};

    for (h = 0; h < Size; ++h){
        index = arr[h] - min;
        for (q = range; q >= 0; --q){
            if (index == q)
                ++tempArr[q];
        }
    }
    // for each item in tempArr that is greater than 0, change arr[indexoftemparr] to index of temparr+min,
    for (h = 0; h < Size; ++h){
        for(q = 0; q < range; ++q){
            while (tempArr[q] > 0 ){
                arr[h] = (q + min);
                ++h;
                --tempArr[q];
            }
        }
    }
    PrintPigeonSort(arr, Size);
}

void PrintPigeonSort(int arr[], int Size) {
    int i;
    cout << "\nPigeon\n";
    for (i = 0; i < (Size); ++i)
        cout << arr[i] << " ";
}



int main() {
    int A_arr[6] = { 7,6,9,0,20,3 };
    int B_arr[6] = { 0 }, n = 6;

    int arr[6] = { 10,9,5,8,4,6 };
    int Size = sizeof(arr)/sizeof(arr[0]);
    double arr2[6] = { 10.5,20,10.55,1,99,20.1 };
    TDMergeSort(A_arr, B_arr, n);
    InsertionSort(arr2);
    PigeonSort(arr, Size);
    return 0;
}
