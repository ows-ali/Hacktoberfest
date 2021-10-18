#include <iostream>
using namespace std;
void bubbleSort(int *array, int n);

int main()
{
    int arr[] = {13, 1024, 995, 5, 15, 45, 105, 1, 67};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, arr_size);

    for (int i = 0; i < arr_size; ++i)
        std::cout << arr[i] << std::endl;

    return 0;
}

void bubbleSort(int *array, int n)
{
    bool swapped = true;
    int j = 0;
    int temp;

    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; ++i)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

