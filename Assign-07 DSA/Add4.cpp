#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int even[1000], odd[1000];
    int e = 0, o = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) even[e++] = arr[i];
        else odd[o++] = arr[i];
    }

    for (int i = 0; i < e - 1; i++)
        for (int j = 0; j < e - i - 1; j++)
            if (even[j] > even[j + 1]) {
                int t = even[j];
                even[j] = even[j + 1];
                even[j + 1] = t;
            }

    for (int i = 0; i < o - 1; i++)
        for (int j = 0; j < o - i - 1; j++)
            if (odd[j] < odd[j + 1]) {
                int t = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = t;
            }

    for (int i = 0; i < e; i++)
        cout << even[i] << " ";

    for (int i = 0; i < o; i++)
        cout << odd[i] << " ";

    return 0;
}
