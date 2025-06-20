#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

// Структура для хранения пары (a, b)
struct Pair {
    char first;
    char second;
};

// Проверка, является ли отношение функцией
bool isFunction(const vector<Pair>& relation) {
    for (int i = 0; i < relation.size(); ++i) {
        for (int j = i + 1; j < relation.size(); ++j) {
            if (relation[i].first == relation[j].first &&
                relation[i].second != relation[j].second) {
                return false; // одному a сопоставлены разные b
            }
        }
    }
    return true;
}

// Ввод отношения в виде матрицы
void inputRelationMatrix(vector<Pair>& relation, const vector<char>& setA, const vector<char>& setB) {
    int n = setA.size();
    int m = setB.size();

    cout << "Введите матрицу " << n << "x" << m << " (0 или 1):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Для элемента A[" << i << "] = '" << setA[i] << "': ";
        for (int j = 0; j < m; ++j) {
            int val;
            cin >> val;
            if (val == 1) {
                Pair p;
                p.first = setA[i];
                p.second = setB[j];
                relation.push_back(p);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    vector<char> setA, setB;
    vector<Pair> relation;

    int sizeA, sizeB;

    // Ввод множества A
    cout << "Введите количество элементов множества A: ";
    cin >> sizeA;
    cout << "Введите элементы множества A:\n";
    for (int i = 0; i < sizeA; ++i) {
        char elem;
        cout << "A[" << i << "] = ";
        cin >> elem;
        setA.push_back(elem);
    }

    // Ввод множества B
    cout << "Введите количество элементов множества B: ";
    cin >> sizeB;
    cout << "Введите элементы множества B:\n";
    for (int i = 0; i < sizeB; ++i) {
        char elem;
        cout << "B[" << i << "] = ";
        cin >> elem;
        setB.push_back(elem);
    }

    // Ввод матрицы и построение отношения
    inputRelationMatrix(relation, setA, setB);

    // Проверка
    cout << "Отношение:\n";
    for (const auto& p : relation) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    if (isFunction(relation)) {
        cout << "Отношение является функцией.\n";
    }
    else {
        cout << "Отношение не является функцией.\n";
    }

    return 0;
}
