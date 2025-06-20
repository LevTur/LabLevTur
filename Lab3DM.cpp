#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

bool IsFunction(vector <pair <int, int>>& f) {
    for (int i = 0; i < f.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (f[i].first == f[j].first && f[i].second != f[j].second) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите количество пар" << endl;
    int n;
    cin >> n;
    vector <pair <int, int>> f(n);
    cout << "Введите пары" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> f[i].first >> f[i].second;
    }
    if (IsFunction(f)) {
        cout << "Это функция";
    }
    else {
        cout << "Это не функция";
    }
}