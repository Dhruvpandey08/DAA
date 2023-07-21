#include <iostream>
#include <string>
using namespace std;

class RabinKarp {
public:
    int rabinKarpSearch(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();

        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                return i; // Pattern found at index i in the text
            }
        }

        return -1; // Pattern not found in the text
    }
};

int main() {
    RabinKarp rk;
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern to search: ";
    cin >> pattern;

    int pos = rk.rabinKarpSearch(text, pattern);
    if (pos != -1) {
        cout << "Pattern found at index " << pos << " in the text." << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}