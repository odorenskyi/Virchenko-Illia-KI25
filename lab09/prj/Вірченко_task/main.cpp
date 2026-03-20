#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <limits>
#include "s_calculation.h"

using namespace std;

// Функція для очищення буфера після некоректного введення
void clear_input_error() {
    cout << "\a"; // Звуковий сигнал помилки
    cin.clear();  // Скидаємо прапорці помилок
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаємо весь буфер
}

int main() {
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

        if (!(cin >> menu_choice)) {
            clear_input_error();
            continue;
        }

        switch (menu_choice) {
            case 'u': {
                double x, y, z;
                cout << "Введіть x, y, z: ";
                if (!(cin >> x >> y >> z)) {
                    cout << "Помилка: Введено не число!" << endl;
                    clear_input_error();
                } else {
                    try {
                        cout << "Результат S = " << s_calculation(x, y, z) << endl;
                    } catch (const exception& e) {
                        cout << "Математична помилка: " << e.what() << endl;
                    }
                }
                break;
            }
            case 'o': {
                int b; string s, d;
                cout << "Введіть бал (0-12): ";
                if (!(cin >> b)) {
                    cout << "Помилка: Потрібно ввести ціле число!" << endl;
                    clear_input_error();
                } else {
                    try {
                        wind_calculation(b, s, d);
                        cout << "Результат: " << d << " (" << s << " м/с)" << endl;
                    } catch (const invalid_argument& e) {
                        cout << "Помилка: " << e.what() << endl;
                    }
                }
                break;
            }
            case 'p': {
                int n, m; double p1, p2; vector<int> o;
                cout << "Введіть цілі n та m: ";
                if (!(cin >> n >> m)) {
                    cout << "Помилка: Введіть два цілих числа!" << endl;
                    clear_input_error();
                } else {
                    power_and_odds(n, m, p1, p2, o);
                    cout << "n^m = " << p1 << ", m^n = " << p2 << endl;
                    cout << "Непарні числа в діапазоні: ";
                    for(int val : o) cout << val << " ";
                    cout << endl;
                }
                break;
            }
            case 'a': {
                int N;
                cout << "Введіть N (0-80000): ";
                if (!(cin >> N)) {
                    cout << "Помилка: Введіть натуральне число!" << endl;
                    clear_input_error();
                } else {
                    try {
                        int result = binary_analysis(N);
                        int bit2 = (N >> 1) & 1;
                        if (bit2 == 0) {
                            cout << "[2-й біт = 0] Результат (кількість НУЛІВ): " << result << endl;
                        } else {
                            cout << "[2-й біт = 1] Результат (кількість ОДИНИЦЬ): " << result << endl;
                        }
                    } catch (const invalid_argument& e) {
                        cout << "Помилка: " << e.what() << endl;
                    }
                }
                break;
            }
            default:
                cout << "\aНевірний символ меню! Спробуйте ще раз." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "\n-----------------------------------------------" << endl;
        cout << "Вийти? (s - так, будь-що інше - ні): ";
        cin >> exit_choice;
        // Очищаємо буфер після кожного циклу, щоб наступний cin >> menu_choice працював чисто
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (exit_choice != 's' && exit_choice != 'S');

    return 0;
}
