#include <iostream>
#include <stdlib.h>

using namespace std;

int* NewArray(int* arr, int r, int size)
{
    int* temp = new int[size + r];
    for (int i = 0; i < size + r; i++) {
        if (i < size)
            temp[i] = arr[i];
        else
            temp[i] = i + 1;
    }
    return temp;
}

int main()
{
    srand(time(0));
    //1
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
        cout << array[i] << " ";
    }
    int psize = rand() % 20;
    cout << "+ new size: " << psize << endl;
    int* temp2 = new int[size + psize];
    for (int i = 0; i < size + psize; i++) {
        if (i < size)
            temp2[i] = array[i];
        else
            temp2[i] = i + 1;
    }
    delete[] array;
    array = temp2;
    for (int i = 0; i < size + psize; i++)
        cout << array[i] << " ";
    cout << "\n\n";

    //2
    int size1;
    cout << "Enter size of array: ";
    cin >> size1;
    int r = rand() % 20;
    int* arr = new int[size1];
    for (int i = 0; i < size1; i++) {
        arr[i] = i + 1;
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "+ new size: " << r << endl;
    int* temp1 = NewArray(arr, r, size1);
    delete[] arr;
    arr = temp1;
    for (int i = 0; i < size1+r; i++) {
        arr[i] = i + 1;
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    
    //3
    int M;
    cout << "Enter size of first array: ";
    cin >> M;
    int N;
    cout << "Enter size of second array: ";
    cin >> N;
    int* A = new int[M];
    cout << "A:\n";
    for (int i = 0; i < M; i++) {
        A[i] = rand() % 20;
        cout << A[i] << " ";
    }
    cout << endl;
    int* B = new int[N];
    cout << "B:\n";
    for (int i = 0; i < N; i++) {
        B[i] = rand() % 20;
        cout << B[i] << " ";
    }
    cout << endl;
    int c = 0, d = 0;
    int* temp = new int[M + N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                for (int l = 1; l <= M+N; l++) {
                    if (A[i] == temp[l-1])
                        d++;
                }
                if (d == 0) {
                    temp[c] = A[i];
                    c++;
                }
            }                      
        }
        d = 0;
    }
    int* a = new int[c];
    for (int i = 0; i < c; i++) {
        a[i] = temp[i];
        cout << a[i] << " ";
    }
    delete[] temp;
    cout << "\n\n";
}
