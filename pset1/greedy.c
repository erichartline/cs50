#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    float change;
    float roundedChange;
    int count = 0;

    do {
        printf("O hai! How much change is owed?");
        change = get_float();
    }
    while (change < 0);

    change = change * 100;
    roundedChange = round(change);

    while (roundedChange >= 25)
    {
        count++;
        roundedChange -= 25;
    }
    while (roundedChange >= 10)
    {
        count++;
        roundedChange -= 10;
    }
    while (roundedChange >= 5)
    {
        count++;
        roundedChange -= 5;
    }
    while (roundedChange >= 1)
    {
        count++;
        roundedChange -= 1;
    }

    printf("%i\n", count);
}
