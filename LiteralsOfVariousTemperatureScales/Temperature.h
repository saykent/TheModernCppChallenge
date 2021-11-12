#ifndef THEMODERNCPPCHALLENGE_TEMPERATURE_H
#define THEMODERNCPPCHALLENGE_TEMPERATURE_H

#include <iostream>
#include <cmath>

namespace temperature {

bool are_equal(const double d1, const double d2, const double epsilon = 0.001)
{
    return std::fabs(d1 - d2) < epsilon;
}

enum class scale { celsius, fahrenheit, kelvin };

template<scale S>
class quantity
{
public:
    constexpr explicit quantity(const double a) : amount_{a} {}
    explicit operator double() const { return amount_; }

private:
    const double amount_;
};

template<scale S>
inline bool operator==(const quantity<S>& lhs, const quantity<S>& rhs)
{
    return are_equal(static_cast<double>(lhs), static_cast<double>(rhs));
}

template<scale S>
inline bool operator!=(const quantity<S>& lhs, const quantity<S>& rhs)
{
    return !(lhs == rhs);
}

template<scale S>
inline bool operator<(const quantity<S>& lhs, const quantity<S>& rhs)
{
    return static_cast<double>(lhs) < static_cast<double>(rhs);
}

template<scale S>
inline bool operator>(const quantity<S>& lhs, const quantity<S>& rhs)
{
    return rhs < lhs;
}

template<scale S>
inline bool operator<=(const quantity<S>& lhs, const quantity<S>& rhs)
{
    return !(lhs > rhs);
}

template<scale S>
inline bool operator>=(const quantity<S>& lhs, const quantity<S>& rhs)
{
    return !(lhs < rhs);
}

template<scale S>
constexpr quantity<S> operator+(const quantity<S>& q1, const quantity<S>& q2)
{
    return quantity<S>(static_cast<double>(q1) + static_cast<double>(q2));
}

template<scale S>
constexpr quantity<S> operator-(const quantity<S>& q1, const quantity<S>& q2)
{
    return quantity<S>(static_cast<double>(q1) - static_cast<double>(q2));
}

template<scale S, scale R>
struct conversion_traits
{
        static double convert(const double value) = delete;
};

template<>
struct conversion_traits<scale::celsius, scale::kelvin>
{
    static double convert(const double value)
    {
        return value + 273.15;
    }
};

template <>
struct conversion_traits<scale::kelvin, scale::celsius>
{
    static double convert(double const value)
    {
        return value - 273.15;
    }
};

template <>
struct conversion_traits<scale::celsius, scale::fahrenheit>
{
    static double convert(double const value)
    {
        return (value * 9) / 5 + 32;;
    }
};

template <>
struct conversion_traits<scale::fahrenheit, scale::celsius>
{
    static double convert(double const value)
    {
        return (value - 32) * 5 / 9;
    }
};

template <>
struct conversion_traits<scale::fahrenheit, scale::kelvin>
{
    static double convert(double const value)
    {
        return (value + 459.67) * 5 / 9;
    }
};

template <>
struct conversion_traits<scale::kelvin, scale::fahrenheit>
{
    static double convert(double const value)
    {
        return (value * 9) / 5 - 459.67;
    }
};

template<scale R, scale S>
constexpr quantity<R> temperature_cast(const quantity<S> q)
{
    return quantity<R>(conversion_traits<S, R>::convert(static_cast<double>(q)));
}

namespace temperature_scale_literals {
    constexpr quantity<scale::celsius> operator""_deg(const long double amount)
    {
        return quantity<scale::celsius> {static_cast<double>(amount)};
    }

    constexpr quantity<scale::fahrenheit> operator""_f(const long double amount)
    {
        return quantity<scale::fahrenheit> {static_cast<double>(amount)};
    }

    constexpr quantity<scale::kelvin> operator""_k(const long double amount)
    {
        return quantity<scale::kelvin> {static_cast<double>(amount)};
    }
}

}


#endif //THEMODERNCPPCHALLENGE_TEMPERATURE_H
