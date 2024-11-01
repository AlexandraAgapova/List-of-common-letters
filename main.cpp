#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter number of words: ";
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    set<char> commonLetters(words[0].begin(), words[0].end());

    for (int i = 1; i < n; ++i) {
        set<char> currentWordLetters(words[i].begin(), words[i].end());
        set<char> intersection;

        set_intersection(commonLetters.begin(), commonLetters.end(),
                              currentWordLetters.begin(), currentWordLetters.end(),
                              inserter(intersection, intersection.begin()));

        commonLetters = intersection; // обновляем общие буквы
    }

    for (char c : commonLetters) {
        cout << c;
    }

    return 0;
}
