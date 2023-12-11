#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
using namespace std;

void insertionSort(string arr[], int lenght) {
    for (int i = 1; i < lenght; i++) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(string arr[], int lenght) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < lenght - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void merge(string arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    string temp [8];

    for (int k = left; k <= right; k++) {
        if (i > mid) {
            temp[k] = arr[j++];
        }
        else if (j > right) {
            temp[k] = arr[i++];
        }
        else {
            if (arr[i] < arr[j]) {
                temp[k] = arr[i++];
            }
            else {
                temp[k] = arr[j++];
            }
        }
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(string arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void quickSort(string arr[], int left, int right)
{ 
    if (left >= right) return;
    int i = left;
    int j = right;
    string mid = arr[(i + j) / 2];

    while (i <= j) {
        while (arr[i] < mid)
            i++;
        while (mid < arr[j])
            j--;
        if (i <= j)
            swap(arr[i++], arr[j--]);
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

void randSort(string arr[], int lenght)
{
    srand(time(NULL));
    int pos, pos2;
    for (int i = 0; i < rand() % 20; i++)
    {
        pos = rand() % lenght;
        pos2 = rand() % lenght;
        swap(arr[pos], arr[pos2]);
    }
}

void print(string arr[], int lenght) {
    for (int i = 0; i < lenght; i++) {
        cout << arr[i] << " ";
    }
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    const int COLORS = 7;
    string rainbow[COLORS]{
        "Orange", "Yellow", "Violet", "Red", "Indigo", "Blue", "Green"
    };

    randSort(rainbow, COLORS);
    
    cout << "Какую сортировку вы хотите использовать? \n";
    cout << "1 - пузырьковая сортировка.\n2 - быстрая сортировка.\n3 - сортировка вставками.\n4 - сортировка слиянием.\n";
    int choice;
    cin >> choice;
    bool isActive = true;
    auto start_sort = chrono::system_clock::now();
    while (isActive) {
        switch (choice) {
        case 1:       
            system("cls");
            cout << "Пузырьковая сортировка: \n";
            bubbleSort(rainbow, COLORS);
            print(rainbow, COLORS);
            isActive = false;
            break;
        case 2:
            system("cls");
            cout << "Быстрая сортировка: \n";
            quickSort(rainbow, 0, COLORS - 1);
            print(rainbow, COLORS);
            isActive = false;
            break;
        case 3:
            system("cls");
            cout << "Сортировка вставками: \n";
            insertionSort(rainbow, COLORS);
            print(rainbow, COLORS);
            isActive = false;
            break;
        case 4:
            system("cls");
            cout << "Сортировка слиянием: \n";
            mergeSort(rainbow, 0, COLORS - 1);
            print(rainbow, COLORS);
            isActive = false;
            break;
        default:
            cout << "Вы ввели неправильное число, попробуйте ещё раз!\n";
            cin >> choice;
            break;
        }
    }

    auto end_sort = chrono::system_clock::now();
    chrono::duration<double> duration_sort = end_sort - start_sort;
    cout << "\n\nВремя выполнения сортировки: " << duration_sort.count() << " сек." << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "\n\nВремя выполнения программы: " << duration.count() << " сек." << endl;
}