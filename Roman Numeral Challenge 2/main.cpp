#include <iostream>
#include <string>
using namespace std;

int main() {

    // Determine whether the user wants to convert a Roman numeral to an English number or vice-versa.
    string conversionPath;
    cout << "Type \"RE\" to convert a Roman numeral to an English number,"
            "or type \"ER\" to convert an English number to a Roman numeral: ";
    cin >> conversionPath;
    cout << endl;

    // The following code converts a Roman numeral to an English number.
    if (conversionPath == "RE") {
        string romanNumeral;
        int englishNum1 = 0;
        cout << "Please type the Roman numeral you wish to convert "
                "(all CAPS, no spaces, and end your entry with a period): ";
        cin >> romanNumeral;
        cout << endl;

        int endLoop = static_cast<int>(romanNumeral.find('.'));
        if (endLoop == string::npos) {
            cout << "You forgot to end your entry with a period." << endl;
            cout << "Please try again." << endl;
        }
        else {
            int tempIndex;
            //Program loops until it reaches the end of the users entry.
            for (tempIndex = 0; tempIndex < endLoop; ++tempIndex) {
                char char1 = romanNumeral.at(tempIndex);
                if (char1 == 'M') {
                    englishNum1 += 1000;
                }
                else if (char1 == 'D') {
                    englishNum1 += 500;
                }
                else if (char1 == 'C') {
                    if (romanNumeral.at(tempIndex + 1) == 'M') {
                        englishNum1 += 900;
                        tempIndex += 1;
                    }
                    else if (romanNumeral.at(tempIndex + 1) == 'D') {
                        englishNum1 += 400;
                        tempIndex += 1;
                    }
                    else {
                        englishNum1 += 100;
                    }
                }
                else if (char1 == 'L') {
                    englishNum1 += 50;
                }
                else if (char1 == 'X') {
                    if (romanNumeral.at(tempIndex + 1) == 'C') {
                        englishNum1 += 90;
                        tempIndex += 1;
                    }
                    else if (romanNumeral.at(tempIndex + 1) == 'L') {
                        englishNum1 += 40;
                        tempIndex += 1;
                    }
                    else {
                        englishNum1 += 10;
                    }
                }
                else if (char1 == 'V') {
                    englishNum1 += 5;
                }
                else if (char1 == 'I') {
                    if (romanNumeral.at(tempIndex + 1) == 'X') {
                        englishNum1 += 9;
                        tempIndex += 1;
                    }
                    else if (romanNumeral.at(tempIndex + 1) == 'V') {
                        englishNum1 += 4;
                        tempIndex += 1;
                    }
                    else {
                        englishNum1 += 1;
                    }
                }
            }
            romanNumeral = romanNumeral.substr(0, romanNumeral.size() - 1);
            cout << "The English number equivalent of the Roman numeral \"";
            cout << romanNumeral << "\" is " << englishNum1 << "." << endl;
        }
    }

    // Program to convert an English number into a Roman numeral.
    else if (conversionPath == "ER") {
        int englishNum = 0;
        int remainder = 0;
        int numM = 0;
        int numD = 0;
        int numC = 0;
        int numL = 0;
        int numX = 0;
        int numV = 0;
        int numI = 0;
        cout << "Please type the English number you wish to convert (excluding commas): ";
        // English number must be less than 3999.
        cin >> englishNum;
        cout << endl;
        cout << "The Roman numeral equivalent of the English number \"" << englishNum << "\" is ";

        // Determine the thousands place.
        numM = englishNum / 1000;
        if (numM == 1) {
            cout << "M";
        }
        else if (numM == 2) {
            cout << "MM";
        }
        else if (numM == 3) {
            cout << "MMM";
        }

        // Determine the hundreds place.
        remainder = englishNum % 1000;
        numD = remainder / 500;
        remainder = remainder % 500;
        numC = remainder / 100;
        if (numD == 1) {
            if (numC == 4) {
                cout << "CM";
            }
            else {
                cout << "D";
            }
            if (numC == 1) {
                cout << "C";
            }
            else if (numC == 2) {
                cout << "CC";
            }
            else if (numC == 3) {
                cout << "CCC";
            }
        }
        else if (numC == 1) {
            cout << "C";
        }
        else if (numC == 2) {
            cout << "CC";
        }
        else if (numC == 3) {
            cout << "CCC";
        }
        else if (numC == 4) {
            cout << "CD";
        }

        // Determine the tens place.
        remainder = remainder % 100;
        numL = remainder / 50;
        remainder = remainder % 50;
        numX = remainder / 10;
        if (numL == 1) {
            if (numX == 4) {
                cout << "XC";
            }
            else {
                cout << "L";
            }
            if (numX == 1) {
                cout << "X";
            }
            else if (numX == 2) {
                cout << "XX";
            }
            else if (numX == 3) {
                cout << "XXX";
            }
        }
        else if (numX == 1) {
            cout << "X";
        }
        else if (numX == 2) {
            cout << "XX";
        }
        else if (numX == 3) {
            cout << "XXX";
        }
        else if (numX == 4) {
            cout << "XL";
        }

        // Determine the ones place.
        remainder = remainder % 10;
        numV = remainder / 5;
        remainder = remainder % 5;
        numI = remainder / 1;
        if (numV == 1) {
            if (numI == 4) {
                cout << "IX";
            }
            else {
                cout << "V";
            }
            if (numI == 1) {
                cout << "I";
            }
            else if (numI == 2) {
                cout << "II";
            }
            else if (numI == 3) {
                cout << "III";
            }
        }
        else if (numI == 1) {
            cout << "I";
        }
        else if (numI == 2) {
            cout << "II";
        }
        else if (numI == 3) {
            cout << "III";
        }
        else if (numI == 4) {
            cout << "IV";
        }
        cout << "." << endl;
    }
    return 0;
}