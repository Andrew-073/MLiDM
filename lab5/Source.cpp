#include <iostream>
#include <vector>
#include <locale.h>
// я изменил активность
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    int n;
    cout << "Ñêîëüêî âåðøèí? ";
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    cout << "Ââîäèòå ìàòðèöó ñìåæíîñòè:\n";
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // äåëàåì êîïèþ
    vector<vector<int>> r = a;

    // àëãîðèò Óîðøåëëà
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (r[i][k] == 1 && r[k][j] == 1) {
                    r[i][j] = 1;
                }
            }
        }
    }

    cout << "Ìàòðèöà äîñòèæèìîñòè:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
    
