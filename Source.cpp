#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    int n;
    cout << "Сколько вершин? ";
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    cout << "Вводите матрицу смежности:\n";
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // делаем копию
    vector<vector<int>> r = a;

    // алгорит Уоршелла
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (r[i][k] == 1 && r[k][j] == 1) {
                    r[i][j] = 1;
                }
            }
        }
    }

    cout << "Матрица достижимости:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
    