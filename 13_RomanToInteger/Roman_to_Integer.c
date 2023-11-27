// Function in c Roman to Integer
int romanCharToInt(char c) {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int romanToInt(char *s) {
    int total = 0;
    int prevValue = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int currentValue = romanCharToInt(s[i]);
        total += currentValue;
        // handling cases where a smaller Roman numeral precedes a larger one.
        // In Roman numerals, this pattern indicates subtraction.
        if (prevValue < currentValue) {
            total -= 2 * prevValue;
        }

        prevValue = currentValue;
    }

    return total;
}

int main() {
    char *s = "MCMXCIV";
    int result = romanToInt(s);
    printf("%d", result);
    return 0;
}