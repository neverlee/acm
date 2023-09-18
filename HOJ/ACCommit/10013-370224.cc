#include <iostream>
#include <string>
using namespace std;
string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int getYearDays(int y)
{
    if (y % 4 != 0)
        return 365;
    else if (y % 400 == 0)
        return 366;
    else if (y % 100 == 0)
        return 365;
    else
        return 366;
}
int getCurMonthDays(int y, int m)
{
    const static int md[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m != 2)
        return md[m];
    return getYearDays(y) - 337;
}

int main()
{
    int curYear;
    int curMonth;
    int curDay;
    int days;
    while (scanf("%d", &days) != EOF && days != EOF)
    {
        int t = (days + 6) % 7;
        curYear = 2000;
        while (days >= getYearDays(curYear))
        {
            days -= getYearDays(curYear);
            ++curYear;
        }
        curMonth = 1;
        while (days >= getCurMonthDays(curYear, curMonth))
        {
            days -= getCurMonthDays(curYear, curMonth);
            ++curMonth;
        }
        curDay = days + 1;
        printf("%04d-%02d-%02d %s\n", curYear, curMonth, curDay, week[t].c_str());
    }
    
    return 0;
}