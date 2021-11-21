#include "permutation.h"

#include <iostream>
#include <vector>

std::vector<std::string> permutation(std::string input) {
    std::vector<std::string> output{};
    if (input.size() == 1) { return std::vector{input}; }
    if (input.size() > 1) {
        for (auto const& x : permutation(input.substr(1))) {
            auto insert_rest = insert(input[0], x);
            output.insert(output.end(), insert_rest.begin(), insert_rest.end());
        }
    }
    return output;
}
std::vector<std::string> insert(char first, std::string rest) {
    if (rest.size() == 0) return std::vector<std::string>{std::string{first}};
    std::vector<std::string> output{first + rest};
    char restF = rest[0];
    std::string restT = rest.substr(1);
    for (std::string const& x : insert(first, restT)) {
        output.emplace_back(restF + x);
    }
    return output;
}

void permute(std::string a, int l, int r) {
    // Base case
    if (l == r)
        std::cout << a << std::endl;
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {
            // Swapping done
            std::swap(a[l], a[i]);

            // Recursion called
            permute(a, l + 1, r);

            //backtrack
            std::swap(a[l], a[i]);
        }
    }
}
