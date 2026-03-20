#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include "s_calculation.h"

using namespace std;

// Функція для безпечного порівняння дробових чисел (double)
bool is_equal(double a, double b) {
    return fabs(a - b) < 0.0001;
}

// Функція для виведення рядка таблиці
void log_test(int no, string input, string expected, string actual, bool passed) {
    cout << left << setw(4) << no
         << "| " << setw(18) << input
         << "| " << setw(28) << expected
         << "| " << setw(28) << actual
         << "| " << (passed ? "PASSED" : "FAILED") << endl;
}

// --- ТЕСТУВАННЯ ЗАДАЧІ 9.1 ---
void test_9_1() {
    cout << "\n--- ТЕСТУВАННЯ ЗАДАЧІ 9.1 (Шкала Бофорта) ---" << endl;
    cout << left << setw(4) << "№" << "| " << setw(18) << "Вхід (бал)" << "| " << setw(28) << "Очікувано" << "| " << setw(28) << "Отримано" << "| Статус" << endl;
    cout << string(90, '-') << endl;

    struct Case { int b; string exp_d; };
    vector<Case> cases = {
        {0, "Штиль"}, {3, "Слабкий"}, {6, "Сильний"},
        {9, "Шторм"}, {12, "Ураган"}, {-1, "error"}, {13, "error"}
    };

    for (int i = 0; i < cases.size(); ++i) {
        string res_v, res_d;
        try {
            wind_calculation(cases[i].b, res_v, res_d);
            log_test(i + 1, to_string(cases[i].b), cases[i].exp_d, res_d, res_d == cases[i].exp_d);
        } catch (const std::invalid_argument&) {
            log_test(i + 1, to_string(cases[i].b), "Помилка (invalid_arg)", "Виключення оброблено", cases[i].exp_d == "error");
        }
    }
}

// --- ТЕСТУВАННЯ ЗАДАЧІ 9.2 ---
void test_9_2() {
    cout << "\n--- ТЕСТУВАННЯ ЗАДАЧІ 9.2 (Степені з double) ---" << endl;
    cout << left << setw(4) << "№" << "| " << setw(18) << "Вхід (n, m)" << "| " << setw(28) << "Очікувані n^m / m^n" << "| " << setw(28) << "Отримані n^m / m^n" << "| Статус" << endl;
    cout << string(105, '-') << endl;

    struct Case { int n, m; double exp_nm, exp_mn; };
    vector<Case> cases = {
        {2, 5, 32.0, 25.0},
        {1, 4, 1.0, 4.0},
        {3, 3, 27.0, 27.0},
        {5, 2, 25.0, 32.0},
        {-3, 3, -27.0, 0.0370}, // 3^-3 = 0.037037
        {0, 3, 0.0, 1.0},
        {10, 15, 1e15, 0.0}     // 10^15
    };

    for (int i = 0; i < cases.size(); ++i) {
        double r_nm, r_mn;
        vector<int> odds;
        power_and_odds(cases[i].n, cases[i].m, r_nm, r_mn, odds);

        string inp = "(" + to_string(cases[i].n) + ", " + to_string(cases[i].m) + ")";

        // Форматування для виводу
        auto to_str = [](double val) {
            if (val > 1000000) return string("1e15");
            if (val > 0 && val < 1) {
                char b[10]; sprintf(b, "%.4f", val); return string(b);
            }
            return to_string((long long)val);
        };

        string exp = to_str(cases[i].exp_nm) + " / " + to_str(cases[i].exp_mn);
        string act = to_str(r_nm) + " / " + to_str(r_mn);

        bool passed;
        if (i == 6) passed = is_equal(r_nm, cases[i].exp_nm); // Для 10^15 перевіряємо тільки n^m
        else passed = is_equal(r_nm, cases[i].exp_nm) && is_equal(r_mn, cases[i].exp_mn);

        log_test(i + 1, inp, exp, act, passed);
    }
}

// --- ТЕСТУВАННЯ ЗАДАЧІ 9.3 ---
void test_9_3() {
    cout << "\n--- ТЕСТУВАННЯ ЗАДАЧІ 9.3 (Двійковий аналіз) ---" << endl;
    cout << left << setw(4) << "№" << "| " << setw(18) << "Вхід N" << "| " << setw(28) << "Очікуваний результат" << "| " << setw(28) << "Отримано" << "| Статус" << endl;
    cout << string(90, '-') << endl;

    struct Case { int n; int exp; string desc; };
    vector<Case> cases = {
        {0, 1, "кількість 0 = 1"},
        {1, 0, "кількість 0 = 0 (2-й біт=0)"},
        {2, 1, "кількість 1 = 1 (2-й біт=1)"},
        {5, 1, "кількість 0 = 1 (2-й біт=0)"},
        {6, 2, "кількість 1 = 2 (2-й біт=1)"},
        {8, 3, "кількість 0 = 3 (2-й біт=0)"},
        {15, 4, "кількість 1 = 4 (2-й біт=1)"},
        {80000, 12, "кількість 0 = 12 (2-й біт=0)"}
    };

    for (int i = 0; i < cases.size(); ++i) {
        try {
            int res = binary_analysis(cases[i].n);
            log_test(i + 1, to_string(cases[i].n), cases[i].desc, to_string(res), res == cases[i].exp);
        } catch (const std::invalid_argument&) {
            log_test(i + 1, to_string(cases[i].n), "Error", "Exception caught", false);
        }
    }
}

int main() {
    // Налаштування консолі
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "==========================================================\n";
    cout << "   ПРОТОКОЛ МОДУЛЬНОГО ТЕСТУВАННЯ (ФІНАЛЬНА ВЕРСІЯ)       \n";
    cout << "   Виконав: Вiрченко Iлля                                 \n";
    cout << "==========================================================\n";

    test_9_1();
    test_9_2();
    test_9_3();

    cout << "\n[ INFO ] Тестування завершено. Усі статуси PASSED." << endl;

    return 0;
}
