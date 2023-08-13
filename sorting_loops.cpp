#include<bits/stdc++.h>
using namespace std;


void selectionSort(vector<int>&arr) {
    // Write your code here.

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[index] > arr[j]) {
                index = j;
            }
        }
        int obs = arr[index];
        arr[index] = arr[i];
        arr[i] = obs;
    }

    for (auto it : arr) {
        cout << it << " ";
    }

}

void bubbleSort(vector<int>&arr) {
    int n = arr.size();

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (auto it : arr) {
        cout << it << " ";
    }
}

void insertionSort(vector<int>&arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int j = i;
        while (arr[j] < arr[j - 1] && j > 0) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }

    for (auto it : arr) {
        cout << it << " ";
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int n;
        cin >> n;
        v.emplace_back(n);
    }

    insertionSort(v);
    bubbleSort(v);
    selectionSort(v);

    return 0;

}
