#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string arr[500];
int n;

int main() {
    while (1) {
        cin >> n;
        if (n == 0) break;
        map<char, vector<int> > aMap;
        int uniques = 0;
        int collisions = 0;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            getline(cin, arr[i]);
        } 
        for (int i = 0; i < n; i++) {
            string str = arr[i];
            // cout << str << endl;
            char hash = (char) 0;
            for (int j = 0; j < str.length(); j++) {
                hash ^= str.at(j);
            }
            if (aMap.find(hash) == aMap.end()) {
                aMap[hash].push_back(i); 
                uniques++;
            }
            else {
                std::vector<int> v = aMap[hash];
                int ind = 0;
                for (int k = 0; k < v.size(); k++) {
                    if (arr[v.at(k)].compare(arr[i]) != 0) {
                        collisions++;
                    }
                    else ind = 1;
                } 
                if (ind == 0) uniques++;
                aMap[hash].push_back(i);
            }

        } 
        cout << uniques << " " << collisions << endl;

    }

}