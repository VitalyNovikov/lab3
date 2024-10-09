#include <iostream>
#include <cmath> 

using namespace std;

// Завдання 1. Опис числа
void task_1() {
    int n;
    cout << "Введіть ціле число в діапазоні 1-999: ";
    cin >> n;

    if (n < 1 || n > 999) {
        cout << "Число поза діапазоном!" << endl;
        return;
    } else{

    // Визначаємо парність
    string parity = (n % 2 == 0) ? "парне" : "непарне";

    // Визначаємо кількість цифр
    string digits;
    if (n < 10) {
        digits = "однозначне";
    } else if (n < 100) {
        digits = "двозначне";
    } else {
        digits = "тризначне";
    }

    // Виводимо результат
    cout << parity << " " << digits << " число" << endl;
    }
}

// Завдання 2. Перевірка точки в області (коло)
void task_2() {
    double r1, r2, a;

    // Введення параметрів фігур
    cout << "Введіть радіус внутрішнього кола (r1): ";
    cin >> r1;
    cout << "Введіть радіус зовнішнього кола (r2): ";
    cin >> r2;
    cout << "Введіть відстань від центру зовнішнього кола до центру внутрішніх кіл (a): ";
    cin >> a;

    double x, y;
    cout << "Введіть координати точки (x, y): ";
    cin >> x >> y;

    // Центри червоних кіл
    double x1 = a * cos(M_PI / 4);
    double y1 = a * sin(M_PI / 4);
    double x2 = -a * cos(M_PI / 4);
    double y2 = -a * sin(M_PI / 4);

    // Перевірка потрапляння в перше червоне коло
    double distance1 = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
    bool inFirstRedCircle = (distance1 <= r1);

    // Перевірка потрапляння в друге червоне коло
    double distance2 = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
    bool inSecondRedCircle = (distance2 <= r1);

    // Перевірка потрапляння в жовте коло
    double distanceOuter = sqrt(pow(x, 2) + pow(y, 2));
    bool inYellowCircle = (distanceOuter <= r2);

    // Виведення результату
    if (inFirstRedCircle || inSecondRedCircle) {
        cout << "Точка потрапляє в червоне коло" << endl;
    } else if (inYellowCircle) {
        cout << "Точка потрапляє в жовте коло" << endl;
    } else {
        cout << "Точка не потрапляє у фігуру" << endl;
    }
}

// Завдання 3. Обчислення площі і периметру кола
void task_3() {
    double radius;
    cout << "Введіть радіус кола: ";
    cin >> radius;

    if (radius <= 0) {
        cout << "Радіус має бути більше нуля!" << endl;
        return;
    }

    // Обчислюємо площу та периметр
    double area = M_PI * radius * radius;
    double perimeter = 2 * M_PI * radius;

    // Виведення результатів
    cout << "Площа кола: " << area << endl;
    cout << "Периметр кола: " << perimeter << endl;
}

// Завдання 4. Меню
void menu() {
    int choice;

    do {
        // Виводимо меню
        cout << "\nОберіть завдання:\n";
        cout << "1. Опис числа\n";
        cout << "2. Перевірка точки у фігурі\n";
        cout << "3. Обчислення площі та периметру\n";
        cout << "0. Вихід\n";
        cout << "Введіть номер завдання: ";
        cin >> choice;

        // Викликаємо функцію залежно від вибору
        switch (choice) {
            case 1:
                task_1();
                break;
            case 2:
                task_2(); // Параметри вводимо тут
                break;
            case 3:
                task_3();
                break;
            case 0:
                cout << "Вихід з програми..." << endl;
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0); // повторюємо, поки користувач не вибере вихід
}

int main() {
    menu(); // Запуск меню
    return 0;
}
