#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

int part1(std::string input) {
    int platform = 0;

    for(char& c : input) {
        if (c == '(') {
            platform++;
        } else if (c == ')') {
            platform--;
        }
    }

    return platform;
}

int part2(std::string input) {
    int platform = 0;
    int position = 0;

    for(char& c : input) {
        position++;
        if (c == '(') {
            platform++;
        } else if (c == ')') {
            platform--;
        }
        
        if (platform == -1) {
            return position;
        }
    }

    return position;
}

int main ()
{
    
    std::ifstream t("input.txt");
    std::string s_input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    
    // int floor = part1(s_input);
    // std::cout << "Platform: " << floor;

    int position = part2(s_input);
    std::cout << "Position: " << position;
}