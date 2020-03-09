#include <iostream>
#include <cmath>

void MergeSort(int[], int);

int main() {
    int m;
    std::cin >> m;
    int array[m];
    for(int i = 0; i < m; i++) {
        std::cin >> array[i];
    }
    MergeSort(array, m);
    for(int i = 0; i < m; i++) {
        std::cout << array[i] << " ";
    }
}

void MergeSort (int *C, int currLength) {
    if(currLength > 1) {
        int m_A = ceil((double)currLength/2);
        int m_B = currLength/2;
        int A[m_A];
        int B[m_B];
        int index = 0;
        for(int i = 0; i < m_A; i++) {
            A[index] = C[i];
            index++;
        }
        index = 0;
        for(int i = m_A; i < currLength; i++) {
            B[index] = C[i];
            index++;
        }
        MergeSort(A, m_A);
        MergeSort(B, m_B);
        //Testing:
        /*
        std::cout << "A is: ";
        for(int i = 0; i < m_A; i++) {
            std::cout << A[i] << " ";
        }
        std::cout << "\n";
        std::cout << "B is: ";
        for(int i = 0; i < m_B; i++) {
            std::cout << B[i] << " ";
        }
        std::cout << "\n";
        std::cout << "currLength: " << currLength << "\n";
         */

        int i = 0;
        int j = 0;
        for(int k = 0; k < currLength; k++) {
            if(A[i] < B[j]) {
                C[k] = A[i];
                i++;
            }
            else {
                C[k] = B[j];
                j++;
            }
            if(i >= m_A) {
                for(k = k + 1; k < currLength; k++) {
                    C[k] = B[j];
                    j++;
                }
                break;
            }
            if(j >= m_B) {
                for(k = k + 1; k < currLength; k++) {
                    C[k] = A[i];
                    i++;
                }
                break;
            }
        }
        //Testing:
        /*
        std::cout << "Sorted 'C': ";
        for(int k = 0; k < currLength; k++) {
            std::cout << C[k] << " ";
        }
        std::cout << "\n\n";
         */
    }
}
