#include <iostream>
using namespace std;

const int MAX = 100;

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        if (min_index != i)
            swap(arr[i], arr[min_index]);
    }
}

int main()
{
    int arr[MAX];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SelectionSort(arr, n);
    cout << "Trung vi la: " << arr[n / 2];
    return 0;
}