//
//  SwapSort.h
//  InsertionSort
//
//  Created by Sart Way on 9/2/23.
//

#ifndef SwapSort_h
#define SwapSort_h
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    
    Node(int Data)
    {
        this->data = Data;
        this->left = NULL;
        this->right = NULL;
    }
    
    
};


class SwapSort
{
public:
    long count;
    
    SwapSort(){
        count = 0;
    }
    
    void getAnswer(int arr[], int size)
    {
        //count = 0;
        MergeSort(arr, 0, size-1);
    }
    
    void MergeSort(int arr[], int start, int end)
    {
        if(start >= end)
        {
            return;
        }
        int mid = start + ((end - start)/2);
        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);
        merger(arr, start, mid, end);
    }
    
    void merger(int arr[], int start, int mid, int end)
    {
        int* leftarr_copy = new int[(mid - start) + 1];
        int* rightarr_copy = new int[end - mid];
        int right = 0;
        int left = 0;

        for (int x = start; x <= mid; x++) {
            leftarr_copy[left] = arr[x];
            //cout << leftarr_copy[left] << " ";
            left++;
        }
        //cout << "left : " << left << endl;

        for (int x = mid + 1; x <= end; x++) {
            rightarr_copy[right] = arr[x];
            //cout << rightarr_copy[right] << " ";
            right++;
        }
        //cout << "right : " << right << endl;

        //cout << endl;

        int right_ptr = 0;
        int left_ptr = 0;
        int x = start;
        while (right_ptr < right && left_ptr < left) {
            if (rightarr_copy[right_ptr] < leftarr_copy[left_ptr]) {
//                cout << rightarr_copy[right_ptr] << " " << arr[x] << endl;
                arr[x] = rightarr_copy[right_ptr];
//                cout << "Right index: " << mid+1+right_ptr << " replacement position: " << x << endl;
//                cout << (mid + 1 + right_ptr) - x << endl;
                count += (long) ((mid + 1 + right_ptr) - x);
                right_ptr++;
                
            }
            else {
                arr[x] = leftarr_copy[left_ptr];
                left_ptr++;
            }
            x++;
        }
        if (left_ptr == left) {
            while (right_ptr < right) {
                arr[x] = rightarr_copy[right_ptr];
                x++;
                right_ptr++;
            }
        }
        else {
            while (left_ptr < left) {
                arr[x] = leftarr_copy[left_ptr];
                x++;
                left_ptr++;
            }
        }

        delete[] leftarr_copy;
        delete[] rightarr_copy;
        return;
    }
    
    
};


#endif /* SwapSort_h */
