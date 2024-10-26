#include <iostream>
#include <string>

using namespace std;

int valueOfRoman(char r);
int convertRomanToInt(const string& s);

int main() {
    string romanNumeral;
    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral;

    int result = convertRomanToInt(romanNumeral);
    cout << "Decimal representation: " << result << endl;

    return 0;
}

int valueOfRoman(char r) {
    switch (r) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int convertRomanToInt(const string& s) {
    int total = 0;

    for (size_t i = 0; i < s.length(); i++) {
        int currentValue = valueOfRoman(s[i]);
        int nextValue = (i + 1 < s.length()) ? valueOfRoman(s[i + 1]) : 0;

        if (currentValue < nextValue) {
            total -= currentValue;
        }
        else {
            total += currentValue;
        }
    }
    return total;
}