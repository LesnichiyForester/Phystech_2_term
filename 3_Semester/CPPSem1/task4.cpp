#include <iostream>
using std::cout;
using std::endl;
using std::isalpha;
using std::isdigit;


void countLetters(const char* str, int& numLetters, int& numDigits, int& numOther) {
    numLetters = 0;
    numDigits = 0;
    numOther = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]))
            numLetters += 1;
        else if (isdigit(str[i]))
            numDigits += 1;
        else
            numOther += 1;
    }
}

int main() {
    const char* str = "Episode 5: The Empire Strikes Back";
    int numLetters = 0;
    int numDigits = 0;
    int numOther = 0;
    countLetters(str, numLetters, numDigits, numOther);
    cout << "Letters:" << numLetters << endl;
    cout << "Digits:" << numDigits << endl;
    cout << "Others:" << numOther << endl;
}