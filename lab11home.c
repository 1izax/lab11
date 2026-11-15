#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

typedef struct {
    int number;
    char dep_point[50];
    int dep_hour;
    int dep_min;
    char arr_point[50];
    int arr_hour;
    int arr_min;
} Train;

int main() {
    setlocale(LC_ALL, "RUS");
    system("chcp 1251 > nul");

    Train trains[10];
    int n;
    int i;
    int found;
    int target_minutes;
    int dep_total, arr_total, travel_time;
    printf("Введите количество поездов (от 5 до 10): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n===== Ввод данных для поезда №%d =====\n", i + 1);
        printf("Введите номер поезда: ");
        scanf("%d", &trains[i].number);
        printf("Введите пункт отбытия (без пробелов): ");
        scanf("%s", trains[i].dep_point);
        printf("Введите время отбытия (часы и минуты через пробел): ");
        scanf("%d %d", &trains[i].dep_hour, &trains[i].dep_min);
        printf("Введите пункт прибытия (без пробелов): ");
        scanf("%s", trains[i].arr_point);
        printf("Введите время прибытия (часы и минуты через пробел): ");
        scanf("%d %d", &trains[i].arr_hour, &trains[i].arr_min);
    }
    printf("\n=============================================================\n");
    printf("ПОЕЗДА, ВРЕМЯ В ПУТИ КОТОРЫХ БОЛЕЕ 7 ЧАСОВ 20 МИНУТ:\n");
    printf("=============================================================\n");
    found = 0;
    target_minutes = 7 * 60 + 20;
    for (i = 0; i < n; i++) {
        dep_total = trains[i].dep_hour * 60 + trains[i].dep_min;
        arr_total = trains[i].arr_hour * 60 + trains[i].arr_min;
        if (arr_total < dep_total) {
            arr_total = arr_total + (24 * 60);
        }
        travel_time = arr_total - dep_total;
        if (travel_time > target_minutes) {
            found = 1;
            printf("Поезд №%d\n", trains[i].number);
            printf("  Маршрут: %s (%02d:%02d) -> %s (%02d:%02d)\n",
                trains[i].dep_point, trains[i].dep_hour, trains[i].dep_min,
                trains[i].arr_point, trains[i].arr_hour, trains[i].arr_min);
            printf("  Время в пути: %d часов %d минут\n", travel_time / 60, travel_time % 60);
            printf("-------------------------------------------------------------\n");
        }
    }
    if (found == 0) {
        printf("Поездов с таким временем в пути не найдено.\n");
    }

    return 0;
}