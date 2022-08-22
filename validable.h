// 11/02/22

#pragma once
#include "type.h"
#include <compare>


namespace nimiat
{
	template<typename _type = logical> class validable  // must be default construtible and have assing operator
	{
	public: // type
		using type = _type;
	private: // data
		logical _valid;
		type _data;
	public: // constructors
		constexpr validable() : _valid(false), _data(type()) {}
		template<typename t> constexpr validable(const t& val) : _valid(true), _data(static_cast<type>(val)) {}
		template<> constexpr validable(const _type& val) : _valid(true), _data(val) {}
	public: // functions
		nodiscard constexpr logical is_valid() noexcept { return _valid; }
		void invalidate() noexcept { _valid = false; }
		void validate() noexcept { _valid = true; }
		nodiscard constexpr const type& value() noexcept { return _data; }
		nodiscard constexpr type& reference() noexcept { return _data; }
		template<typename t> void set(const t& val) noexcept { _data = type(val); _valid = true; }
		template<> void set(const type& val) noexcept { _data = val; _valid = true; }
		void reset() { _data = type(); _valid = false; }
    public: // conversion operator
        operator type()
        {
            return _data;
        }
    public: // I and O operators
        template <typename _CharT, typename type>
            friend std::basic_ostream<_CharT>& operator<<(std::basic_ostream<_CharT>& _Os, const validable<type>& _Right) noexcept;
        template <typename _CharT, typename type>
            friend std::basic_istream<_CharT>& operator>>(std::basic_istream<_CharT>& _Is, const validable<type>& _Right);
    };

    /* operators */

    template <typename _CharT, typename type> std::basic_ostream<_CharT>& 
        operator<<(std::basic_ostream<_CharT>& _Os, const validable<type>& _Right) noexcept
    {
        return _Os << '<' << "valid: " << (_Right._valid ? "true" : "false") << " | data: " << _Right._data << '>';
    }
    template <typename _CharT, typename type> std::basic_istream<_CharT>& 
        operator>>(std::basic_istream<_CharT>& _Is, const validable<type>& _Right)
    {
        // read obj from stream
        if (false /* no valid object of T found in stream */)
        {
            _Is.setstate(std::ios::failbit);
        }
        return _Is;
    }
}

#undef nodiscard

/*
// basic operators
        nodiscard constexpr validable<type> operator+() const noexcept
        {
            return validable<type>(*this);
        }
        nodiscard constexpr validable<_type> operator-() const noexcept
        {
            return validable<type>(-_data);
        }
        constexpr validable<type>& operator++() noexcept
        {
            ++_data;
            return *this;
        }
        constexpr validable<type> operator++(int) noexcept
        {
            return validable<type>(_data++);
        }
        constexpr validable<type>& operator--() noexcept
        {
            --_data;
            return *this;
        }
        constexpr validable<type> operator--(int) noexcept
        {
            return validable<type>(_data--);
        }
        // aritimetic operators
        nodiscard constexpr validable<type> operator+(const type& _Right) const noexcept
        {
            return validable<type>(_data + _Right);
        }
        nodiscard constexpr validable<type> operator+(const validable<type>& _Right) const noexcept
        {
            return validable<type>(_data + _Right._data);
        }
        nodiscard constexpr validable<type> operator-(const type& _Right) const noexcept
        {
            return validable<type>(_data - _Right);
        }
        nodiscard constexpr validable<type> operator-(const validable<type>& _Right) const noexcept
        {
            return validable<type>(_data - _Right._data);
        }
        nodiscard constexpr validable<type> operator*(const type& _Right) const noexcept
        {
            return validable<type>(_data * _Right);
        }
        nodiscard constexpr validable<type> operator*(const validable<type>& _Right) const noexcept
        {
            return validable<type>(_data * _Right._data);
        }
        nodiscard constexpr validable<type> operator/(const type& _Right) const noexcept
        {
            return validable<type>(_data / _Right);
        }
        nodiscard constexpr validable<type> operator/(const validable<type>& _Right) const noexcept
        {
            return validable<type>(_data / _Right._data);
        }
        nodiscard constexpr validable<type> operator%(const type& _Right) const noexcept
        {
            return validable<type>(_data % _Right);
        }
        nodiscard constexpr validable<type> operator%(const validable<type>& _Right) const noexcept
        {
            return validable<type>(_data % _Right._data);
        }
        nodiscard constexpr validable<type>& operator+=(const type& _Right) noexcept
        {
            _data += _Right;
            return *this;
        }
        nodiscard constexpr validable<type>& operator+=(const validable<type>& _Right) noexcept
        {
            _data += _Right._data;
            return *this;
        }
        nodiscard constexpr validable<type>& operator-=(const type& _Right) noexcept
        {
            _data -= _Right;
            return *this;
        }
        nodiscard constexpr validable<type>& operator-=(const validable<type>& _Right) noexcept
        {
            _data -= _Right._data;
            return *this;
        }
        nodiscard constexpr validable<type>& operator*=(const type& _Right) noexcept
        {
            _data *= _Right;
            return *this;
        }
        nodiscard constexpr validable<type>& operator*=(const validable<type>& _Right) noexcept
        {
            _data *= _Right._data;
            return *this;
        }
        nodiscard constexpr validable<type>& operator/=(const type& _Right) noexcept
        {
            _data /= _Right;
            return *this;
        }
        nodiscard constexpr validable<type>& operator/=(const validable<type>& _Right) noexcept
        {
            _data /= _Right._data;
            return *this;
        }
        nodiscard constexpr validable<type>& operator%=(const type& _Right) noexcept
        {
            _data %= _Right;
            return *this;
        }
        nodiscard constexpr validable<type>& operator%=(const validable<type>& _Right) noexcept
        {
            _data %= _Right._data;
            return *this;
        }
         // comparison operator
        template<typename type>
            friend constexpr logical operator==(const validable<type>& _Left, const validable<type>& _Right) noexcept;
        template<typename type>
            friend constexpr std::strong_ordering operator<=>(const validable<type>& _Left, const validable<type>& _Right) noexcept;
            template<typename type> nodiscard constexpr std::strong_ordering
        operator<=>(const validable<type>& _Left, const validable<type>& _Right) noexcept
    {
        return _Left._data <=> _Right._data;
    }
    template<typename type> nodiscard constexpr logical
        operator==(const validable<type>& _Left, const validable<type>& _Right) noexcept
    {
        return _Left._data == _Right._data;
    }
*/