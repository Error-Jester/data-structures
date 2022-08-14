#include "iostream"

using namespace std;

template <class T>
void selection_sort(T* array, int n) {
    int i, j, pos, temp;
    for (i = 0; i < (n - 1); i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (array[pos] > array[j])
            pos = j;
        }
        if (pos != i) {
            temp = array[i];
            array[i] = array[pos];
            array[pos] = temp;
        }
    }
}