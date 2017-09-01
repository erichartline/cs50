#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void) {
    float dollars;
    int change;
    int counter = 0;

    do {
        printf("O hai! How much change is owed?\n");
        dollars = get_float();
    }
    while (dollars < 0);

    change = round(dollars * 100);

    while (change >= 25) {
        counter++;
        change -= 25;
    }
    while (change >= 10) {
        counter++;
        change -= 10;
    }
    while (change >= 5) {
        counter++;
        change -= 5;
    }
    while (change >= 1) {
        counter++;
        change -= 1;
    }

    printf("%i\n", counter);
}
