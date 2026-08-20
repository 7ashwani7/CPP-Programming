//print all prime numbers from 1 to n using sieve of eratosthenes Time Complexity: O(n log(log n))
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }
    cout << "Prime numbers from 1 to " << n << " are: ";
    for(int i = 2; i <= n; i++){
        if(isPrime[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}