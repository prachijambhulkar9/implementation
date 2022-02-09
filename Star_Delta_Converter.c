#include "Star_Delta_Converter.h"
float R1, R2, R3;
void print_Delta()
{
    printf("\n");
    int i, j, rows = 7;

    for (i = 1; i <= rows; i++)
    {
        for (j = i; j < rows; j++)
        {
            printf("  ");
        }
        for (j = 1; j <= (2 * i - 1); j++)
        {
            if (i == rows || j == 1 || j == (2 * i - 1))
            {
                if (i == 4 && j == 1)
                    printf("R1");
                else if (i == 4 && j == (2 * i - 1))
                    printf(" R2");
                else if (i == rows && j == 7)
                    printf("R3");
                else
                    printf(" ^");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("\n");
}

void print_Star()
{
    int i, j, rows = 7;
    printf("\n");
    for (int i = 1; i < 6; i++)
    {
        if (i == 4)
            printf("             R1\n");
        else
            printf("             ^\n");
    }
    for (i = 1; i < rows; i++)
    {
        for (j = i; j < rows; j++)
        {
            printf("  ");
        }
        for (j = 1; j <= (2 * i - 1); j++)
        {
            if (i == rows || j == 1 || j == (2 * i - 1))
            {
                if (i == 4 && j == 1)
                    printf("R2");
                else if (i == 4 && j == (2 * i - 1))
                    printf(" R3");
                else
                    printf(" ^");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void print_values(float R1, float R2, float R3)
{
    printf("\n\n------------------------\n");
    printf("Value of R1: %0.4f Ohm\n", R1);
    printf("Value of R2: %0.4f Ohm\n", R2);
    printf("Value of R3: %0.4f Ohm\n", R3);
    printf("------------------------\n\n");
}

void input()
{
    printf("------------------------\n");
    printf("Enter The Value of R1: ");
    scanf("%f", &R1);
    printf("Enter The Value of R2: ");
    scanf("%f", &R2);
    printf("Enter The Value of R3: ");
    scanf("%f", &R3);
    printf("------------------------\n\n");
}

void star_to_delta()
{
    float Ra, Rb, Rc;
    Ra = ((R1 * R2) + (R2 * R3) + (R3 * R1)) / R1;
    Rb = ((R1 * R2) + (R2 * R3) + (R3 * R1)) / R2;
    Rc = ((R1 * R2) + (R2 * R3) + (R3 * R1)) / R3;
    printf("After Converting Start To Delta The Values Are:");
    print_values(Rb, Rc, Ra);
}

void Delta_to_star()
{
    float Ra, Rb, Rc;
    Ra = (R1 * R2) / (R1 + R2 + R3);
    Rb = (R3 * R2) / (R1 + R2 + R3);
    Rc = (R3 * R1) / (R1 + R2 + R3);
    printf("After Converting Delta To Star The Values Are:");
    print_values(Ra, Rb, Rc);
}

int main()

{
    int ch;
    do
    {
        printf("\t\t\t\t------------MENUE-----------------\n");
        printf("\t\t\t\tpress 1 for Star To Delta Conversion\n");
        printf("\t\t\t\tpress 2 for Delta To Star Conversion\n");
        printf("\t\t\t\tpress 0 for Exit The Program\n");
        printf("\t\nEnter Your Choice:");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 1:
            print_Star();
            printf("Enter The Values of star Registers\n");
            input();
            star_to_delta();
            print_Delta();
            break;
        case 2:
            print_Delta();
            printf("Enter The Values of Delta Registers\n");
            input();
            Delta_to_star();
            print_Star();
            break;
        }

    } while (ch != 0);
    printf("\n Thanks For Using Our Program..........  \n");
    sleep(1);

    return 0;
}