#include <bitset>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <valarray>
#include <vector>

using namespace std;

static const int B64index[256] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  62, 63, 62, 62, 63, 52, 53, 54, 55, 56, 57,
    58, 59, 60, 61, 0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,
    7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
    25, 0,  0,  0,  0,  63, 0,  26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
    37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51};

std::string b64decode(const void* data, const size_t len) {
    unsigned char* p = (unsigned char*)data;
    int pad = len > 0 && (len % 4 || p[len - 1] == '=');
    const size_t L = ((len + 3) / 4 - pad) * 4;
    std::string str(L / 4 * 3 + pad, '\0');

    for (size_t i = 0, j = 0; i < L; i += 4) {
        int n = B64index[p[i]] << 18 | B64index[p[i + 1]] << 12 |
                B64index[p[i + 2]] << 6 | B64index[p[i + 3]];
        str[j++] = n >> 16;
        str[j++] = n >> 8 & 0xFF;
        str[j++] = n & 0xFF;
    }
    if (pad) {
        int n = B64index[p[L]] << 18 | B64index[p[L + 1]] << 12;
        str[str.size() - 1] = n >> 16;

        if (len > L + 2 && p[L + 2] != '=') {
            n |= B64index[p[L + 2]] << 6;
            str.push_back(n >> 8 & 0xFF);
        }
    }
    return str;
}
char reverseBits(char n) {
    char r = 0;
    for (int counter = 8; counter > 0; --counter) {
        auto x = n & 0x01;
        r = r << 1 | x;
        n = n >> 1;
    }
    return r;
}

int vtoi(vector<char> vec)// vector of char to int
{
    uint ret;

    for (int i = 0; i <= 3; ++i) {
        ret = ret << 8;
        ret = ret | u_char(vec[i]);
    }
    return ret;
}

string vtos(vector<char> vec, int& off, int length)// vector to string
{
    string ret = "";
    int offset = off;
    auto first_seven_bit = 0xFE;
    auto first_six_bit = 0xFC;
    auto first_five_bit = 0xF8;
    auto first_four_bit = 0xF0;
    auto first_three_bit = 0xE0;
    auto first_two_bit = 0xC0;
    auto first_one_bit = 0x80;
    auto last_seven_bit = 0x7F;
    auto last_six_bit = 0x3F;
    auto last_five_bit = 0x1F;
    auto last_four_bit = 0x0F;
    auto last_three_bit = 0x07;
    auto last_two_bit = 0x03;
    auto last_one_bit = 0x01;

    for (; offset < off + length * 7; offset += 7) {
        unsigned int take_first = offset % 8;
        unsigned int take_second = 7 - take_first;
        unsigned char first_char = vec[offset / 8];
        auto b = bitset<8>(first_char);
        // cout << "first_char: " << b << endl;
        unsigned char second_char = vec[offset / 8 + 1];
        // cout << "second_char: " << bitset<8>(second_char) << endl;
        unsigned char tmp;
        switch (take_first) {
        case 0:
            tmp = (first_char & first_seven_bit) >> 1;
            ret += tmp;
            break;
        case 7:
            tmp = (first_char & last_one_bit) << 6 |
                  (second_char & first_six_bit) >> 2;
            ret += tmp;
            break;
        case 6:
            tmp = (first_char & last_two_bit) << 5 |
                  (second_char & first_five_bit) >> 3;
            ret += tmp;
            break;
        case 5:
            tmp = (first_char & last_three_bit) << 4 |
                  (second_char & first_four_bit) >> 4;
            ret += tmp;
            break;
        case 4:
            tmp = (first_char & last_four_bit) << 3 |
                  (second_char & first_three_bit) >> 5;
            ret += tmp;
            break;
        case 3:
            tmp = (first_char & last_five_bit) << 2 |
                  (second_char & first_two_bit) >> 6;
            ret += tmp;
            break;
        case 2:
            tmp = (first_char & last_six_bit) << 1 |
                  (second_char & first_one_bit) >> 7;
            ret += tmp;
            break;
        case 1: ret += (first_char & last_seven_bit); break;
        }
    }
    off = offset;
    return ret;
}

int process() {
    string data;
    std::string file_contents;
    std::ifstream myfile;
    myfile.open("../data");

    if (myfile.is_open()) {// always check whether the file is open
        while (myfile.good()) {
            getline(myfile, data);
            file_contents += data;
            file_contents.push_back('\n');
        }
    }

    const std::string decoded =
        b64decode(file_contents.c_str(), file_contents.length());

    auto cs = decoded.c_str();

    bitset version = bitset<8>(cs[0]);
    cout << "Version: " << version.to_ulong() << endl;

    bitset checksum = bitset<8>(cs[1]);

    cout << "Checksum: " << checksum.to_ulong() << endl;

    auto order_seed_chars = std::vector<char>{cs[5], cs[4], cs[3], cs[2]};
    auto order_seed = vtoi(order_seed_chars);

    auto key = order_seed & 0xFF;

    cout << "Key: " << key << endl;

    vector<char> decrypted_chars;
    int len = decoded.length();
    cout << "len: " << len << endl;
    for (int i = 0; i < len; i++) {
        if (i < 6) {
            decrypted_chars.push_back(cs[i]);
        } else {
            decrypted_chars.push_back(cs[i] ^ key);
        }
    }
    cout << "Order seed: " << order_seed << endl;

    auto error_index = vtoi(std::vector<char>{cs[9], cs[8], cs[7], cs[6]});
    cout << "error index: " << error_index << endl;

    auto marker = 10;
    auto offset = 0;
    while (marker < len) {

        int string_length = bitset<8>(decrypted_chars[marker]).to_ulong();
        cout << "string length: " << string_length << endl;

        vector<char> string_data;

        string_data.assign(
            decrypted_chars.begin() + marker + 1,
            decrypted_chars.begin() + marker + 1 + string_length);

        auto x = vtos(string_data, offset, string_length);
        marker += string_length * 7 / 8 + 1;
        cout << x << endl;
    }

    return 0;
}
