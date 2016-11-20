#include <iostream>
#include <vector>

using namespace std;

string reverseWord(string s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        s[right] = s[right] + s[left];
        s[left] = s[right] - s[left];
        s[right] = s[right] - s[left];
    left++;
    right--;
    }
    return s;
}

int main() {
    string input = "This is an example";
    vector<string> words;
    int prev = 0;
    for (int i=0; i<input.length(); i++) {
        if (input[i] == ' ') {
            string word = (input.substr(prev, i - prev));
            words.push_back(word);
            prev = i+1;
        }
    }
    words.push_back(input.substr(prev));
    for (int i=0; i<words.size(); i++) {
        words[i] = reverseWord(words[i]);
        cout << words[i] << " ";
    }

}