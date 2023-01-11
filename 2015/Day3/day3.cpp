#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <vector>
#include <algorithm>

void part1() {
    std::ifstream t("input.txt");
    std::string s_input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    std::vector<int> positions;
    int position_x, position_y = 0;

    positions.push_back(0); //First home

    for(char& c : s_input) {

        switch (c)
        {
        case '>':
            position_x++;
            break;
        case '<':
            position_x--;
            break;
        case '^':
            position_y--;
            break;
        case 'v':
            position_y++;
            break;
        }
        positions.push_back( 1000*position_x + position_y);
    }

    std::sort(positions.begin(), positions.end());

    auto uni = std::unique(positions.begin(), positions.end());
    
    positions.erase(uni, positions.end());

    std::cout << "Part1: " << positions.size() << " houses receive at least one present!\n";
}

void part2() {
    std::ifstream t("input.txt");
    std::string s_input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    std::vector<int> positions;
    int position_x = 0;
    int position_y = 0;
    int position_robo_x = 0;
    int position_robo_y = 0;

    positions.push_back(0); //First home

    bool santa = true;

    for(char& c : s_input) {

        switch (c)
        {
        case '>':
            if (santa) {
                position_x++;
            } else {
                position_robo_x++;
            }
            break;
        case '<':
            if (santa) {
                position_x--;
            } else {
                position_robo_x--;
            }
            break;
        case '^':
            if (santa) {
                position_y++;
            } else {
                position_robo_y++;
            }
            break;
        case 'v':
            if (santa) {
                position_y--;
            } else {
                position_robo_y--;
            }
            break;
        }

        if (santa) {
            positions.push_back(100*position_x + position_y);
            santa = false;
        } else {
            positions.push_back(100*position_robo_x + position_robo_y);
            santa = true;
        }
    }

    std::sort(positions.begin(), positions.end());

    auto uni = std::unique(positions.begin(), positions.end());
    
    positions.erase(uni, positions.end());

    std::cout << "Part2: " << positions.size() << " houses receive at least one present!\n";
}

int main ()
{
    part1();
    part2();
}