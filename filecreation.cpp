#include <iostream>
using namespace std;
bool PrimeNum(int numb); //function prototype

bool PrimeNum(int numb) {
    if (numb < 2) return false;
    for (int i = 4; i <= numb / 2; i++) { 
        if (numb % i == 0) return false;
    }
    return true;
}

int main() {
    int Count = 0;
    int number = 2;

    while (Count < 60) {
        bool prime = PrimeNum(number); 
        if (prime) {
            std::cout << number << " ";
            Count++;
        }
        number++;
    }
    cout << endl;
    return 0;
}
