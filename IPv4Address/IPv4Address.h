#ifndef IPV4_ADDRESS_H
#define IPV4_ADDRESS_H

#include <iostream>
#include <sstream>
#include <array>
#include <vector>

namespace cppws {
class IPv4Address
{
public:
    //Constructors
    IPv4Address() : ipAddress_{0} {}
    explicit IPv4Address(unsigned long ipAddress) : ipAddress_{ {
          static_cast<unsigned char>((ipAddress >> 24) & 0xFF),
          static_cast<unsigned char>((ipAddress >> 16) & 0xFF),
          static_cast<unsigned char>((ipAddress >> 8) & 0xFF),
          static_cast<unsigned char>((ipAddress >> 0) & 0xFF)
        }} {}
    explicit IPv4Address(const unsigned char ip1, const unsigned char ip2,
                         const unsigned char ip3, const unsigned char ip4)
                         : ipAddress_{{ip1, ip2, ip3, ip4}} {}
    IPv4Address(const IPv4Address& other) noexcept : ipAddress_{other.ipAddress_} {}
    IPv4Address(const IPv4Address&& other) noexcept : ipAddress_{other.ipAddress_} {}

    IPv4Address& operator=(const IPv4Address& other) noexcept
    {
        ipAddress_ = other.ipAddress_;

        return *this;
    }

    IPv4Address& operator=(IPv4Address&& other) noexcept
    {
        ipAddress_ = other.ipAddress_;

        return *this;
    }

    IPv4Address& operator++()
    {
        *this = IPv4Address(1 + to_long());
        return *this;
    }

    IPv4Address operator++(int)
    {
        IPv4Address iPv4Address(*this);
        ++(*this);

        return iPv4Address;
    }

    std::string to_string() const
    {
        std::stringstream ss;
        ss << *this;

        return ss.str();
    }

    constexpr unsigned long to_long() const noexcept
    {
        return (static_cast<unsigned long>(ipAddress_[0]) << 24) |
               (static_cast<unsigned long>(ipAddress_[1]) << 16) |
               (static_cast<unsigned long>(ipAddress_[2]) <<  8) |
               (static_cast<unsigned long>(ipAddress_[3]) <<  0);
    }

    friend std::ostream& operator<<(std::ostream& os, const IPv4Address& ip)
    {
        os << static_cast<int>(ip.ipAddress_[0]) << '.'
           << static_cast<int>(ip.ipAddress_[1]) << '.'
           << static_cast<int>(ip.ipAddress_[2]) << '.'
           << static_cast<int>(ip.ipAddress_[3]);

        return os;
    }

    friend std::istream& operator>>(std::istream& is, IPv4Address& ip)
    {
        char d1, d2, d3;
        int ip1, ip2, ip3, ip4;

        is >> ip1 >> d1 >> ip2 >> d2 >> ip3 >> d3 >> ip4;
        if (d1 == '.' && d2 == '.' && d3 == '.')
            ip = IPv4Address(ip1, ip2, ip3, ip4);
        else
            is.setstate(std::ios_base::failbit);

        return is;
    }

    friend bool operator==(const IPv4Address& ip1, const IPv4Address& ip2) noexcept
    {
        return ip1.ipAddress_ == ip2.ipAddress_;
    }

    friend bool operator!=(const IPv4Address& ip1, const IPv4Address& ip2) noexcept
    {
        return !(ip1 == ip2);
    }

    friend bool operator<(const IPv4Address& ip1, const IPv4Address& ip2) noexcept
    {
        return ip1.to_long() < ip2.to_long();
    }

    friend bool operator>(const IPv4Address& ip1, const IPv4Address& ip2) noexcept
    {
        return ip2 < ip1;
    }

    friend bool operator<=(const IPv4Address& ip1, const IPv4Address& ip2) noexcept
    {
        return !(ip1 > ip2);
    }

    friend bool operator>=(const IPv4Address& ip1, const IPv4Address& ip2) noexcept
    {
        return !(ip1 < ip2);
    }

private:
    std::array<unsigned char, 4> ipAddress_;
};
}

#endif