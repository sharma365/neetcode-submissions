#include <string>
using namespace std;

class Solution {
private:
    bool isAlphaNum(char c) const {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }

    char toLowerManual(char c) const {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }
        return c;
    }

public:
    bool isPalindrome(const string& s) {
        int start = 0;
        int end = static_cast<int>(s.size()) - 1;

        while (start < end) {
            while (start < end && !isAlphaNum(s[start])) {
                start++;
            }
            while (start < end && !isAlphaNum(s[end])) {
                end--;
            }

            if (toLowerManual(s[start]) != toLowerManual(s[end])) {
                return false;
            }

            start++;
            end--;
        }
        return true;
    }
};
