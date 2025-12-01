#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> k;

    int uniq[1000], freq[1000];
    int m = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < m; j++) {
            if (uniq[j] == arr[i]) {
                found = j;
                break;
            }
        }
        if (found == -1) {
            uniq[m] = arr[i];
            freq[m] = 1;
            m++;
        } else {
            freq[found]++;
        }
    }

    // bubble sort (sort by freq desc, if tie, by number desc)
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (freq[j] < freq[j + 1] ||
               (freq[j] == freq[j + 1] && uniq[j] < uniq[j + 1])) {

                int t = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = t;

                t = uniq[j];
                uniq[j] = uniq[j + 1];
                uniq[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < k; i++)
        cout << uniq[i] << " ";

    return 0;
}
