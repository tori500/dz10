#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

float area_rhombus(float d1, float d2);
void draw_rhombus(int d1, int d2, char sym);
int get_diagonal();
int compare_rhombus(int d1_1, int d2_1, int d1_2, int d2_2);

int main()
{
    setlocale(LC_ALL, "RUS");

    int choice;
    int d1, d2;
    char symbol;

    printf("--- Лабораторная 9. Фигура: Ромб (контур) ---\n");

    printf("Введите первую диагональ ромба: ");
    d1 = get_diagonal();

    printf("Введите вторую диагональ ромба: ");
    d2 = get_diagonal();

    printf("Введите символ для рисования (например, * или #): ");
    scanf(" %c", &symbol);

    printf("\nМеню:\n");
    printf("1) Рассчитать площадь\n");
    printf("2) Вывести определение фигуры\n");
    printf("3) Нарисовать фигуру\n");
    printf("4) Сравнить с другим ромбом\n");
    printf("Выберите операцию: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Площадь ромба с диагоналями %d и %d равна %.2f\n", d1, d2, area_rhombus((float)d1, (float)d2));
            break;
        case 2:
            printf("Ромб — это параллелограмм, у которого все стороны равны. Площадь ромба равна половине произведения его диагоналей.\n");
            break;
        case 3:
            draw_rhombus(d1, d2, symbol);
            break;
        case 4:
            {
                int d1_2, d2_2;
                printf("Введите первую диагональ второго ромба: ");
                d1_2 = get_diagonal();
                printf("Введите вторую диагональ второго ромба: ");
                d2_2 = get_diagonal();

                int diff = compare_rhombus(d1, d2, d1_2, d2_2);
                printf("Разница между площадями ромбов (по модулю): %d\n", diff);
            }
            break;
        default:
            printf("Неверный выбор операции\n");
            break;
    }

    return 0;
}

int get_diagonal()
{
    int d;
    scanf("%d", &d);
    return d;
}

float area_rhombus(float d1, float d2)
{
    return 0.5f * d1 * d2;
}

void draw_rhombus(int d1, int d2, char sym)
{
    int a = d1 / 2; // Половина первой диагонали (по оси X)
    int b = d2 / 2; // Половина второй диагонали (по оси Y)
    int x, y;

    // Если диагонали четные, сделаем их нечетными для симметричного центра
    if (d1 % 2 == 0) a--;
    if (d2 % 2 == 0) b--;

    for (y = -b; y <= b; y++)
    {
        int abs_y = y < 0 ? -y : y;
        // Вычисляем, насколько широким должен быть ромб в этой строке
        int limit = (a * b - abs_y * a) / b;

        for (x = -a; x <= a; x++)
        {
            int abs_x = x < 0 ? -x : x;

            // Выводим символ только если мы на границе (слева или справа)
            if (abs_x == limit)
            {
                printf("%c", sym);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int compare_rhombus(int d1_1, int d2_1, int d1_2, int d2_2)
{
    float s1 = area_rhombus((float)d1_1, (float)d2_1);
    float s2 = area_rhombus((float)d1_2, (float)d2_2);

    if (s1 > s2)
        return (int)(s1 - s2);
    else
        return (int)(s2 - s1);
}