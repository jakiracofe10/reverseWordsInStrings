#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input = "This is an example";
    vector<string> words;
    int prev = 0;
    for (int i=0; i<input.length(); i++) {
        if (input[i] == ' ') {
            string word = (input.substr(prev, i - prev));
            words.push_back(word);
            prev = i;
        }
    }
    words.push_back(input.substr(prev));
    for (int i=0; i<words.size(); i++) {
        int left = 0;
        int right = words[i].length() - 1;
        while (left < right) {
            words[i][right] = words[i][right] + words[i][left];
            words[i][left] = words[i][right] - words[i][left];
            words[i][right] = words[i][right] - words[i][left];
            left++;
            right--;
        }
        cout << words[i] << " ";
    }

}