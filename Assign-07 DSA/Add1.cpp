#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &arr) {
    int ans = 0, cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (cnt == 0) {
            ans = arr[i];
            cnt = 1;
        } else {
            if (arr[i] == ans)
                cnt++;
            else
                cnt--;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << majorityElement(arr);
    return 0;
}
