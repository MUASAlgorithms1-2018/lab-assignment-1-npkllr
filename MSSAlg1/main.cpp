#include <iostream>

int cubic_mss(const int arr[], int size);
int quadratic_mss(const int arr[], int size);
int linear_mss(const int arr[], int size);

using namespace std;

int main() {
    static const int arr1[] = {1, 2, -30, 4, 5};
    static const int arr2[] = {3, 1, -15, 4, 5, -1, 2};
    static const int arr3[] = {1, -1, 1};
    static const int arr4[] = {5, -17, 12, 5, -10, 6, 4, 8, -5, -10, -17, 22, 1};
    static const int arr5[] = {11, -32, 1, -2, 29, 120, -12, 44, -73, -36, 12, -19, 2, 123, 43, 65, 87, -23, 12, 56, -2, 8, 45, 7, -46};

    int cmss1 = cubic_mss(arr1, sizeof(arr1) / sizeof(int));
    int cmss2 = cubic_mss(arr2, sizeof(arr2) / sizeof(int));
    int cmss3 = cubic_mss(arr3, sizeof(arr3) / sizeof(int));
    int cmss4 = cubic_mss(arr4, sizeof(arr4) / sizeof(int));
    int cmss5 = cubic_mss(arr5, sizeof(arr5) / sizeof(int));

    int qmss1 = quadratic_mss(arr1, sizeof(arr1) / sizeof(int));
    int qmss2 = quadratic_mss(arr2, sizeof(arr2) / sizeof(int));
    int qmss3 = quadratic_mss(arr3, sizeof(arr3) / sizeof(int));
    int qmss4 = quadratic_mss(arr4, sizeof(arr4) / sizeof(int));
    int qmss5 = quadratic_mss(arr5, sizeof(arr5) / sizeof(int));

    int lmss1 = linear_mss(arr1, sizeof(arr1) / sizeof(int));
    int lmss2 = linear_mss(arr2, sizeof(arr2) / sizeof(int));
    int lmss3 = linear_mss(arr3, sizeof(arr3) / sizeof(int));
    int lmss4 = linear_mss(arr4, sizeof(arr4) / sizeof(int));
    int lmss5 = linear_mss(arr5, sizeof(arr5) / sizeof(int));

    cout << endl << "Cubic MSS:" << endl;
    cout << "Test 1 " << (cmss1 == 9 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << cmss1 << endl;
    cout << "Test 2 " << (cmss2 == 10 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << cmss2 << endl;
    cout << "Test 3 " << (cmss3 == 1 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << cmss3 << endl;
    cout << "Test 4 " << (cmss4 == 25 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << cmss4 << endl;
    cout << "Test 5 " << (cmss5 == 488 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << cmss5 << endl;

    cout << endl << "Quadratic MSS:" << endl;
    cout << "Test 1 " << (qmss1 == 9 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << qmss1 << endl;
    cout << "Test 2 " << (qmss2 == 10 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << qmss2 << endl;
    cout << "Test 3 " << (qmss3 == 1 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << qmss3 << endl;
    cout << "Test 4 " << (qmss4 == 25 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << qmss4 << endl;
    cout << "Test 5 " << (qmss5 == 488 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << qmss5 << endl;

    cout << endl << "Linear MSS:" << endl;
    cout << "Test 1 " << (lmss1 == 9 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << lmss1 << endl;
    cout << "Test 2 " << (lmss2 == 10 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << lmss2 << endl;
    cout << "Test 3 " << (lmss3 == 1 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << lmss3 << endl;
    cout << "Test 4 " << (lmss4 == 25 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << lmss4 << endl;
    cout << "Test 5 " << (lmss5 == 488 ? "erfolgreich!" : "fehlgeschlagen!") << " Ergebnis: " << lmss5 << endl;

    return 0;
}

int cubic_mss(const int arr[], int size) {
    int maxSum = 0;

    for (int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            int thisSum = 0;

            for(int k = i; k <= j; k++){
                thisSum = thisSum + arr[k];
            }

            if(thisSum > maxSum){
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

int quadratic_mss(const int arr[], int size) {
    int maxSum = 0;

    for (int i = 0; i < size; i++){
        int thisSum = 0;
        for(int j = i; j < size; j++){
            thisSum = thisSum + arr[j];

            if(thisSum > maxSum){
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

int linear_mss(const int arr[], int size) {
    int maxSum = 0;
    int thisSum = 0;

    for (int i = 0; i < size; i++){
        thisSum = thisSum + arr[i];

        if(thisSum > maxSum){
            maxSum = thisSum;
        } else if (thisSum < 0){
            thisSum = 0;
        }
    }

    return maxSum;
}
