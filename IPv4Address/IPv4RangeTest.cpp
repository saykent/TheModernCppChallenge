#include "IPv4Address.h"

int main()
{
    bool isValidIp = false;
    cppws::IPv4Address firstIP, secondIP;
    std::cout << "Enter 2 valid IP addresses: ";
    while (!isValidIp)
    {
        std::cin >> firstIP >> secondIP;
        if (!std::cin.fail())
            isValidIp = true;
    }

    cppws::IPv4Address start, end;
    if (firstIP <= secondIP)
    {
        start = firstIP;
        end = secondIP;
    }
    else
    {
        start = secondIP;
        end = firstIP;
    }

    while (start <= end)
        std::cout << start++ << std::endl;
}