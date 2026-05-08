#include <iostream>
#include <vector>

int main() {
    std::vector<int> L1 = {5, 5, 5, 2, 2, 8};
    std::vector<int> L2;

    for (int i = 0; i < L1.size(); i++) {
        int count = 1;
        while (i + 1 < L1.size() && L1[i] == L1[i + 1]) {
            count++;
            i++;
        }
        L2.push_back(L1[i]);
        L2.push_back(count);
    }

    // Salida: 5 3 2 2 8 1
    for (int n : L2) std::cout << n << " ";
    
    return 0;
}