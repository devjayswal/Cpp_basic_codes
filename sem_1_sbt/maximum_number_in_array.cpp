#include<iostream>
using namespace std;

int max(int array[], int inde) {
    int i, temp = array[0];
    for (i = 0; i <= inde - 2; i++) {
        if (temp < array[i + 1])
            temp = array[i + 1];
    }
    return temp;
}

int main() {
    int index, i;
    int arr[] = {-1, -1, 9, 8, 7, 0, -10};
    cout << "MAXIMUM = " << max(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}
