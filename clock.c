#include <stdio.h>
#include <windows.h>

int main(void)
{
    int hour;
    int minute;
    int second = 0;

    do
    {
        printf("Enter the hour (0-23): ");
        scanf("%d", &hour);
    } while (hour < 0 || hour > 23);

    do
    {
        printf("Enter the minute (0-59): ");
        scanf("%d", &minute);
    } while (minute < 0 || minute > 59);

    while (1)
    {
        printf("\r%02d:%02d:%02d", hour, minute, second);
        fflush(stdout);

        Sleep(1000);

        second++;
        if (second == 60)
        {
            second = 0;
            minute++;
            if (minute == 60)
            {
                minute = 0;
                hour++;
                if (hour == 24)
                {
                    hour = 0;
                }
            }
        }
    }
}