class Solution {
public:
    std::string parse(int& ptr, std::string& s) {
        std::string output = "";
        int exponenta = 0;
        while (ptr < s.size()) {
            if (s[ptr] == '[') {
                ++ptr;
                std::string result = parse(ptr, s);
                for (int i = 0; i < exponenta; ++i) output += result;
                exponenta = 0;
            } else if (s[ptr] == ']') {
                ++ptr;
                return output;
            }
            else if (std::isdigit(s[ptr])) exponenta = exponenta * 10 + (s[ptr++] - '0');
            else output.push_back(s[ptr++]);
        }
        return output;
    }
    string decodeString(string s) {
        int start = 0;
        return parse(start, s);
    }
};