#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = static_cast<int>(s.size()) - 1;

        while (start < end) {
            // Skip non-alphanumeric characters from the left
            while (start < end && !isalnum(static_cast<unsigned char>(s[start]))) {
                start++;
            }
            // Skip non-alphanumeric characters from the right
            while (start < end && !isalnum(static_cast<unsigned char>(s[end]))) {
                end--;
            }

            if (tolower(static_cast<unsigned char>(s[start])) != 
                tolower(static_cast<unsigned char>(s[end]))) {
                return false;
            }

            start++;
            end--;
        }
        return true;
    }
};
