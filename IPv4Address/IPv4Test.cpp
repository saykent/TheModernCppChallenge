#include "IPv4Address.h"

int main()
{
    cppws::IPv4Address ipAddress(192, 168, 1, 123);
    std::cout << "First IP address: " << ipAddress << std::endl;


    auto nextIpAddress = cppws::IPv4Address(ipAddress.to_long() + 1);
    std::cout << "Next IP address: " << nextIpAddress << std::endl;


    bool isValidIp = false;
    cppws::IPv4Address ipFromUser;
    std::cout << "Initial IP : " << ipFromUser << std::endl;
    std::cout << "Enter a valid IP address: ";
    while (!isValidIp)
    {
        std::cin >> ipFromUser;
        if (!std::cin.fail())
            isValidIp = true;
    }
    std::cout << "Entered IP address : " << ipFromUser << std::endl;
}