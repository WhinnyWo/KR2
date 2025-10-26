#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        
        cout << "Опорный элемент: " << arr[pivot_index] << endl;
        cout << "Текущий массив: ";
        for (int num : arr) cout << num << " ";
        cout << endl;
        
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int main() {
    vector<int> numbers = {64, 34, 25, 12, 22, 11, 90, 8};
    
    cout << "Исходный массив: ";
    for (int num : numbers) cout << num << " ";
    cout << endl << endl;
    
    quicksort(numbers, 0, numbers.size() - 1);
    
    cout << "\nОтсортированный массив: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;
    
    return 0;
}