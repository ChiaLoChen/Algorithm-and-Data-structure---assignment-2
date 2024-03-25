#include <iostream>
#include <vector>
using namespace std;
vector<int> productID;

void printArray() {
    cout << productID[0];
    for (int i = 1; i < productID.size(); i++) {
        cout << ", " << productID[i];
    };
    cout << endl;
}
void merge(vector<int>& arr, int low, int middle, int high) {
    int n1 = middle - low + 1;
    int n2 = high - middle;
    vector<int> L(n1);
    vector<int> H(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++) {
        H[i] = arr[middle + 1 + i];
    }
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= H[j]) {
            arr[low] = L[i];
            i++;
        }
        else {
            arr[low] = H[j];
            j++;
        }
        low++;
    }
    while (i < n1) {
        arr[low] = L[i];
        i++;
        low++;
    }
    while (j < n2) {
        arr[low] = H[j];
        j++;
        low++;
    }

}
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
        printArray();
    }
}
int main()
{
    cout << "Task 1:\n";
    cout << "Mergesort:\n";
    cout << "11, 1, 30, 2, 51, 6, 29, 7, 67, 15, 118, 4, 89, 23\n";
    cout << "(1, 11) (2, 30) (6, 51) (7, 29) (15, 67) (4, 118) (23, 89)\n";
    cout << "(1, 2, 11, 30) (6, 7, 29, 51) (4, 15, 67, 118) (23, 89)\n";
    cout << "(1, 2, 6, 7, 11, 29, 30, 51) (4, 15, 23, 67, 89, 118)\n";
    cout << "1, 2, 4, 6, 7, 11, 15, 23, 29, 30, 51, 67, 89, 118\n\n";
    cout << "Quicksort:\n";
    cout << "(11) 1, 30, 2, 51, 6, 29, 7, 67, 15, 118, 4, 89, 23\n";
    cout << "1, 2, 6, 7, 4 (11) 30, 51, 29, 67, 15, 118, 89, 23\n";
    cout << "1, 2, 6, 7, 4, 11 (30) 51, 29, 67, 15, 118, 89, 23\n";
    cout << "1, 2, 6, 7, 4, 11, 29, 15, 23 (30) 51, 67, 118, 89\n";
    cout << "1, 2, 6, 7, 4, 11, 29, 15, 23, 30 (51) 67, 118, 89\n";
    cout << "1, 2, 6, 7, 4, 11, 29, 15, 23, 30, 51 (67) 118, 89\n";
    cout << "1, 2, 6, 7, 4, 11, 29, 15, 23, 30, 51, 67 (118) 89\n";
    cout << "1, 2, 6, 7, 4, 11, 29, 15, 23, 30, 51, 67, 89 (118)\n";
    cout << "(1) 2, 6, 7, 4, 11, 29, 15, 23, 30, 51, 67, 89, 118\n";
    cout << "1, (2) 6, 7, 4, 11, 29, 15, 23, 30, 51, 67, 89, 118\n";
    cout << "1, 2, (6) 7, 4, 11, 29, 15, 23, 30, 51, 67, 89, 118\n";
    cout << "1, 2, 4 (6) 7, 11, 29, 15, 23, 30, 51, 67, 89, 118\n\n";

    cout << "Task 2:\n";
    bool out = false;
    int num;
    string answer;
    //this is just to save time from inserting numbers one by one
    /*productID.push_back(11);
    productID.push_back(1);
    productID.push_back(30);
    productID.push_back(2);
    productID.push_back(51);
    productID.push_back(6);
    productID.push_back(29);
    productID.push_back(7);
    productID.push_back(67);
    productID.push_back(15);
    productID.push_back(118);
    productID.push_back(4);
    productID.push_back(89);
    productID.push_back(3);*/
    while (!out) {
        cout << "please insert an integer for merge sort\n";
        cin >> num;
        productID.push_back(num);
        printArray();
        cout << "Do you wish to conduct merge sort? Y/N\n";
        cin >> answer;
        if (answer == "Y") {
            cout << "You have begin to conduct merge sort\n";
            mergeSort(productID, 0, productID.size() - 1);
            out = true;
        }
        else {
            cout << "ok letz continue\n";
        }
    }
}