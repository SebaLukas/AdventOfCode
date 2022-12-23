#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> split (const std::string &s, char delim) {
    std::vector<int> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (std::stoi(item));
    }
    return result;
}

int main() {

    std::ifstream input {"input.txt"};
    std::string line;
    std::vector<int> v_input;
    int wrapping_paper_sqfeet = 0;

    int total_ribbon = 0;

    if (input.good()) {
        while (input >> line) {
            v_input = split(line, 'x');

            int side_l_w = v_input[0] * v_input[1];
            int side_w_h = v_input[1] * v_input[2];
            int side_h_l = v_input[2] * v_input[0];
            std::vector<int> sides {side_l_w, side_w_h, side_h_l};

            wrapping_paper_sqfeet += 2 * side_l_w + 2 * side_w_h + 2 * side_h_l + *std::min_element(sides.begin(), sides.end());
            
            std::sort(v_input.begin(), v_input.end());
            total_ribbon += v_input[0] + v_input[0] + v_input[1] + v_input[1] + v_input[0] * v_input[1] * v_input[2];

        }
    }

    std::cout << "Total sqaure feet of wrapping paper: " << wrapping_paper_sqfeet << "\n";
    std::cout << "Total feet of ribbon: " << total_ribbon << "\n";
}