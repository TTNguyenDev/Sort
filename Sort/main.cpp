#define MAX 2000
#include <iostream>


using namespace std;

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
//---------selectionSort-------
void selectionSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j])
                swap(a[i], a[j]);
}

//-----------mergeSort----------
void mergeFunc(int *a, int mid, int left, int right) {
    int temp[right - left + 1];
    int i = left;
    int j = mid + 1;
    
    for (int m = 0; m <= right - left; m++) {
        if (a[i] < a[j]) {
            temp[m] = a[i];
            i++;
        } else {
            temp[m] = a[j];
            j++;
        }
        
        if (i == mid + 1) {
            while (j <= right) {
                m++;
                temp[m] = a[j];
                j++;
            }
            break;
        }
        
        if (j == right + 1) {
            while (i <= mid) {
                m++;
                temp[m] = a[i];
                i++;
            }
            break;
        }
    }
    for (int m = 0; m <= right - left; m++)
        a[left + m] = temp[m];
}

void mergeSort(int *a, int left, int right) {
    if (left < right) {
        int mid = (left+right)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        mergeFunc(a, mid, left, right);
    }
}

//-------Quick_sort----------------
void quickSort(int a[], int left, int right) {
    int i, j, x, y;
    
    i = left;
    j = right;
    
    x = a[(left + right)/2];
    
    do {
        while (a[i] < x && i < right) i++;
        while (a[j] > x && j > left) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);
}

void quick_sort(int a[], int n) {
    quickSort(a, 0, n-1);
}

//-------HeapSort-------------------
void Heapify(int a[], int n, int i) {
    int left = 2 * (i + 1) - 1;
    int right = 2 * (i + 1);
    
    int max;
    
    if (left < n && a[left] > a[i])
        max = left;
    else
        max = i;
    
    if (right < n && a[right] > a[max])
        max = right;
    
    if (i != max) {
        swap(a[i], a[max]);
        Heapify(a, n, max);
    }
}

void BuildHeap(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        Heapify(a, n, i);
}

void HeapSort(int a[], int n) {
    BuildHeap(a, n);
    
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}

//--------RadixSort----------------
void RadixSort(int *a, int n) {
    int b[MAX], m = a[0], exp = 1;
    
    for (int i = 0; i < n; i++) {
        if (a[i] > m)
            m = a[i];
    }
    
    while (m / exp > 0) {
        int bucket[10] = {0};
        for (int i = 0; i < n; i++)
            bucket[a[i] / exp % 10]++;
        for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; i--)
            b[--bucket[a[i] / exp % 10]] = a[i];
        for (int i = 0; i < n; i++)
            a[i] = b[i];
        exp *= 10;
    }
    
}

int main() {
    int a[7] = {2,5,1,4,5,8,2};
    //selectionSort(a, 7);
//    quick_sort(a, 7);
   // mergeSort(a, 0, 6);
//    HeapSort(a, 7);
    RadixSort(a, 7);
    return 0;
}
