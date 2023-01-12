#include <iostream>
#include <string>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>
#include <cstring>


void part1() {

    std::string input = std::string("yzbqklnj");
    std::string input_zahl;

    unsigned char result[MD5_DIGEST_LENGTH];

    for (int i = 0; i < 1000000; i++) {
        input_zahl = input + std::to_string(i);

        MD5((unsigned char*) input_zahl.c_str(), input_zahl.size(), result);

        int result0 = (int) result[0];
        int result1 = (int) result[1];
        int result2 = (int) result[2];

        if (result0 == 0 && result1 == 0 && result2 < 16) {
            std::ostringstream sout;
            sout << std::hex << std::setfill('0');
            for(auto c: result) sout<<std::setw(2)<<(int)c;

            std::cout << "MD5: " << sout.str() << "\n";
            std::cout << "Input: " << input_zahl << "\n";
            break;
        }

        std::memset(result, 0x00, sizeof(result));

    }
}

void part2() {

    std::string input = std::string("yzbqklnj");
    std::string input_zahl;

    unsigned char result[MD5_DIGEST_LENGTH];

    for (int i = 0; i < 100000000; i++) {
        input_zahl = input + std::to_string(i);

        MD5((unsigned char*) input_zahl.c_str(), input_zahl.size(), result);

        int result0 = (int) result[0];
        int result1 = (int) result[1];
        int result2 = (int) result[2];

        if (result0 == 0 && result1 == 0 && result2 == 0) {
            std::ostringstream sout;
            sout << std::hex << std::setfill('0');
            for(auto c: result) sout<<std::setw(2)<<(int)c;

            std::cout << "MD5: " << sout.str() << "\n";
            std::cout << "Input: " << input_zahl << "\n";
            break;
        }

        std::memset(result, 0x00, sizeof(result));
    }

}

int main ()
{
    // part1();
    part2();
}