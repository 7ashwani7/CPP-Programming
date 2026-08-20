//  Modular Arithmetic m = 1000000007 or 998244353
//  Addition: ((a%m)+(b%m))%m
//  Subtraction: ((a%m)-(b%m)+m)%m
//  Multiplication: ((a%m)*(b%m))%m
#include<iostream>
using namespace std;
int const MOD = 1000000007;
long long power(long long a,long long b){
    long long ans = 1;
    while(b){
        if(b & 1) ans  = (ans * a) % MOD;
        a = (a * a) % MOD;
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