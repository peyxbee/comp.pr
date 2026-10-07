#include <stdio.h>

int main()
{
    int n;
    int i;
    double product = 1.0;
    double numerator;
    double denominator;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            numerator = i + 1;
            denominator = i;
        }
        else
        {
            numerator = i;
            denominator = i + 1;
        }

        product *= numerator / denominator;
    }

    printf("Product = %lf\n", product);

    return 0;
}