#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

const std::vector<std::string> disallowed{"ab", "cd", "pq", "xy"};
const std::vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

bool found_three_vowels(std::string line) {
    int found_vowels = 0;
    std::string::size_type start_pos = 0;
    for (char vowel : vowels) {
        while (std::string::npos != (start_pos = line.find(vowel, start_pos))) {
            ++start_pos;
            found_vowels++;
        }
        start_pos = 0;
    }

    if (found_vowels >= 3) {
        return true;
    } else {
        return false;
    }
}

bool found_naughty_word(std::string line) {
    for (std::string dis : disallowed) {
        if (std::string::npos != line.find(dis)) {
            return true;
        }
    }
    return false;
}

bool found_letter_double(std::string line) {
    for (std::string::size_type i = 1; i < line.size(); i++) {
        if (line[i-1] == line[i]) {
            return true;
        }
    }
    return false;
    
}

void part1() {
    std::ifstream input {"input.txt"};
    std::string line;
    int nice_strings = 0;

    if (input.good()) {
        while (input >> line) {

            if (found_letter_double(line) == false) {
                // std::cout << "Double letter not found!\n";
                continue;
            }

            if (found_three_vowels(line) == false) {
                // std::cout << "Vowels not found!";
                continue;
            }

            if (found_naughty_word(line)) {
                continue;
            }
            nice_strings++;
        }
    }
    std::cout << "Nice Strings: " << nice_strings << "\n";
}

bool check_xyy(std::string line) {
    for (std::string::size_type i = 0; i < line.size()-2; i++) {
        if (line[i] == line[i+2]) {
            return true;
        }
    }
    return false;
}

bool find_pair_of_2_letters(std::string line) {

    std::string letters;
    int found_letters = 0;
    std::string::size_type start_pos = 0;

    for (std::string::size_type i = 0; i < line.size()-2; i++) {
        letters = line.substr(i, 2);

        while (std::string::npos != (start_pos = line.find(letters, start_pos))) {
            start_pos+=2;
            found_letters++;
            if (found_letters >= 2) return true;
        }
        start_pos = 0;
        found_letters = 0;
    }
    return false;
}

void part2() {

    std::ifstream input {"input.txt"};
    std::string line;
    int nice_strings = 0;

    if (input.good()) {
        while (input >> line) {

            if (check_xyy(line) == false) {
                continue;
            }

            if (find_pair_of_2_letters(line) == false) {
                continue;
            }
            nice_strings++;
        }
    }
    std::cout << "Nice Strings: " << nice_strings << "\n";

}

int main() {

    part1();

    part2();

}