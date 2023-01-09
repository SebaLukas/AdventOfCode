#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <vector>
#include <algorithm>

int main ()
{

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

    std::cout << positions.size() << " houses receive at least one present!\n";

}