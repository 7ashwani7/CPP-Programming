#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(20);
    s.insert(40);
    s.insert(50);

    for (auto x : s) cout << x << " ";

    cout << endl;

    s.erase(20);

    s.erase(s.begin());

    if(s.find(30) != s.end()) cout << "30 Found\n";
    else cout << "30 Not Found\n";

    cout << s.count(30) << endl;

    cout << s.size() << endl;

    if(s.empty()) cout << "Empty\n";
    else cout << "Not Empty\n";

    cout << *s.begin() << endl;

    auto it = s.end();
    it--;
    cout << *it << endl;

    cout << *s.rbegin() << endl;

    for(auto it = s.rbegin(); it != s.rend(); it++) cout << *it << " ";

    cout << endl;

    auto lb = s.lower_bound(25);
    if(lb != s.end()) cout << *lb << endl;

    auto ub = s.upper_bound(25);
    if(ub != s.end()) cout << *ub << endl;

    set<int> s2 = {100, 200, 300};

    s.swap(s2);

    for(auto x : s) cout << x << " ";

    cout << endl;

    s.clear();

    cout << s.size() << endl;

    return 0;
}