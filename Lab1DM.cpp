#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

struct element {
    char evenNumber;
    char unEvenNumber;
    char number1;
    char number2;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "введите размер первого множества" << endl;
    int n;
    cin >> n;
    vector <element> a(n);
    cout << "введите первое множество" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        string input;
        cin >> input;
        if ((input[0] < '0' || input[0] > '9' || (input[0] - '0') % 2 != 0) || (input[1] < '0' || input[1] > '9' || (input[1] - '0') % 2 != 1)
            || (input[2] < '0' || input[2] > '9') || (input[3] < '0' || input[3] > '9')) {
            cout << "ошибка, введите корректный элемент" << endl;
            i--;
        }
        else {
            a[i].evenNumber = input[0];
            a[i].unEvenNumber = input[1];
            a[i].number1 = input[2];
            a[i].number2 = input[3];
        }
    }
    cout << "введите размер второго множества" << endl;
    int m;
    cin >> m;
    vector <element> b(m);
    cout << "введите второе множество" << endl;
    for (int i = 0; i < m; ++i) {
        cout << "Element " << i + 1 << ": ";
        string input;
        cin >> input;
        if ((input[0] < '0' || input[0] > '9' || (input[0] - '0') % 2 != 0) || (input[1] < '0' || input[1] > '9' || (input[1] - '0') % 2 != 1)
            || (input[2] < '0' || input[2] > '9') || (input[3] < '0' || input[3] > '9')) {
            cout << "ошибка, введите корректный элемент" << endl;
            i--;
        }
        else {
            b[i].evenNumber = input[0];
            b[i].unEvenNumber = input[1];
            b[i].number1 = input[2];
            b[i].number2 = input[3];
        }
    }
    cout << "объединение множеств" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": " << a[i].evenNumber << a[i].unEvenNumber << a[i].number1 << a[i].number2 << endl;
    }
    for (int i = 0; i < m; ++i) {
        bool us = false;
        for (int j = 0; j < n; ++j) {
            if (a[j].evenNumber == b[i].evenNumber && a[j].unEvenNumber == b[i].unEvenNumber
                && a[j].number1 == b[i].number1 && a[j].number2 == b[i].number2) {
                us = true;
            }
        }
        if (!us) {
            cout << "Element " << n + i + 1 << ": " << b[i].evenNumber << b[i].unEvenNumber << b[i].number1 << b[i].number2 << endl;
        }
    }
    cout << endl << "пересечение множеств" << endl;
    for (int i = 0; i < m; ++i) {
        bool us = false;
        for (int j = 0; j < n; ++j) {
            if (a[j].evenNumber == b[i].evenNumber && a[j].unEvenNumber == b[i].unEvenNumber
                && a[j].number1 == b[i].number1 && a[j].number2 == b[i].number2) {
                us = true;
            }
        }
        if (us) {
            cout << "Element " << i + 1 << ": " << b[i].evenNumber << b[i].unEvenNumber << b[i].number1 << b[i].number2 << endl;
        }
    }
    cout << endl << "дополнение a b " << endl;
    int nom = 1;
    for (int i = 0; i < n; ++i) {
        bool us = false;
        for (int j = 0; j < m; ++j) {
            if (a[i].evenNumber == b[j].evenNumber && a[i].unEvenNumber == b[j].unEvenNumber
                && a[i].number1 == b[j].number1 && a[i].number2 == b[j].number2) {
                us = true;
            }
        }
        if (!us) {
            cout << "Element " << nom << ": " << a[i].evenNumber << a[i].unEvenNumber << a[i].number1 << a[i].number2 << endl;
            nom++;
        }
    }
    cout << endl << "дополнение b a" << endl;
    nom = 1;
    for (int i = 0; i < m; ++i) {
        bool us = false;
        for (int j = 0; j < n; ++j) {
            if (b[i].evenNumber == a[j].evenNumber && b[i].unEvenNumber == a[j].unEvenNumber
                && b[i].number1 == a[j].number1 && b[i].number2 == a[j].number2) {
                us = true;
            }
        }
        if (!us) {
            cout << "Element " << nom << ": " << b[i].evenNumber << b[i].unEvenNumber << b[i].number1 << b[i].number2 << endl;
            nom++;
        }
    }
    cout << endl << "симметрическую разность" << endl;
    nom = 1;
    for (int i = 0; i < n; ++i) {
        bool us = false;
        for (int j = 0; j < m; ++j) {
            if (a[i].evenNumber == b[j].evenNumber && a[i].unEvenNumber == b[j].unEvenNumber
                && a[i].number1 == b[j].number1 && a[i].number2 == b[j].number2) {
                us = true;
            }
        }
        if (!us) {
            cout << "Element " << nom << ": " << a[i].evenNumber << a[i].unEvenNumber << a[i].number1 << a[i].number2 << endl;
            nom++;
        }
    }
    for (int i = 0; i < m; ++i) {
        bool us = false;
        for (int j = 0; j < n; ++j) {
            if (b[i].evenNumber == a[j].evenNumber && b[i].unEvenNumber == a[j].unEvenNumber
                && b[i].number1 == a[j].number1 && b[i].number2 == a[j].number2) {
                us = true;
            }
        }
        if (!us) {
            cout << "Element " << nom << ": " << b[i].evenNumber << b[i].unEvenNumber << b[i].number1 << b[i].number2 << endl;
            nom++;
        }
    }
    cout << endl << "всё" << endl;
}