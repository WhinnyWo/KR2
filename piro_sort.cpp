#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // Построение max-кучи
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> numbers = {4, 10, 3, 5, 1, 8, 7};
    
    cout << "Исходный массив: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;
    
    heapSort(numbers);
    
    cout << "Отсортированный массив: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;
    
    return 0;
}