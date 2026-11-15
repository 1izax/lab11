#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

struct point {
    float x;
    float y;
    char name;
};

typedef struct point Point;

void put_point(Point z) {
    printf("point %c (%.1f, %.1f)", z.name, z.x, z.y);
}

float dist(Point z, Point w) {
    float d = (float)sqrt(pow(z.x - w.x, 2) + pow(z.y - w.y, 2));
    return d;
}

Point mid(Point z, Point w) {
    Point m;
    m.name = 'M';
    m.x = (z.x + w.x) / 2.0f;
    m.y = (z.y + w.y) / 2.0f;
    return m;
}

double distanceToOrigin(Point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

int task1() {
    setlocale(LC_ALL, "RUS");

    Point a, b, m;
    printf("========================================\n");
    printf("Введите координаты точки A (x y): ");
    scanf("%f %f", &a.x, &a.y);
    a.name = 'A';
    printf("Введите координаты точки B (x y): ");
    scanf("%f %f", &b.x, &b.y);
    b.name = 'B';
    printf("========================================\n");
    put_point(a);
    printf("\n");
    put_point(b);
    printf("\nРасстояние между A и B: %.2f\n", dist(a, b));
    printf("Расстояние от A до (0,0): %.2lf\n", distanceToOrigin(a));
    printf("Расстояние от B до (0,0): %.2lf\n", distanceToOrigin(b));
    m = mid(a, b);
    printf("Середина отрезка: ");
    put_point(m);
    printf("\n");
    printf("========================================\n");

    return 0;
}

void print_center(char text[]) {
    int len = strlen(text);
    int total_stars = 80 - len;
    int left_stars = total_stars / 2;
    int right_stars = total_stars - left_stars;
    for (int i = 0; i < left_stars; i++) {
        printf("*");
    }
    printf("%s", text);
    for (int i = 0; i < right_stars; i++) {
        printf("*");
    }
    printf("\n");
}

int task2() {
    setlocale(LC_ALL, "RUS");

    time_t t = time(NULL);
    struct tm* mytime = localtime(&t);
    struct tm now = *mytime;
    char str[200];
    char line[81];
    char* days[] = {
        "воскресенье", "понедельник", "вторник",
        "среда", "четверг", "пятница", "суббота"
    };
    char* months[] = {
        "января", "февраля", "марта", "апреля",
        "мая", "июня", "июля", "августа",
        "сентября", "октября", "ноября", "декабря"
    };
    char* roman[] = {
        "I", "II", "III", "IV", "V", "VI",
        "VII", "VIII", "IX", "X", "XI", "XII"
    };
    char* seasons[] = { "зимы", "весны", "лета", "осени" };
    int year = now.tm_year + 1900;
    int month = now.tm_mon;
    int day = now.tm_mday;
    int hour = now.tm_hour;
    int min = now.tm_min;
    int sec = now.tm_sec;
    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 80; j++) {
            printf("*");
        }
        printf("\n");
    }
    sprintf(str, "Текущее время: %02d:%02d:%02d", hour, min, sec);
    print_center(str);
    sprintf(str, "День недели: %s", days[now.tm_wday]);
    print_center(str);
    sprintf(str, "Дата: %02d.%02d.%d", day, month + 1, year);
    print_center(str);
    sprintf(str, "Сегодня %d %s", day, months[month]);
    print_center(str);
    sprintf(str, "Сегодня %d-й день %d года", now.tm_yday + 1, year);
    print_center(str);
    int daysToSunday = (7 - now.tm_wday) % 7;
    int hoursToSunday = daysToSunday * 24 - hour;
    if (hoursToSunday < 0) hoursToSunday = 0;
    sprintf(str, "До воскресенья %d дней и %d часов", daysToSunday, hoursToSunday);
    print_center(str);
    int elapsed = hour * 60 + min - (8 * 60 + 30);
    if (elapsed < 0) elapsed = 0;
    sprintf(str, "С первой пары прошло %d часов %d минут", elapsed / 60, elapsed % 60);
    print_center(str);
    int monthsLeft = 11 - month;
    int daysLeft = daysInMonth[month] - day;
    sprintf(str, "До Нового года осталось %d месяцев и %d дней", monthsLeft, daysLeft);
    print_center(str);
    int currentTime = hour * 60 + min;
    int pairEnd = 0;
    if (currentTime >= 8 * 60 + 30 && currentTime < 10 * 60 + 5) pairEnd = 10 * 60 + 5;
    else if (currentTime >= 10 * 60 + 15 && currentTime < 11 * 60 + 50) pairEnd = 11 * 60 + 50;
    else if (currentTime >= 12 * 60 && currentTime < 13 * 60 + 35) pairEnd = 13 * 60 + 35;
    else if (currentTime >= 14 * 60 + 20 && currentTime < 15 * 60 + 55) pairEnd = 15 * 60 + 55;
    else if (currentTime >= 16 * 60 + 5 && currentTime < 17 * 60 + 40) pairEnd = 17 * 60 + 40;
    else if (currentTime >= 17 * 60 + 50 && currentTime < 19 * 60 + 25) pairEnd = 19 * 60 + 25;
    if (pairEnd != 0) {
        int remaining = (pairEnd - currentTime) * 60 - sec;
        sprintf(str, "До конца пары %d минут и %d секунд", remaining / 60, remaining % 60);
    }
    else {
        sprintf(str, "Сейчас занятий нет");
    }
    print_center(str);
    sprintf(str, "До конца месяца %d дней, до конца года %d месяцев", daysInMonth[month] - day, 11 - month);
    print_center(str);
    sprintf(str, "Месяц: %s, год: %d", roman[month], year);
    print_center(str);
    int season;
    if (month == 11 || month <= 1) season = 0;
    else if (month >= 2 && month <= 4) season = 1;
    else if (month >= 5 && month <= 7) season = 2;
    else season = 3;
    char* seasonNames[] = { "зима", "весна", "лето", "осень" };
    sprintf(str, "Время года: %s, год: %02d", seasonNames[season], year % 100);
    print_center(str);
    int seasonDay;
    if (season == 0) {
        if (month == 11) seasonDay = day;
        else if (month == 0) seasonDay = 31 + day;
        else seasonDay = 62 + day;
    }
    else if (season == 1) {
        seasonDay = day;
        for (int i = 2; i < month; i++) seasonDay += daysInMonth[i];
    }
    else if (season == 2) {
        seasonDay = day;
        for (int i = 5; i < month; i++) seasonDay += daysInMonth[i];
    }
    else {
        seasonDay = day;
        for (int i = 8; i < month; i++) seasonDay += daysInMonth[i];
    }
    sprintf(str, "Идет %d-й день %s", seasonDay, seasons[season]);
    print_center(str);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 80; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

int main() {
    setlocale(LC_ALL, "RUS");


    task2();

    system("pause");
    return 0;
}