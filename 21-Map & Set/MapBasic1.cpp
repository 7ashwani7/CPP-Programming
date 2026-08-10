#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<int, string> mp;

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

    unordered_map<int, string> mp2;

    mp2[10] = "Ten";
    mp2[20] = "Twenty";

    mp.swap(mp2);

    for (auto x : mp)
        cout << x.first << " " << x.second << endl;

    cout << "Bucket Count: " << mp.bucket_count() << endl;

    cout << "Bucket of key 10: " << mp.bucket(10) << endl;

    cout << "Load Factor: " << mp.load_factor() << endl;

    cout << "Max Load Factor: " << mp.max_load_factor() << endl;

    mp.reserve(100);

    mp.rehash(50);

    mp.clear();

    cout << mp.size() << endl;

    return 0;
}