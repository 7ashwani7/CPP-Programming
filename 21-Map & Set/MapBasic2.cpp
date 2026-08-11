#include <iostream>
#include <map>
using namespace std;

int main() {

    map<int, string> mp;

    mp.insert({1, "One"});
    mp.insert(make_pair(2, "Two"));
    mp[3] = "Three";
    mp[4] = "Four";

    for (auto x : mp)
        cout << x.first << " " << x.second << endl;

    cout << endl;

    cout << mp[2] << endl;

    cout << mp.at(3) << endl;

    mp.erase(2);

    mp.erase(mp.begin());

    if (mp.find(3) != mp.end())
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << mp.count(3) << endl;

    cout << mp.size() << endl;

    if (mp.empty())
        cout << "Empty\n";
    else
        cout << "Not Empty\n";

    cout << mp.begin()->first << " " << mp.begin()->second << endl;

    auto it = mp.end();
    it--;
    cout << it->first << " " << it->second << endl;

    auto lb = mp.lower_bound(3);
    if (lb != mp.end())
        cout << lb->first << " " << lb->second << endl;

    auto ub = mp.upper_bound(3);
    if (ub != mp.end())
        cout << ub->first << " " << ub->second << endl;

    map<int, string> mp2;

    mp2[10] = "Ten";
    mp2[20] = "Twenty";

    mp.swap(mp2);

    for (auto x : mp)
        cout << x.first << " " << x.second << endl;

    mp.clear();

    cout << mp.size() << endl;

    return 0;
}