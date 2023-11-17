
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char *argv[]) {

    if (argc != 4) {
        std::cout << "invalid args" << std::endl;
        return 0;
    }

    std::string infile(argv[1]), from(argv[2]), to(argv[3]);

    std::ifstream in(infile.c_str());
    if (!in) {
        std::cout << "cannot open \"" << infile << "\"" << std::endl;
        return 0;
    }
    std::ofstream out((infile + ".replace").c_str());
    if (!out) {
        std::cout << "cannot open \"" << infile << ".replace\"" << std::endl;
        return 0;
    }

    std::string out_str;
    char c;
    while (in.get(c)) {
        out_str += c;
        int offset = out_str.size() - from.size();
        if (offset >= 0 && out_str.substr(offset, out_str.size()) == from) {
            out_str.erase(out_str.begin() + offset, out_str.end());
            out_str += to;
        }
    }

    out << out_str;
}
