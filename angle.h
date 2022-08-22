// 11/02/22

#pragma once
#include "type.h"
#include "validable.h"

namespace nimiat
{

    /* definitions */

    template<typename _type> class basic_angle;
    template<typename type = decimal> class radians;
    template<typename type = decimal> class degrees;
    template<typename _angle = radians<>> class cos;
    template<typename _angle = radians<>> class sin;
    template<typename _angle = radians<>> class tan;
    template<typename _angle = radians<>> class sec;
    template<typename _angle = radians<>> class csc;
    template<typename _angle = radians<>> class cot;
    template<typename _type = decimal> class acos;
    template<typename _type = decimal> class asin;
    template<typename _type = decimal> class atan;
    template<typename _type = decimal> class asec;
    template<typename _type = decimal> class acsc;
    template<typename _type = decimal> class acot;

    /* basic_angle */

    template<typename _type> class basic_angle
    {
    public: // type
        using type = _type;
    public: // data
        validable<type> value;
    protected: // constructors
        constexpr basic_angle() : value(validable<type>()) {}
        template<typename t> constexpr basic_angle(const t& val) : value(val) {}
    public: // functions
        virtual basic_angle& simplify() = 0;
    public: // conversion operators
        explicit operator validable<type>() { return value; }
        explicit operator type() { return value.reference(); }
    };

    /* basic_angle especializations */

    template<typename type = decimal> class radians : public basic_angle<type>
    {
    public: // constructors
        constexpr radians() : basic_angle() {}
        template<typename t> constexpr radians(const t& val) : basic_angle<type>(val) {}
    public: // function
        basic_angle<type>& simplify() override { return *this; }
        constexpr cos<radians<type>> cos() { nimiat::cos<radians<type>>(*this); }
        constexpr sin<radians<type>> sin() { nimiat::sin<radians<type>>(*this); }
        constexpr tan<radians<type>> tan() { nimiat::tan<radians<type>>(*this); }
        constexpr sec<radians<type>> sec() { nimiat::sec<radians<type>>(*this); }
        constexpr csc<radians<type>> csc() { nimiat::csc<radians<type>>(*this); }
        constexpr cot<radians<type>> cot() { nimiat::cot<radians<type>>(*this); }
    public: // conversion operators
        //explicit operator degrees<type>() {}
    };

    /* radians operators */

    template <typename _CharT, typename type> std::basic_ostream<_CharT>&
        operator<<(std::basic_ostream<_CharT>& _Os, const radians<type>& _Right) noexcept
    {
        return _Os << '<' << _Right.value << "rad" << '>';
    }
    template <typename _CharT, typename type> std::basic_istream<_CharT>&
        operator>>(std::basic_istream<_CharT>& _Is, const radians<type>& _Right)
    {
        // read obj from stream
        if (false /* no valid object of T found in stream */)
        {
            _Is.setstate(std::ios::failbit);
        }
        return _Is;
    }

    /* radians operators end */

    template<typename type = decimal> class degrees : public basic_angle<type>
    {
    public: // constructors
        constexpr degrees() : basic_angle<type>() {}
        template<typename t> constexpr degrees(const t& val) : basic_angle<type>(val) {}
    public: // function
        basic_angle<type>& simplify() override { return *this; }
        constexpr cos<radians<type>> cos() { nimiat::cos<degrees<type>>(*this); }
        constexpr sin<radians<type>> sin() { nimiat::sin<degrees<type>>(*this); }
        constexpr tan<radians<type>> tan() { nimiat::tan<degrees<type>>(*this); }
        constexpr sec<radians<type>> sec() { nimiat::sec<degrees<type>>(*this); }
        constexpr csc<radians<type>> csc() { nimiat::csc<degrees<type>>(*this); }
        constexpr cot<radians<type>> cot() { nimiat::cot<degrees<type>>(*this); }
    public: // operators
        explicit operator radians<type>() {}
    };

    /* degrees operators */

    template <typename _CharT, typename type> std::basic_ostream<_CharT>&
        operator<<(std::basic_ostream<_CharT>& _Os, const degrees<type>& _Right) noexcept
    {
        return _Os << '<' << _Right.value << "degrees" << '>';
    }
    template <typename _CharT, typename type> std::basic_istream<_CharT>&
        operator>>(std::basic_istream<_CharT>& _Is, const degrees<type>& _Right)
    {
        // read obj from stream
        if (false /* no valid object of T found in stream */)
        {
            _Is.setstate(std::ios::failbit);
        }
        return _Is;
    }

    /* geometric functions classes */

    template<typename _angle = radians<>> class cos
    {
    public: // type
        using angle = _angle;
        using type = angle::_type;
    public: // data
        validable<angle> value;
    public: // constructors
        constexpr cos() : value(validable<angle>()) {}
        template<typename t> constexpr cos(const t& val) : value(val) {}
    public: // functions
        template<typename result = type> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
    template<typename _angle = radians<>> class sin
    {
    public: // type
        using angle = _angle;
        using type = angle::_type;
    public: // data
        validable<angle> value;
    public: // constructors
        constexpr sin() : value(validable<angle>()) {}
        template<typename t> constexpr sin(const t& val) : value(val) {}
    public: // functions
        template<typename result = type> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
    template<typename _angle = radians<>> class tan
    {
    public: // type
        using angle = _angle;
        using type = angle::_type;
    public: // data
        validable<angle> value;
    public: // constructors
        constexpr tan() : value(validable<angle>()) {}
        template<typename t> constexpr tan(const t& val) : value(val) {}
    public: // functions
        template<typename result = type> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
    template<typename _angle = radians<>> class sec
    {
    public: // type
        using angle = _angle;
        using type = angle::_type;
    public: // data
        validable<angle> value;
    public: // constructors
        constexpr sec() : value(validable<angle>()) {}
        template<typename t> constexpr sec(const t& val) : value(val) {}
    public: // functions
        template<typename result = type> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
    template<typename _angle = radians<>> class csc
    {
    public: // type
        using angle = _angle;
        using type = angle::_type;
    public: // data
        validable<angle> value;
    public: // constructors
        constexpr csc() : value(validable<angle>()) {}
        template<typename t> constexpr csc(const t& val) : value(val) {}
    public: // functions
        template<typename result = type> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
    template<typename _angle = radians<>> class cot
    {
    public: // type
        using angle = _angle;
        using type = angle::_type;
    public: // data
        validable<angle> value;
    public: // constructors
        constexpr cot() : value(validable<angle>()) {}
        template<typename t> constexpr cot(const t& val) : value(val) {}
    public: // functions
        template<typename result = type> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };

    /* inverses geometric functions classes  */

    template<typename _type = decimal> class acos
    {
    public: // type
        using type = _type;
    public: // data
        validable<type> value;
    public: // constructors
        constexpr acos() : value(validable<type>()) {}
        template<typename t> constexpr acos(const t& val) : value(val) {}
    public: // functions
        template<typename result = radians<type>> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
    template<typename _type = decimal> class asin
    {
    public: // type
        using type = _type;
    public: // data
        validable<type> value;
    public: // constructors
        constexpr asin() : value(validable<type>()) {}
        template<typename t> constexpr asin(const t& val) : value(val) {}
    public: // functions
        template<typename result = radians<type>> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
    template<typename _type = decimal> class atan
    {
    public: // type
        using type = _type;
    public: // data
        validable<type> value;
    public: // constructors
        constexpr atan() : value(validable<type>()) {}
        template<typename t> constexpr atan(const t& val) : value(val) {}
    public: // functions
        template<typename result = radians<type>> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
    template<typename _type = decimal> class asec
    {
    public: // type
        using type = _type;
    public: // data
        validable<type> value;
    public: // constructors
        constexpr asec() : value(validable<type>()) {}
        template<typename t> constexpr asec(const t& val) : value(val) {}
    public: // functions
        template<typename result = radians<type>> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
    template<typename _type = decimal> class acsc
    {
    public: // type
        using type = _type;
    public: // data
        validable<type> value;
    public: // constructors
        constexpr acsc() : value(validable<type>()) {}
        template<typename t> constexpr acsc(const t& val) : value(val) {}
    public: // functions
        template<typename result = radians<type>> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
    template<typename _type = decimal> class acot
    {
    public: // type
        using type = _type;
    public: // data
        validable<type> value;
    public: // constructors
        constexpr acot() : value(validable<type>()) {}
        template<typename t> constexpr acot(const t& val) : value(val) {}
    public: // functions
        template<typename result = radians<type>> nodiscard constexpr result resolve() noexcept
        {
            return  result(0);
        }
    };
}

#undef nodiscard 