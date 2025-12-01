#include <iostream>
#include <queue>
using namespace std;

void sortQueue(queue<int>& q) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int size = q.size();
        int minElem = q.front();
        q.pop();
        q.push(minElem);

        for (int j = 1; j < size; j++) {
            int curr = q.front();
            q.pop();
            q.push(curr);

            if (curr < minElem)
                minElem = curr;
        }

        int countMin = 0;
        for (int j = 0; j < size; j++) {
            int curr = q.front();
            q.pop();

            if (curr == minElem && countMin == 0) {
                countMin++;  // Skip adding first occurrence of minElem now
            } else {
                q.push(curr);
            }
        }

        q.push(minElem);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
