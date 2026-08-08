#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

    unordered_set<int> us;

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(20);

    for (auto x : us)
        cout << x << " ";

    cout << endl;

    us.erase(20);

    us.erase(us.begin());

    if (us.find(30) != us.end())
        cout << "30 Found\n";
    else
        cout << "30 Not Found\n";

    cout << us.count(30) << endl;

    cout << us.size() << endl;

    if (us.empty())
        cout << "Empty\n";
    else
        cout << "Not Empty\n";

    cout << *us.begin() << endl;

    unordered_set<int> us2 = {100, 200, 300};

    us.swap(us2);

    for (auto x : us)
        cout << x << " ";

    cout << endl;

    us.clear();

    cout << us.size() << endl;

    return 0;
}