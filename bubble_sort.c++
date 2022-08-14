#include <iostream>
using namespace std;

template<class T>
void bubble_sort(T* arr, int num) {
    int i, j, temp, counter = 0;
    for (i = 0; i<(num - 1); i++){
          
        for (j = 0; j < (num - 1) - 1; j++) {
            if (arr[j] > arr[j + 1]){
                 temp = arr[j];
                 arr[j] = arr[j + 1];
                 arr[j + 1] = arr[j];
           }
            cout << "pass: " << counter << endl;
            for(int a = 0; a < 10; a++) {
                cout << arr[a] << ", ";
            }
            cout << endl;
        }
        counter++;   
    }
}

int main() {
    long int array[10] = {118, 12, 13, 15, 61, 82, 89, 23, 87, 67 };
    bubble_sort(array, 10);
    cout << endl;
    return 0;
}
