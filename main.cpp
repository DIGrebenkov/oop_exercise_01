/*
Лабораторная работа № 1
Гребенков Дмитрий Игоревич
М8О-207Б-19
Вариант 17:
    Создать класс Budget для работы с бюджетом. Класс состоит из двух вещественных чисел (a,b).
    Где a - собственная часть средств бюджета в рублях, b - заемная часть средств бюджета рублях.
    Оба числа должны округляться до второго знака после запятой. Реализовать арифметические операции
    сложения, вычитания, умножения и деления, а также операции сравнения.
*/

#include <iostream>
#include <cmath>

class Budget {
public:
    double a = 0;
    double b = 0;
    void ent (double x, double y) {
        a = (round (x * 100)) / 100;
        b = (round (y * 100)) / 100;
    }
    void output () {
        std::cout << "(" << a << ", " << b << "). " << std::endl;
    }
};

void plus (Budget first, Budget second, Budget * third) {
    third->a = first.a + second.a;
    third->b = first.b + second.b;
}

int minus (Budget first, Budget second, Budget * third) {
    if ((first.a >= second.a) && (first.b >= second.b)) {
        third->a = first.a - second.a;
        third->b = first.b - second.b;
        return 0;
    }
    else {
        std::cout << "Error: budget cannot be negative." << std::endl;
        return 1;
    }
}

void multiply (Budget first, double c, Budget * third) {
    third->a = round ((c * first.a) * 100) / 100;
    third->b = round ((c * first.b) * 100) / 100;
}

int divide (Budget first, double c, Budget * third) {
    if (c != 0) {
        third->a = round ((first.a / c) * 100) / 100;
        third->b = round ((first.b / c) * 100) / 100;
        return 0;
    }
    else {
        std::cout << "Error: division by zero." << std::endl;
        return 1;
    }
}

void compare (Budget first, Budget second) {
    if ((first.a == second.a) && (first.b == second.b)) {
        std::cout << "Budgets are equal." << std::endl;
    }
    else {
        std::cout << "Budgets are not equal." << std::endl;
    }
}

int main () {
    int point = 0;
    double x;
    double y;
    double c;
    int first_flag = 0;
    int second_flag = 0;
    int exf = 0;
    Budget first;
    Budget second;
    Budget third;
    std::cout << "0. Print menu." << std::endl;
    std::cout << "1. Enter the data of the first budget." << std::endl;
    std::cout << "2. Enter the data of the second budget." << std::endl;
    std::cout << "3. Print the data of the first and second budgets." << std::endl;
    std::cout << "4. Addition of the first and second budgets." << std::endl;
    std::cout << "5. Subtract the second budget from the first." << std::endl;
    std::cout << "6. Multiply the first budget by number." << std::endl;
    std::cout << "7. Divide first budget by number." << std::endl;
    std::cout << "8. Compare the first budget with the second." << std::endl;
    std::cout << "9. Quit the program." << std::endl;
    while (point != 9) {
        std::cout << "Choose option:" << std::endl;
        std::cin >> point;
        switch (point) {
            case 0:
                std::cout << "0. Print menu." << std::endl;
                std::cout << "1. Enter the data of the first budget." << std::endl;
                std::cout << "2. Enter the data of the second budget." << std::endl;
                std::cout << "3. Print the data of the first and second budgets." << std::endl;
                std::cout << "4. Addition of the first and second budgets." << std::endl;
                std::cout << "5. Subtract the second budget from the first." << std::endl;
                std::cout << "6. Multiply the first budget by number." << std::endl;
                std::cout << "7. Divide first budget by number." << std::endl;
                std::cout << "8. Compare the first budget with the second." << std::endl;
                std::cout << "9. Quit the program." << std::endl;
                break;
            case 1: {
                std::cout << "Enter own part of the budget: ";
                std::cin >> x;
                if (x < 0) {
                    std::cout << "Error: budget cannot be negative." << std::endl;
                    break;
                }
                std::cout << "Enter borrowed part of the budget: ";
                std::cin >> y;
                if (y < 0) {
                    std::cout << "Error: budget cannot be negative." << std::endl;
                    break;
                }
                first_flag = 1;
                first.ent (x, y);
                break;
            }
            case 2: {
                std::cout << "Enter own part of the budget: ";
                std::cin >> x;
                if (x < 0) {
                    std::cout << "Error: budget cannot be negative." << std::endl;
                    break;
                }
                std::cout << "Enter borrowed part of the budget: ";
                std::cin >> y;
                if (y < 0) {
                    std::cout << "Error: budget cannot be negative." << std::endl;
                    break;
                }
                second_flag = 1;
                second.ent (x, y);
                break;
            }
            case 3: {
                if (first_flag == 1) {
                    first.output ();
                }
                else {
                    std::cout << "Error: no first budget data entered." << std::endl;
                }
                if (second_flag == 1) {
                    second.output ();
                }
                else {
                    std::cout << "Error: no second budget data entered." << std::endl;
                }
                break;
            }
            case 4: {
                if (first_flag != 1) {
                    std::cout << "Error: no first budget data entered." << std::endl;
                }
                if (second_flag != 1) {
                    std::cout << "Error: no second budget data entered." << std::endl;
                }
                if ((first_flag != 1) || (second_flag != 1)) {
                    break;
                }
                else {
                    plus (first, second, &third);
                    third.output ();
                }
                break;
            }
            case 5: {
                if (first_flag != 1) {
                    std::cout << "Error: no first budget data entered." << std::endl;
                }
                if (second_flag != 1) {
                    std::cout << "Error: no second budget data entered." << std::endl;
                }
                if ((first_flag != 1) || (second_flag != 1)) {
                    break;
                }
                else {
                    exf = minus (first, second, &third);
                    if (exf == 0) {
                        third.output ();
                    }
                }
                break;
            }
            case 6: {
                if (first_flag != 1) {
                    std::cout << "Error: no first budget data entered." << std::endl;
                }
                if ((first_flag != 1) || (second_flag != 1)) {
                    break;
                }
                else {
                    std::cout << "Enter multiplier: ";
                    std::cin >> c;
                    multiply (first, c, &third);
                    third.output ();
                }
                break;
            }
            case 7: {
                if (first_flag != 1) {
                    std::cout << "Error: no first budget data entered." << std::endl;
                }
                if ((first_flag != 1) || (second_flag != 1)) {
                    break;
                }
                else {
                    std::cout << "Enter divider: ";
                    std::cin >> c;
                    exf = divide (first, c, &third);
                    if (exf == 0) {
                        third.output ();
                    }
                }
                break;
            }
            case 8: {
                if (first_flag != 1) {
                    std::cout << "Error: no first budget data entered." << std::endl;
                }
                if (second_flag != 1) {
                    std::cout << "Error: no second budget data entered." << std::endl;
                }
                if ((first_flag != 1) || (second_flag != 1)) {
                    break;
                }
                else {
                    compare (first, second);
                }
                break;
            }
            case 9: {
                break;
            }
            default: {
                std::cout << "Error: incorrect input." << std::endl;
                break;
            }
        }
    }
    return 0;
}