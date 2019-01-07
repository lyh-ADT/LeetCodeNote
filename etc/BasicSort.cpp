#include <iostream>
using namespace std;

template <class T>
void outputArray(T a[], int n);

// 插入排序
template<class T>
T* insertionSort(T a[], const int n) {
    /*
     * 将第1..n-1号元素插入到初始0号元素周围
     */
    int ordered_index = 0;
    for (int i = 1; i < n; ++i) {
        int temp = a[i];
        for (int j = i - 1; j > -1; --j) {
            if (a[j + 1] < a[j]) {
                a[j + 1] = a[j];
            } else {
                a[j + 1] = temp;
                break;
            }
        }
        outputArray(a, n);
    }
    return a;
}

// 选择排序
template<class T>
T* selectionSort(T a[], const int n) {
    /*
     * 每次遍历找到最小(大)的元素下标,交换两个下标对应的元素
     */
    for (int i = 0; i < n; ++i) {
        int peak = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[peak]) {
                peak = j;
            }
        }
        int temp = a[i];
        a[i] = a[peak];
        a[peak] = temp;
    }
    return a;
}

// 冒泡排序
template<class T>
T* popupSort(T a[], const int n) {
    /*
     * 两两比较,进行交换
     */
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return a;
}

int main() {
    int a[] = {2, 5, 3, 7, 6};
    int n = sizeof(a) / sizeof(int);
    // insertionSort(a, n);
    // selectionSort(a, n);
    popupSort(a, n);
    outputArray(a, n);
}

template <class T>
void outputArray(T a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << "\t";
    }
    cout << endl;
}