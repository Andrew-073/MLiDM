#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Element {
    char evenNumber1; // Первый - четное число
    char letter1;     // Второй символ
    char evenNumber2; // Третий - четное число
    char number;      // Четвертый - нечетное число
};

void inputArray(vector<Element>& mass, int size) {
    Element elem;
    for (int i = 0; i < size; ++i) {
        cout << "Input Element ibij " << i << ": ";
        string input;
        cin >> input;

        if (input.length() == 4 &&
            (input[0] >= '0' && input[0] <= '9') &&
            (input[1] >= 'a' && input[1] <= 'z') &&
            (input[2] >= '0' && input[2] <= '9') && (input[2] - '0') % 2 == 0 &&
            (input[3] >= '0' && input[3] <= '9') && (input[3] - '0') % 2 != 0)
        {
            elem.evenNumber1 = input[0];
            elem.letter1 = input[1];
            elem.evenNumber2 = input[2];
            elem.number = input[3];
            mass.push_back(elem);
        }
        else {
            cout << "Error input" << endl;
            i--;
        }
    }
}

void printArray(const vector<Element>& mass) {
    for (int i = 0; i < mass.size(); ++i) {
        cout << "Element " << i << ": "
            << mass[i].evenNumber1
            << mass[i].letter1
            << mass[i].evenNumber2
            << mass[i].number << endl;
    }
}

void removeNonUnique(vector<Element>& mass) {
    vector<Element> uniqueElements;
    for (int i = 0; i < mass.size(); ++i) {
        bool isUnique = true;
        for (int j = 0; j < uniqueElements.size(); ++j) {
            if (mass[i].evenNumber1 == uniqueElements[j].evenNumber1 &&
                mass[i].letter1 == uniqueElements[j].letter1 &&
                mass[i].evenNumber2 == uniqueElements[j].evenNumber2 &&
                mass[i].number == uniqueElements[j].number) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueElements.push_back(mass[i]);
        }
    }
    mass = uniqueElements;
}

bool areEqual(const Element& a, const Element& b) {
    return a.evenNumber1 == b.evenNumber1 &&
        a.letter1 == b.letter1 &&
        a.evenNumber2 == b.evenNumber2 &&
        a.number == b.number;
}

//объединение
void unionArrays(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
    result = mass1;
    result.insert(result.end(), mass2.begin(), mass2.end());
    removeNonUnique(result);
}

//пересечение
void intersectionArrays(vector<Element>& result, const vector<Element>& mass1, const vector<Element>& mass2) {
    for (const auto& e1 : mass1) {
        for (const auto& e2 : mass2) {
            if (areEqual(e1, e2)) {
                result.push_back(e1);
                break;
            }
        }
    }
    removeNonUnique(result);
}

//дополнение
void differenceArrays(vector<Element>& result, const vector<Element>& A, const vector<Element>& B) {
    for (const auto& eA : A) {
        bool found = false;
        for (const auto& eB : B) {
            if (areEqual(eA, eB)) {
                found = true;
                break;
            }
        }
        if (!found)
            result.push_back(eA);
    }
    removeNonUnique(result);
}

//симметричная разность
void symmetricDifferenceArrays(vector<Element>& result, const vector<Element>& A, const vector<Element>& B) {
    vector<Element> diffAB, diffBA;
    differenceArrays(diffAB, A, B);
    differenceArrays(diffBA, B, A);
    result = diffAB;
    result.insert(result.end(), diffBA.begin(), diffBA.end());
    removeNonUnique(result);
}

int main() {
    int size1, size2;
    vector<Element> mass1, mass2, mass_unification;

    cout << "Input SIZE first array: ";
    cin >> size1;
    inputArray(mass1, size1);
    cout << "\n";

    cout << "Input SIZE second array: ";
    cin >> size2;
    inputArray(mass2, size2);
    cout << "\n";

    cout << "ELEMENTS first array not unique: " << endl;
    printArray(mass1);
    cout << "\n";

    removeNonUnique(mass1);
    cout << "ELEMENTS first array: " << endl;
    printArray(mass1);
    cout << "\n";

    cout << "ELEMENTS second array: " << endl;
    printArray(mass2);
    cout << "\n";
    
    removeNonUnique(mass2);

    unionArrays(mass_unification, mass1, mass2);
    cout << "ELEMENTS union arrays: " << endl;
    printArray(mass_unification);
    cout << "\n";

    vector<Element> mass_intersection;
    intersectionArrays(mass_intersection, mass1, mass2);
    cout << "ELEMENTS intersection arrays: " << endl;
    printArray(mass_intersection);
    cout << "\n";

    vector<Element> mass_difference_AB;
    differenceArrays(mass_difference_AB, mass1, mass2);
    cout << "ELEMENTS A \\ B: " << endl;
    printArray(mass_difference_AB);
    cout << "\n";

    vector<Element> mass_difference_BA;
    differenceArrays(mass_difference_BA, mass2, mass1);
    cout << "ELEMENTS B \\ A: " << endl;
    printArray(mass_difference_BA);
    cout << "\n";

    vector<Element> mass_sym_diff;
    symmetricDifferenceArrays(mass_sym_diff, mass1, mass2);
    cout << "ELEMENTS symmetric difference (A XOR B): " << endl;
    printArray(mass_sym_diff);
    cout << "\n";

    return 0;
}
