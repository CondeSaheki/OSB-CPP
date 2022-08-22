// 01/02/22

#pragma once
#include "type.h"
#include <vector>
#include <numbers>


namespace nimiat::math 
{

    /* concepts */

template <typename t> nodiscard inline constexpr bool is_positive(const t& num) noexcept
{
    if (num > 0) { return true; }
    return false;
}
template <typename t> nodiscard inline constexpr bool is_negative(const t& num) noexcept
{
    if (num < 0) { return true; }
    return false;
}
template <typename t> nodiscard inline constexpr bool is_null(const t& num) noexcept
{
    if (num == 0) { return true; }
    return false;
}

    /* types */

template <typename type> class rational // must be numeric
{
public:
    type numerator;
    type denominator;
public:
    constexpr rational() : numerator(static_cast<type>(1)), denominator(static_cast<type>(1)) {}
    template<typename t1> constexpr rational(const t1& first) : numerator(static_cast<type>(first)), denominator(static_cast<type>(1)) {}
    template<typename t1, typename t2>constexpr rational(const t1& first, const t2& second)
        : numerator(static_cast<type>(first)), denominator(static_cast<type>(second)) {}
public:
    nodiscard constexpr inline logical valid() noexcept
    {
        if (denominator == static_cast<type>(0)) { return false; }
        return true;
    }
    void simplify() noexcept
    {
        if ((*this).valid())
        {
            if (numerator == denominator)
            {
                numerator = 1;
                denominator = 1;
            }
            else
            {
                for (type i(modulo(numerator - denominator)); i != 1; --i) {
                    if (numerator % i == 0 && denominator % i == 0)
                    {
                        numerator /= i;
                        denominator /= i;
                        break;
                    }
                }
            }
        }
    }
};

    /* basic math operations */

template<typename type = long long> class addiction  // must be numeric
{
public: // data
    std::vector<type> terms;
public: // constructors
    constexpr addiction() : terms(std::vector<type>()) { terms.reserve(2); }
    constexpr addiction(const std::vector<type>& vec) : terms(vec) {};
    template<typename t1> constexpr addiction(const t1& first)
    {
        terms.reserve(2);
        terms.emplace_back(static_cast<type>(first));
    }
    template<typename t1, typename t2>constexpr addiction(const t1& first, const t2& second)
    {
        terms.reserve(2);
        terms.emplace_back(static_cast<type>(first));
        terms.emplace_back(static_cast<type>(second));
    }
public: // functions
    template<typename result = type> nodiscard constexpr result resolve() noexcept
    {
        result temp = static_cast<result>(0);
        for (auto it = terms.begin(); it != terms.end(); ++it)
        {
            temp += *it;
        }
        return temp;
    }
};
template<typename type = long long> class subtraction  // must be numeric
{
public: // data
    std::vector<type> terms;
public: // constructors
    constexpr subtraction() : terms(std::vector<type>()) { terms.reserve(2); }
    constexpr subtraction(const std::vector<type>& vec) : terms(vec) {};
    template<typename t1> constexpr subtraction(const t1& first)
    {
        terms.reserve(2);
        terms.emplace_back(static_cast<type>(first));
    }
    template<typename t1, typename t2>constexpr subtraction(const t1& first, const t2& second)
    {
        terms.reserve(2);
        terms.emplace_back(static_cast<type>(first));
        terms.emplace_back(static_cast<type>(second));
    }
public: // functions
    template<typename result = type> nodiscard constexpr result resolve()
    {
        result temp = static_cast<result>(0);
        for (auto it = terms.begin(); it != terms.end(); ++it)
        {
            temp -= *it;
        }
        return temp;
    }
};
template<typename type = long long> class multiplication  // must be numeric
{
public: // data
    std::vector<type> factors;
public: // constructors
    constexpr multiplication() : factors(std::vector<type>()) { factors.reserve(2); }
    constexpr multiplication(const std::vector<type>& vec) : factors(vec) {};
    template<typename t1> constexpr multiplication(const t1& first)
    {
        factors.reserve(2);
        factors.emplace_back(static_cast<type>(first));
    }
    template<typename t1, typename t2>constexpr multiplication(const t1& first, const t2& second)
    {
        factors.reserve(2);
        factors.emplace_back(static_cast<type>(first));
        factors.emplace_back(static_cast<type>(second));
    }
public: // functions
    template<typename result = type> nodiscard constexpr result resolve()
    {
        if (factors.empty()) { return 0; }

        result temp = static_cast<result>(1);
        for (auto i = factors.begin(); i != factors.end(); ++i)
        {
            //temp += ;
        }
        return temp;
    }
private: // private functions
    template<typename type, typename result = type> nodiscard inline constexpr result simple(const type& factor1, const type& factor2) noexcept
    {
        result temp = static_cast<result>(0);
        for (type i = static_cast<type>(0); i != factor2; ++i)
        {
            temp += factor1;
        }
    }
};
template<typename type = long long> class division  // must be numeric
{
public: // data
    std::vector<type> num;
public: // constructors
    constexpr division() : num(std::vector<type>()) { num.reserve(2); }
    constexpr division(const std::vector<type>& vec) : num(vec) {};
    template<typename t1> constexpr division(const t1& first)
    {
        num.reserve(2);
        num.emplace_back(static_cast<type>(first));
    }
    template<typename t1, typename t2>constexpr division(const t1& first, const t2& second)
    {
        num.reserve(2);
        num.emplace_back(static_cast<type>(first));
        num.emplace_back(static_cast<type>(second));
    }
public: // functions
    template<typename result> nodiscard constexpr result resolve() noexcept
    {
        if ((*this).valid())
        {
            //return static_cast<result>(num / den);
        }
        return static_cast<result>(0);
    }
    nodiscard constexpr inline bool valid() noexcept
    {
        for (auto it = num.begin; it != num.end(); ++it)
        {
            if (*it == static_cast<type>(0)) { return false; }
        }
        return true;
    }
};

    /* complex math operations */

template<typename type> class exponentiation
{
    type base;
    type expo;
    void resolve()
    {
        if (base == 1)
        {
            return base;
        }

        if (base == 0 || expo == 0)
        {
            return type(1);
        }

        if (base == 0 && expo == 0)
            type resposta = 0;

        for (auto i = 0; i != expo; ++i)
        {

        }
    }
};
template<typename type> class root;
template<typename type> class logarithm;

    /* other math operations */

template<typename type> class factorial
{
public: // data
    type num;
public: // constructors
    constexpr factorial() : num(static_cast<type>(1)) { }
    template<typename t>constexpr factorial(const t& num) : num(static_cast<type>(num)) { }
public: // functions
    template<typename result = type> nodiscard constexpr result resolve() noexcept
    {
        if (!(*this).valid()){ return static_cast<type>(1); }
        multiplication<type> temp;
        temp.factors.reserve(num);
        temp.factors.emplace_back(num);
        for (auto i = static_cast<type>(1); i != num; ++i)
        {
            
            temp.factors.emplace_back(subtraction<type>(num, i).resolve());
        }
        return temp.resolve<result>();
    }
    nodiscard constexpr inline bool valid() noexcept
    {
        if (is_negative(num) || is_null(num)) { return false; }
        return true;
    }
};
template<typename type> class absolute
{
public: // data
    type value;
public: // constructors
    constexpr absolute() : value(static_cast<type>(0)) {}
    template<typename t> constexpr absolute(const t& val) : value(static_cast<type>(val)) {}
public: // functions
    template<typename result = type> nodiscard constexpr result resolve() noexcept
    {
        if (is_null(value) || is_positive(value)) { return static_cast<result>(value); }
        return multiplication<type>(-1, value).resolve<result>();
    }
};

}

#undef nodiscard