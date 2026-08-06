#include <bits/stdc++.h>
using namespace std;

// Function to perform selection sort
void selection_sort(int arr[], int n) {
    for(int i = 0;i<n;i++)
    {
        int mini = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[mini]>arr[j])
            {
                mini = j;
            }
        }
        swap(arr[i],arr[mini]);
    }
    // Print the sorted array
    cout << "After selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

}

int main() {
    // Initialize array
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print array before sorting
    cout << "Before selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Call selection sort
    selection_sort(arr, n);

    return 0;
}
