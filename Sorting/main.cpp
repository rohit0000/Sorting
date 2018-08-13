#include <iostream>

using namespace std;

    int arr[10] = {0};
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int *arr, int low, int high)
{
    int pv = arr[high];    // pivot
    int i = (low - 1);  // Index of low element

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pv)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{


    cout << "Quick Sort Algorithm" << endl;

    for(int i = 0; i < 10; i++){
        cout << "input " << i+1 << ": ";
        cin >> arr[i];
        while(cin.fail()) {
            cout << "Error: Invalid user input" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "input " << i+1 << ": ";
            cin >> arr[i];
        }
    }
//for(int i = 0; i < 10; i++){
//        cout << arr[i] << " ";
//    }
//        cout << endl;

    quickSort(arr, 0, 9);
    cout << "Sorted Values: ";
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

