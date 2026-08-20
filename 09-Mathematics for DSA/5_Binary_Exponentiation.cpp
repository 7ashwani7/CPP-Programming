#include<iostream>
using namespace std;

long long power(long long a,long long b){
    long long ans=1;
    while(b){
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main() {
    long long base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;
    cout << base << " raised to the power of " << exponent << " is " << power(base, exponent) << endl;
    return 0;
}