#include <iostream>
#include <iomanip>
#include <string>
#include "s_calculation.h"

using namespace std;

string getDeveloperInfo() {
    return "Розробник: Вiрченко Iлля ";
}

bool checkExpression(char a, char b) {
    return (a + 3 <= b);
}

void printData(int x, int y, int z) {
    cout << "Десяткова система:  x=" << dec << x
         << ", y=" << y
         << ", z=" << z << endl;

    cout << "Шістнадцяткова:     x=0x" << hex << x
         << ", y=0x" << y
         << ", z=0x" << z << endl;

    cout << dec << "Обчислене S:        " << fixed << setprecision(2) << s_calculation(x, y, z) << endl;
}

int main() {
    setlocale(LC_ALL, "");
    system("chcp 65001");

    string developer = getDeveloperInfo();
    cout << developer << u8"©" << endl;

    int x, y, z;
    char a, b;

    cout << "Введiть числа x, y, z: ";
    cin >> x >> y >> z;
    cout << "Введiть символи a та b: ";
    cin >> a >> b;

    cout << "\n--- РЕЗУЛЬТАТИ ---" << endl;

    cout << " Результат виразу (a + 3 <= b): " << boolalpha << checkExpression(a, b) << endl;

    cout << ": " << endl;
    printData(x, y, z);

    return 0;
}
