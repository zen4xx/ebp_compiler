#include "parser.h"

int main(int argc, char **argv)
{
    if (argc <= 1)
        std::cout << "bad usage\n";

    std::ofstream bin("out", std::ios::binary | std::ios::out);
    if (!bin.is_open())
    {
        std::cerr << "failed to open out\n";
        return 1;
    }

    for (auto op : file_to_vector(argv[1]))
    {
        if (op == "NOP")
            bin << "0x00 ";
        else if (op == "HALT")
            bin << "0x01 ";
        else if (op == "LDAX")
            bin << "0x02 ";
        else if (op == "LDA")
            bin << "0x03 ";
        else if (op == "STA")
            bin << "0x04 ";
        else if (op == "LDBX")
            bin << "0x05 ";
        else if (op == "LDB")
            bin << "0x06 ";
        else if (op == "STB")
            bin << "0x07 ";
        else if (op == "ADDX")
            bin << "0x08 ";
        else if (op == "ADD")
            bin << "0x09 ";
        else if (op == "SUBX")
            bin << "0x0A ";
        else if (op == "SUB")
            bin << "0x0B ";
        else if (op == "OUTA")
            bin << "0x0C ";
        else if (op == "OUTB")
            bin << "0x0D ";
        else if (op == "OUTX")
            bin << "0x0E ";
        else if (op == "OUT")
            bin << "0x0F ";
        else if (op == "JP")
            bin << "0x10 ";
        else if (op == "JPZ")
            bin << "0x11 ";
        else if (op == "JPC")
            bin << "0x12 ";
    }
    bin.close();
    return 0;
}