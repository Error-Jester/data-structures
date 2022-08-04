#include <iostream>
using namespace std;

template<class T>
void bubble_sort(T* arr, int num) {
    int i, j, temp;
    for (i = 0; i<(num - 1); i++)
        for (j = 0; j < (num - 1) - 1; j++)
            if (arr[j] > arr[j + 1])
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
}
