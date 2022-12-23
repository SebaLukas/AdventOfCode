#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

int main ()
{
    int platform = 0;
    std::ifstream t("input.txt");
    std::string s_input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    for(char& c : s_input) {
        if (c == '(') {
            platform++;
        } else if (c == ')') {
            platform--;
        }
    }

    std::cout << "Platform: " << platform;
}