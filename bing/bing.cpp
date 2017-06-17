#include <iostream>
#include <cstring>

using namespace std;

struct node
{
    node *children[26];
    int count;

    node() {
        memset(children, 0, sizeof(children));
        count = 0;
    }    
};

void insert(node *nd, string &s, int n) {
    if (n != s.length()) {
        if (!nd->children[s.at(n)-'a']) {
            nd->children[s.at(n)-'a'] = new node();
        }
        nd->count++;
        insert(nd->children[s.at(n)-'a'], s, n+1);
    }
    else {
        nd->count++;
    }
}

int count(node *nd, string &s, int n) {
    if (n != s.length()) {
        return count(nd->children[s.at(n)-'a'], s, n+1);
    }
    else {
        return nd->count;
    }
}

int main() {
    int N;
    string str;
    node *trie = new node();
    scanf("%d\n", &N);
    while(N--) {
        cin >> str;
        insert(trie, str, 0);
        printf("%d\n", count(trie, str, 0)-1);
    }
}
