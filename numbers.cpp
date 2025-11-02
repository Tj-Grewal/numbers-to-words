#include <iostream>
#include <string>
using namespace std;

// Converts integers to words
string intToString(int number);

// Prints integers to words over the range of specified interval
void printIntStrings(int start, int end, int interval);

// Function prototypes
string upToTeens(int number);
string twentyThroughNinety(int number);
string singlesToWords(int number);
string hundredsToWords(int number);
string thousandsToWords(int number);

int main() {
    printIntStrings(0, 21543, 13);
    return 0;
}

void printIntStrings(int start, int end, int interval) {

    // If the start of the interval is less than the end
    // Print by incrementing on the specified interval
    if (start < end) {
        for (int i = start; i <= end; i += interval) {
            cout << intToString(i) << endl;
        }
    }
    // If the start of the interval is greater than the end
    // Print by decrementing on the specified interval
    if (end < start) {
        for (int j = start; j >= end; j -= interval) {
            cout << intToString(j) << endl;
        }
    }
    // If the start is equal to the end, print only the start value
    if (start == end) {
        cout << intToString(start) << endl;
    }
}

string intToString(int number) {

    // If number is 0
    if (number == 0) {
        return upToTeens(number);
    }
    // If number is between 1 and 100,
    // send to function for converting integers less than a hundred to words
    else if (1 <= number && number < 100) {
        return singlesToWords(number);
    }
    // If number is between 100 and 1000,
    //send to function for converting intergers in hundreds to words
    else if (100 <= number && number < 1000) {
        return hundredsToWords(number);
    }
    // If number is between 1000 and 100000,
    //send to function for converting intergers in thousands to words
    else if (1000 <= number && number < 100000) {
        return thousandsToWords(number);
    }
    else {
        return ("error");
    }
}

// Function for converting numbers in thousands to words
string thousandsToWords(int number) {

    // There are exactly TWO cases. FIRST CASE where integers are between 20 and 100 range
    // SECOND CASE where they are all individual words from 0 to 19
    // as otherwise called singleInput for the individual number they represent

    // Extract digits from number for the thousands
    int digitForThousand = (number % 10000) / 1000;
    int digitForTenThousand = number / 1000;

    // Checking remainders if any in tens and hundreds
    int remInTens = number % 100;
    int remInHundreds = number % 1000;

    // Initialize string out for returning integers to words
    string outPhrase = "";

    // If number is between 20000 and 100000, FIRST CASE
    if (20000 <= number && number < 100000) {

        // String for storing thousands in tens range
        string tenThousand = twentyThroughNinety(digitForTenThousand);

        // Check if there are digits in the one thousands place after tens
        // Print thousands in tens followed by thousands in ones place
        if (digitForThousand != 0) {

            // String for storing thousdands in ones range
            string ones = upToTeens(digitForThousand);

            // If there are remainders in hundreds, add a comma and
            // send the remainder to function for converting hundreds to words
            if (remInHundreds != 0 && remInHundreds >= 100) {
                outPhrase += tenThousand + "-" + ones + " thousand, " + hundredsToWords(remInHundreds);
            }
            // If there are no remainders in hundreds and and only remainders in tens range
            // Add "and"  and send the remainder to function for converting words less than a hundred
            else if (remInTens != 0 && remInHundreds < 100) {
                outPhrase += tenThousand + "-" + ones + " thousand and " + singlesToWords(remInHundreds);
            }
            // If the remainder is zero print thousand
            else if (remInHundreds == 0) {
                outPhrase += tenThousand + "-" + ones + " thousand ";
            }
        }
        // If there are digits in tens thousands and no digits in ones thousdands
        // follow the above logic and omit the call for thousands in ones
        else if (digitForThousand == 0) {

            if (remInHundreds != 0 && remInHundreds >= 100) {
                outPhrase += tenThousand + " thousand, " + hundredsToWords(remInHundreds);
            }
            else if (remInTens != 0 && remInHundreds < 100) {
                outPhrase += tenThousand + " thousand and " + hundredsToWords(remInHundreds);
            }
            else if (remInHundreds == 0) {
                outPhrase += tenThousand + " thousand ";
            }
        }
    }

    // If the number is between 1000 and 20000, SECOND CASE
    if (1000 <= number && number < 20000) {

        // String for storing the individual inputs from 1 to 19 thousand
        string thousand = upToTeens(digitForTenThousand);

        // If there are remainders in hundreds, add a comma and
        // send the remainder to function for converting hundreds to words
        if (remInHundreds != 0 && remInHundreds >= 100) {
            outPhrase += thousand + " thousand, " + hundredsToWords(remInHundreds);
        }
        // If there are no remainders in hundreds and remainders in tens range
        // Send the remainder to function for converting words less than a hundred
        else if (remInTens != 0 && remInHundreds < 100) {
            outPhrase += thousand + " thousand and " + hundredsToWords(remInHundreds);
        }
        // If the remainder is zero in hundreds then only print thousand
        else if (remInHundreds == 0) {
            outPhrase += thousand + " thousand ";
        }
    }
    // Return the modified string
    return outPhrase;
}

// Function for converting numbers in hundreds to words
string hundredsToWords(int remInhundreds) {

    // Initialize string out for returning integers to words
    string outPhrase = "";

    // Extract digit for hundred and find remainder in tens range
    int digitForhundred = remInhundreds / 100;
    int remIntens = remInhundreds % 100;

    // If remainder in hundreds is between 100 and 1000
    if (100 <= remInhundreds && remInhundreds < 1000) {

        // String for hundreds
        string hundred = upToTeens(digitForhundred);

        // If there are remainders in tens, add "and" and
        // send to function for converting remaining integers to words
        if (remIntens != 0) {
            outPhrase += hundred + " hundred and " + singlesToWords(remIntens);
        }
        // If there are no remainders in tens print only hundred
        else if (remIntens == 0) {
            outPhrase += hundred + " hundred ";
        }
    }
    // If remainder in hundreds is between 1 and 100
    // Send to function for converting remaining integers to words
    else if (1 <= remInhundreds && remInhundreds < 100) {
        outPhrase += singlesToWords(remIntens);
    }
    // Return the modified string
    return outPhrase;
}

// Function for converting numbers less than hundred to words
string singlesToWords(int remIntens) {

    // Initialize string out for returning integers to words
    string outPhrase = "";
    // Check if any digits left in ones place
    int singleRem = remIntens % 10;

    // FIRST CASE - If number is between 20 and 100
    if (20 <= remIntens && remIntens < 100) {
        string nameInTens = twentyThroughNinety(remIntens);
        if (singleRem != 0) {
            string ones = upToTeens(singleRem);
            outPhrase += nameInTens + "-" + ones;
        }
        else outPhrase += nameInTens;
    }
    // SECOND CASE - If number is between 1 and 19 inclusive
    else if (1 <= remIntens && remIntens < 20) {
        string singles = upToTeens(remIntens);
        outPhrase += singles;
    }
    // Return the modified string
    return outPhrase;
}

string twentyThroughNinety(int number) {

    // FIRST CASE - twenty's through ninety's
    if (number >= 90) return "ninety";
    else if (number >= 80) return "eighty";
    else if (number >= 70) return "seventy";
    else if (number >= 60) return "sixty";
    else if (number >= 50) return "fifty";
    else if (number >= 40) return "forty";
    else if (number >= 30) return "thirty";
    else if (number >= 20) return "twenty";
    return "";
}

string upToTeens(int number) {

    // SECOND CASE - All individual words zero to nineteen
    if (number == 0) return "zero";
    else if (number == 1) return "one";
    else if (number == 2) return "two";
    else if (number == 3) return "three";
    else if (number == 4) return "four";
    else if (number == 5) return "five";
    else if (number == 6) return "six";
    else if (number == 7) return "seven";
    else if (number == 8) return "eight";
    else if (number == 9) return "nine";
    else if (number == 10) return "ten";
    else if (number == 11) return "eleven";
    else if (number == 12) return "twelve";
    else if (number == 13) return "thirteen";
    else if (number == 14) return "fourteen";
    else if (number == 15) return "fifteen";
    else if (number == 16) return "sixteen";
    else if (number == 17) return "seventeen";
    else if (number == 18) return "eighteen";
    else if (number == 19) return "nineteen";
    return "";
}
