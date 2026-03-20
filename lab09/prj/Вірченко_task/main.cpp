#include <iostream>
#include <windows.h>
#include "s_calculation.h"

using namespace std;

int main() {
    // Налаштування кирилиці для консолі Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char menu_choice, exit_choice;

    do {
        cout << "\n========== МЕНЮ КЕРУВАННЯ (Варіант 3) ==========" << endl;
        cout << "u - Задача 9.4 (Обчислення виразу S)" << endl;
        cout << "o - Задача 9.1 (Шкала Бофорта)" << endl;
        cout << "p - Задача 9.2 (Степені та непарні числа)" << endl;
        cout << "a - Задача 9.3 (Двійковий аналіз)" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Ваш вибір: ";
        cin >> menu_choice;

        switch (menu_choice) {
            case 'u': {
                double x, y, z;
                cout << "Введіть x, y, z: ";
                cin >> x >> y >> z;
                double result = s_calculation(x, y, z);
            cout << "Результат S = " << result << endl;
        break;
}
            case 'o': {
                int b; string s, d;
                cout << "Введіть бал: "; cin >> b;
                try { wind_calculation(b, s, d); cout << d << " (" << s << " м/с)" << endl; }
                catch (...) { cout << "\aПомилка!" << endl; }
                break;
            }
            case 'p': {
                int n, m; double p1, p2; vector<int> o;
                cout << "Введіть n, m: "; cin >> n >> m;
                power_and_odds(n, m, p1, p2, o);
                cout << "Степені: " << p1 << ", " << p2 << endl;
                break;
            }
            case 'a': {
                int N;
                cout << "Введіть N (0-80000): ";
                cin >> N;
                try {
                    int result = binary_analysis(N);

                    // Визначаємо другий біт (вага 2), щоб знати, що ми рахували
                    int second_bit = (N >> 1) & 1;

                    if (second_bit == 0) {
                        cout << "Другий біт дорівнює 0. Підраховано кількість НУЛІВ: " << result << endl;
                    } else {
                        cout << "Другий біт дорівнює 1. Підраховано кількість ОДИНИЦЬ: " << result << endl;
                    }
                }
                catch (const std::exception& e) {
                    cout << "\aПомилка: " << e.what() << endl;
                }
            break;
            }
            default:
                cout << "\a"; // Звуковий сигнал при помилці
                cout << "Невірний символ!" << endl;
        }

        cout << "\nВведіть 's' для виходу або будь-який символ для повтору: ";
        cin >> exit_choice;

    } while (exit_choice != 's' && exit_choice != 'S');

    return 0;
}
