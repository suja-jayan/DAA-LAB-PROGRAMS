#include <iostream>
#include <vector>

int count = 0;
std::vector<int> w;
int d;
std::vector<int> x;

void subset(int cs, int k, int r) {
    if (cs == d) {
        std::cout << "Subset solution = " << ++count << std::endl;
        for (int i = 0; i < k; i++) {
            if (x[i] == 1) {
                std::cout << w[i] << " ";
            }
        }
        std::cout << std::endl;
    }
    if (k >= w.size() || cs > d) {
        return;
    }

    x[k] = 1;
    subset(cs + w[k], k + 1, r - w[k]);
    x[k] = 0;
    subset(cs, k + 1, r - w[k]);
}

int main() {
    int sum = 0;
    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    w.resize(n);
    x.resize(n);

    std::cout << "Enter the elements in ascending order:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
        sum += w[i];
    }

    std::cout << "Enter the required sum: ";
    std::cin >> d;

    if (sum < d) {
        std::cout << "No solution exists" << std::endl;
    } else {
        std::cout << "The solution is:" << std::endl;
        count = 0;
        subset(0, 0, sum);
    }

    return 0;
}
