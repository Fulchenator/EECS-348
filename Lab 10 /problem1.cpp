#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// holds parts of a number string
struct nums_parts {
    int sign;          // +1 or -1
    string intPart;    // digits before decimal
    string fracPart;   // digits after decimal
};
//Will remove the leading zeros
string remove_zeros(string s) {
    size_t i = 0;
    while (i + 1 < s.size() && s[i] == '0')
        i++;
    return s.substr(i);
}
//This will check if the string is a valid number
bool valid_num(string s) {
    if (s.empty())
        return false;
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    size_t start = i;
    while (i < s.size() && isdigit((unsigned char)s[i]))
        i++;
    if (i == start)
        return false;
    if (i == s.size())
        return true;
    if (s[i] != '.')
        return false;
    i++;
    size_t fracStart = i;
    while (i < s.size() && isdigit((unsigned char)s[i]))
        i++;
    if (i == fracStart)
        return false;
    return i == s.size();
}
//This will break the number into sign, int part, frac part
void split_nums(string s, int &sign_plus, string &int_num1, string &frac_num1) {
    sign_plus = 1;
    int_num1 = "";
    frac_num1 = "";
    size_t i = 0;
    if (s[i] == '+') { sign_plus = 1; i++; }
    else if (s[i] == '-') { sign_plus = -1; i++; }
    while (i < s.size() && isdigit((unsigned char)s[i])) {
        int_num1.push_back(s[i]);
        i++;
    }
    if (i < s.size() && s[i] == '.') {
        i++;
        while (i < s.size() && isdigit((unsigned char)s[i])) {
            frac_num1.push_back(s[i]);
            i++;
        }
    }
    int_num1 = remove_zeros(int_num1);
}
//Will compare the magnitudes
int compare_nums(string Ai, string Bi, string Aj, string Bj) {
    if (Ai.size() != Aj.size())
        return (Ai.size() < Aj.size() ? -1 : 1);
    if (Ai != Aj)
        return (Ai < Aj ? -1 : 1);

    size_t L = max(Bi.size(), Bj.size());
    for (size_t k = 0; k < L; k++) {
        char x = k < Bi.size() ? Bi[k] : '0';
        char y = k < Bj.size() ? Bj[k] : '0';
        if (x != y)
            return (x < y ? -1 : 1);
    }
    return 0;
}
//This will add positive the magnitudes
void add_positives(string Ai, string Bi, string Aj, string Bj, string &result_int, string &result_num) {
    size_t L = max(Bi.size(), Bj.size());
    int carry = 0;
    result_num = "";
    for (int k = (int)L - 1; k >= 0; k--) {
        int x = k < (int)Bi.size() ? Bi[k] - '0' : 0;
        int y = k < (int)Bj.size() ? Bj[k] - '0' : 0;

        int sum_digits = x + y + carry;
        result_num.insert(result_num.begin(), char('0' + (sum_digits % 10)));
        carry = sum_digits / 10;
    }
    result_int = "";
    int i = Ai.size() - 1;
    int j = Aj.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int x = i >= 0 ? Ai[i] - '0' : 0;
        int y = j >= 0 ? Aj[j] - '0' : 0;

        int sum_digits = x + y + carry;
        result_int.insert(result_int.begin(), char('0' + (sum_digits % 10)));
        carry = sum_digits / 10;

        i--;
        j--;
    }
    int t = result_num.size() - 1;
    while (t >= 0 && result_num[t] == '0')
        t--;
    if (t < 0) result_num = "";
    else result_num = result_num.substr(0, t + 1);
    result_int = remove_zeros(result_int);
}
//This will subtract magnitudes
void subtract_positives(string Ai, string Bi, string Aj, string Bj, string &result_int, string &result_num) {
    size_t L = max(Bi.size(), Bj.size());
    while (Bi.size() < L) Bi.push_back('0');
    while (Bj.size() < L) Bj.push_back('0');
    int borrow = 0;
    result_num = "";
    for (int k = (int)L - 1; k >= 0; k--) {
        int x = (Bi[k] - '0') - borrow;
        int y = Bj[k] - '0';
        if (x < y) { x += 10; borrow = 1; }
        else borrow = 0;
        result_num.insert(result_num.begin(), char('0' + (x - y)));
    }
    result_int = "";
    int i = Ai.size() - 1;
    int j = Aj.size() - 1;
    while (i >= 0 || j >= 0) {
        int x = i >= 0 ? Ai[i] - '0' : 0;
        int y = j >= 0 ? Aj[j] - '0' : 0;
        x -= borrow;
        if (x < y) { x += 10; borrow = 1; }
        else borrow = 0;
        result_int.insert(result_int.begin(), char('0' + (x - y)));
        i--;
        j--;
    }
    int t = result_num.size() - 1;
    while (t >= 0 && result_num[t] == '0')
        t--;
    if (t < 0) result_num = "";
    else result_num = result_num.substr(0, t + 1);
    result_int = remove_zeros(result_int);
}
string sum_string(string s1, string s2) {
    int sign_plus, sign_neg;
    string int_num1, frac_num1;
    string int_num2, frac_num2;
    split_nums(s1, sign_plus, int_num1, frac_num1);
    split_nums(s2, sign_neg, int_num2, frac_num2);
    string result_int, result_num;
    if (sign_plus == sign_neg) {
        add_positives(int_num1, frac_num1, int_num2, frac_num2, result_int, result_num);
        if (result_int == "0" && result_num == "")
            return "0";
        return (sign_plus < 0 ? "-" : "") + result_int + (result_num.empty() ? "" : "." + result_num);
    }
    int compare = compare_nums(int_num1, frac_num1, int_num2, frac_num2);
    if (compare == 0)
        return "0";
    if (compare > 0) {
        subtract_positives(int_num1, frac_num1, int_num2, frac_num2, result_int, result_num);
        return (sign_plus < 0 ? "-" : "") + result_int + (result_num.empty() ? "" : "." + result_num);
    } else {
        subtract_positives(int_num2, frac_num2, int_num1, frac_num1, result_int, result_num);
        return (sign_neg < 0 ? "-" : "") + result_int + (result_num.empty() ? "" : "." + result_num);
    }
}
//Main function that ask user for file input
int main() {
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;
    ifstream fin(filename);
    if (!fin) {
        cout << "Could not open file.\n";
        return 0;
    }
    string a, b;
    int line = 0;
    while (fin >> a >> b) {
        line++;
        bool ok1 = valid_num(a);
        bool ok2 = valid_num(b);
        if (!ok1 && !ok2) {
            cout << "Line " << line << ": both invalid -> '" << a << "' and '" << b << "'\n";
            continue;
        }
        if (!ok1) {
            cout << "Line " << line << ": invalid number -> '" << a << "'\n";
            continue;
        }
        if (!ok2) {
            cout << "Line " << line << ": invalid number -> '" << b << "'\n";
            continue;
        }
        cout << "Line " << line << ": " << a << " + " << b << " = " << sum_string(a, b) << "\n";
    }
    return 0;
}
