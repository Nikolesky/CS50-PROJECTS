#include <stdio.h>

int main(void)
{
    int date, month, year, odd_days_century, odd_days_year, odd_days_month, i, j, day;
    printf("ENTER A DATE (dd mm yyyy format):");
    scanf("%d %d %d", &date, &month, &year);

    year--;
    // odd_days_century calculation

    i = (year / 100) % 4;
    switch (i)
    {
        case 0:
            odd_days_century = 0;
            break;
        case 1:
            odd_days_century = 5;
            break;
        case 2:
            odd_days_century = 3;
            break;
        case 3:
            odd_days_century = 1;
            break;
    }
    // odd_days_year calculation

    odd_days_year = (year % 100) + ((year % 100) / 4);

    // odd_days_month calculation
    if (((year + 1) % 4 != 0) || (year % 100 == 0 && year % 400 != 0))
    {
        switch (month)
        {
            case 1:
                odd_days_month = 0;
                break;

            case 2:
                odd_days_month = 3;
                break;

            case 3:
                odd_days_month = 3;
                break;

            case 4:
                odd_days_month = 6;
                break;

            case 5:
                odd_days_month = 1;
                break;

            case 6:
                odd_days_month = 4;
                break;

            case 7:
                odd_days_month = 6;
                break;

            case 8:
                odd_days_month = 2;
                break;

            case 9:
                odd_days_month = 5;
                break;

            case 10:
                odd_days_month = 0;
                break;

            case 11:
                odd_days_month = 3;
                break;

            case 12:
                odd_days_month = 5;
                break;
        }
    }
    else
    {
        switch (month)
        {

            case 1:
                odd_days_month = 0;
                break;

            case 2:
                odd_days_month = 3;
                break;

            case 3:
                odd_days_month = 4;
                break;

            case 4:
                odd_days_month = 0;
                break;

            case 5:
                odd_days_month = 2;
                break;

            case 6:
                odd_days_month = 5;
                break;

            case 7:
                odd_days_month = 0;
                break;

            case 8:
                odd_days_month = 3;
                break;

            case 9:
                odd_days_month = 6;
                break;

            case 10:
                odd_days_month = 1;
                break;

            case 11:
                odd_days_month = 4;
                break;

            case 12:
                odd_days_month = 6;
                break;
        }
    }
    j = odd_days_century + odd_days_year + odd_days_month + date;
    day = j % 7;

    switch (day)
    {
        case 0:
            printf("Sunday\n");
            break;

        case 1:
            printf("Monday\n");
            break;

        case 2:
            printf("Tuesday\n");
            break;

        case 3:
            printf("Wednesday\n");
            break;

        case 4:
            printf("Thursday\n");
            break;

        case 5:
            printf("Friday\n");
            break;

        case 6:
            printf("Saturday\n");
            break;
    }
}
