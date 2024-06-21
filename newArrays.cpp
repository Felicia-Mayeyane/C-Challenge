#include <iostream>
using namespace std;

int* FirstLastArray(int* arr, int ArraySize, int* newArraySize); // Function prototype

int main() {
int arr[] = {8, 4, 13, 14, 15};
int ArraySize = sizeof(arr) / sizeof(arr[0]);
int newArraySize; //declaring data type of newarraysize

int* newArr = FirstLastArray(arr, ArraySize, &newArraySize);
if (newArr != nullptr) {
cout << "This is the new array: ";
for (int i = 0; i < newArraySize; i++) {
cout << newArr[i] << " ";
}
std::cout << endl;
delete[] newArr;
}
return 0;
}

int* FirstLastArray(int* arr, int ArraySize, int* newArraySize) {
if (ArraySize <= 2) {
*newArraySize = 0;
return nullptr; //set conditon, if array size is less than 2 array size goes to 0 and returns a nullptr
} //this itereation sets the conditions of the element to be in the array
*newArraySize = ArraySize - 2;
int* newArr = new int[*newArraySize];
for (int i = 1; i < ArraySize - 1; i++) {
newArr[i - 1] = arr[i];
}
return newArr;
}
