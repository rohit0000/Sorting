#include <iostream>

using namespace std;

int arr[10]={0};
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    cout << "Merge Sort Algorithm" << endl;

    for(int i = 0; i < 10; i++){
        cout << "input " << i+1 << ": ";
        cin >> arr[i];
        while(cin.fail()) {
            cout << "Error: Invalid user input" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "input " << i << ": ";
            cin >> arr[i];
        }
    }

    heapSort(arr, 10);
    cout << "Sorted Values: ";
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
