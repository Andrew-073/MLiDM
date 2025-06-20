#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

// ��������� ��� �������� ���� (a, b)
struct Pair {
    char first;
    char second;
};

// ��������, �������� �� ��������� ��������
bool isFunction(const vector<Pair>& relation) {
    for (int i = 0; i < relation.size(); ++i) {
        for (int j = i + 1; j < relation.size(); ++j) {
            if (relation[i].first == relation[j].first &&
                relation[i].second != relation[j].second) {
                return false; // ������ a ������������ ������ b
            }
        }
    }
    return true;
}

// ���� ��������� � ���� �������
void inputRelationMatrix(vector<Pair>& relation, const vector<char>& setA, const vector<char>& setB) {
    int n = setA.size();
    int m = setB.size();

    cout << "������� ������� " << n << "x" << m << " (0 ��� 1):\n";
    for (int i = 0; i < n; ++i) {
        cout << "��� �������� A[" << i << "] = '" << setA[i] << "': ";
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

    // ���� ��������� A
    cout << "������� ���������� ��������� ��������� A: ";
    cin >> sizeA;
    cout << "������� �������� ��������� A:\n";
    for (int i = 0; i < sizeA; ++i) {
        char elem;
        cout << "A[" << i << "] = ";
        cin >> elem;
        setA.push_back(elem);
    }

    // ���� ��������� B
    cout << "������� ���������� ��������� ��������� B: ";
    cin >> sizeB;
    cout << "������� �������� ��������� B:\n";
    for (int i = 0; i < sizeB; ++i) {
        char elem;
        cout << "B[" << i << "] = ";
        cin >> elem;
        setB.push_back(elem);
    }

    // ���� ������� � ���������� ���������
    inputRelationMatrix(relation, setA, setB);

    // ��������
    cout << "���������:\n";
    for (const auto& p : relation) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    if (isFunction(relation)) {
        cout << "��������� �������� ��������.\n";
    }
    else {
        cout << "��������� �� �������� ��������.\n";
    }

    return 0;
}
