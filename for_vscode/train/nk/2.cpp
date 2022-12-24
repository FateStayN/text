#include <iostream>

using namespace std;
void QuickSort(long *arr, int begin, int end);
void exchange(long *a, long *b);

int main()
{
    long a[100000] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void QuickSort(long arr[100000], int begin, int end)
{
    long std = arr[end];
    int j = begin;
    if (begin < end)
    {
        for (int i = begin; i < end; i++)
        {
            if (arr[i] < std)
            {
                exchange(arr + i, arr + j);
                j++;
            }
        }
        exchange(arr + end, arr + j);
        QuickSort(arr, begin, j - 1);
        QuickSort(arr, j + 1, end);
    }
}

void exchange(long *a, long *b)
{
    if (*a != *b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}