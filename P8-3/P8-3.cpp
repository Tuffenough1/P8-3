#include <iostream>
#include <string>

using namespace std;

int valueOfRoman(char r);
int romanToDecimal(string roman);

int main() {
    string romanNumeral;
    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral;

    int result = romanToDecimal(romanNumeral);
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

int romanToDecimal(string roman) {
    int decimalValue = 0;
    int length = roman.length();

    for (int i = 0; i < length; i++) {
        int currentValue = valueOfRoman(roman[i]);
        int nextValue = (i < length - 1) ? valueOfRoman(roman[i + 1]) : 0;

        if (currentValue < nextValue) {
            decimalValue -= currentValue;
        }
        else {
            decimalValue += currentValue;
        }
    }
    return decimalValue;
}