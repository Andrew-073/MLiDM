#include <iostream>
#include <vector>
#include <locale.h>
// я внёс изменения в 3 лабу
using namespace std;

// Ñòðóêòóðà äëÿ õðàíåíèÿ ïàðû (a, b)
struct Pair {
    char first;
    char second;
};

// Ïðîâåðêà, ÿâëÿåòñÿ ëè îòíîøåíèå ôóíêöèåé
bool isFunction(const vector<Pair>& relation) {
    for (int i = 0; i < relation.size(); ++i) {
        for (int j = i + 1; j < relation.size(); ++j) {
            if (relation[i].first == relation[j].first &&
                relation[i].second != relation[j].second) {
                return false; // îäíîìó a ñîïîñòàâëåíû ðàçíûå b
            }
        }
    }
    return true;
}

// Ââîä îòíîøåíèÿ â âèäå ìàòðèöû
void inputRelationMatrix(vector<Pair>& relation, const vector<char>& setA, const vector<char>& setB) {
    int n = setA.size();
    int m = setB.size();

    cout << "Ââåäèòå ìàòðèöó " << n << "x" << m << " (0 èëè 1):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Äëÿ ýëåìåíòà A[" << i << "] = '" << setA[i] << "': ";
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

    // Ââîä ìíîæåñòâà A
    cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ ìíîæåñòâà A: ";
    cin >> sizeA;
    cout << "Ââåäèòå ýëåìåíòû ìíîæåñòâà A:\n";
    for (int i = 0; i < sizeA; ++i) {
        char elem;
        cout << "A[" << i << "] = ";
        cin >> elem;
        setA.push_back(elem);
    }

    // Ââîä ìíîæåñòâà B
    cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ ìíîæåñòâà B: ";
    cin >> sizeB;
    cout << "Ââåäèòå ýëåìåíòû ìíîæåñòâà B:\n";
    for (int i = 0; i < sizeB; ++i) {
        char elem;
        cout << "B[" << i << "] = ";
        cin >> elem;
        setB.push_back(elem);
    }

    // Ââîä ìàòðèöû è ïîñòðîåíèå îòíîøåíèÿ
    inputRelationMatrix(relation, setA, setB);

    // Ïðîâåðêà
    cout << "Îòíîøåíèå:\n";
    for (const auto& p : relation) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    if (isFunction(relation)) {
        cout << "Îòíîøåíèå ÿâëÿåòñÿ ôóíêöèåé.\n";
    }
    else {
        cout << "Îòíîøåíèå íå ÿâëÿåòñÿ ôóíêöèåé.\n";
    }

    return 0;
}
