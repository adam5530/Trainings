#include <iostream>

using namespace std;

int partition(int arr[], int low, int high, int pivot)
{
	int PIndex = low;
    
	// Traverse the array from low to high
    for(int i=low;i<=high;i++) 
    {
        cout << "Pivot index " << PIndex << ", and i " << i << ", and arr[" << i << "]=" << arr[i] << ", and arr[PIndex]=" << arr[PIndex] << ", and pivot value " << pivot << endl;
        // If the current element is smaller than the pivot element
        if(arr[i]<=pivot) 
        {
            cout << "In for loop if condition met before swap" << endl;
            for(int j = 0; j <= high; j++)
                cout << arr[j] << " ";
            cout << endl;
            // Swap PIndex element with current element.
            swap(arr[PIndex],arr[i]);
            // Increment the pointer.
            cout << "In for loop if condition met after swap" << endl;
            for(int j = 0; j <= high; j++)
                cout << arr[j] << " ";
            cout << endl;
            PIndex++;
        }
    }
    
    PIndex--;
    
	return PIndex;
}

void quickSort(int arr[], int low, int high)
{
    cout << "Start quick sort" << endl;
	if(low < high) 
    {
	    int pivot = arr[high];
        //Rearrange and get the actual pivot index
	    int PIndex = partition(arr, low, high, pivot);
        cout << "Start quick sort when condition with returned pivot index " << PIndex << ", and pivot value " << pivot << endl;
        // solve for the left and right subarrays
        quickSort(arr, low, PIndex-1);
        quickSort(arr, PIndex+1, high);
	}
}

int main(int argc, char **argv)
{
    int arr[10] = {5, 7, 4, 0, 10, 17, 23, 2, 1, 6};
    cout << "Array before sort" << endl;
    for(auto elem : arr)
        cout << elem << " ";
    cout << endl;

    quickSort(arr, 0, 9);

    cout << "Array after sort" << endl;
    for(auto elem : arr)
        cout << elem << " ";
    cout << endl;
    return 0;
}