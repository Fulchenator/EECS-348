//Temperature converter
#include <stdio.h>

int main() {
    double temp, result;
    char from, to;

    printf("Enter temperature value: ");
    scanf("%lf", &temp);

    printf("Enter original scale (C, F, or K): ");
    scanf(" %c", &from);

    printf("Enter scale to convert to (C, F, or K): ");
    scanf(" %c", &to);

    // Will convert everything using the basic formulas
    if (from == 'C' && to == 'F') {
        result = (temp * 9 / 5) + 32;
    }
    else if (from == 'C' && to == 'K') {
        result = temp + 273.15;
    }
    else if (from == 'F' && to == 'C') {
        result = (temp - 32) * 5 / 9;
    }
    else if (from == 'F' && to == 'K') {
        result = (temp - 32) * 5 / 9 + 273.15;
    }
    else if (from == 'K' && to == 'C') {
        result = temp - 273.15;
    }
    else if (from == 'K' && to == 'F') {
        result = (temp - 273.15) * 9 / 5 + 32;
    }
    else {
        result = temp; // The same scale or bad input
    }

    printf("Converted temperature: %.2f %c\n", result, to);

    // This figures out how it feels based on Celsius value
    double celsius;

    if (to == 'C') {
        celsius = result;
    } else if (to == 'F') {
        celsius = (result - 32) * 5 / 9;
    } else { // K
        celsius = result - 273.15;
    }

    if (celsius < 0)
        printf("Temperature category: Freezing\nWear a coat!\n");
    else if (celsius < 10)
        printf("Temperature category: Cold\nPut on a jacket.\n");
    else if (celsius < 25)
        printf("Temperature category: Comfortable\nEnjoy the weather.\n");
    else if (celsius < 35)
        printf("Temperature category: Hot\nDrink water.\n");
    else
        printf("Temperature category: Extreme Heat\nStay inside!\n");

    return 0;
}
