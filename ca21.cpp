 #include <iostream>
using namespace std;

void merge(int arr[][3], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1][3], rightArr[n2][3];

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < 3; j++)
            leftArr[i][j] = arr[left + i][j];
    for (int j = 0; j < n2; j++)
        for (int k = 0; k < 3; k++)
            rightArr[j][k] = arr[mid + 1 + j][k];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i][1] <= rightArr[j][1]) {
            for (int l = 0; l < 3; l++)
                arr[k][l] = leftArr[i][l];
            i++;
        } else {
            for (int l = 0; l < 3; l++)
                arr[k][l] = rightArr[j][l];
            j++;
        }
        k++;
    }

    while (i < n1) {
        for (int l = 0; l < 3; l++)
            arr[k][l] = leftArr[i][l];
        i++;
        k++;
    }

    while (j < n2) {
        for (int l = 0; l < 3; l++)
            arr[k][l] = rightArr[j][l];
        j++;
        k++;
    }
}

void mergeSort(int arr[][3], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int arr[][3], int size) {
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i][1] << " " << arr[i][0] << " " << arr[i][2] << endl;
    }
}

int main() {
    int N = 5; 
    int Orders[N][3] = {{3, 10, 250}, {1, 7, 150}, {2, 3, 300}, {5, 9, 450}, {4, 5, 200}};

    mergeSort(Orders, 0, N - 1);

    cout << "Sorted Orders by Customer ID" << endl;
    printArray(Orders, N);

    return 0;
}