#include<iostream>
using namespace std;
//Euclid Algorithm
int gcd1(int a, int b) {
    if (b == 0) return a;
    return gcd1(b, a % b);
}
//Brute Force Method
int gcd2(int a, int b){
    int ans = 1;
    for(int i = 1; i <= min(a,b); i++){
        if(a % i == 0 && b % i == 0) ans = i;
    }
    return ans;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << "GCD of " << x << " and " << y << " is " << gcd1(x, y) << endl;
    cout << "GCD of " << x << " and " << y << " is " << gcd2(x, y) << endl;
    return 0;
}