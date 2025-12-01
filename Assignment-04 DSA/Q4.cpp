#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string s) {
    int freq[256] = {0};  
    queue<char> q;

    for (char ch : s) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << "-1 ";
    }
}

int main() {
    string input = "aabc";
    firstNonRepeating(input);
    return 0;
}

