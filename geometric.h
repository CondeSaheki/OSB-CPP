// 11/02/22

#pragma once
#include "math.h"
#include "validable.h"
#include "angle.h"
#include <array>

namespace nimiat
{

    /* definitions */

    template<typename _type = integer, natural _dimensions = 2> class point;
    template<typename _type = point<>> class distance;
    template<typename _type = point<>> class vector;
    template<typename _type = point<>> class versor;
    template<typename _type = vector<>> class scalar_product;
    template<typename _type = vector<>> class vectorial_product;
    template<typename _type = point<>> class line;
    template<typename _type = point<>> class segment;
    template<typename _type = point<>> class form;

    /* point */

    template<typename _type = integer, natural _dimensions = 2> class point
    {
    public: // type
        using type = _type;
        inline static const natural dimensions = _dimensions;
    public: // data
        validable<std::array<type, dimensions>> coordinates;
    public: // constructor
        constexpr point() : coordinates(validable<std::array<type, dimensions>>()) {}
        constexpr point(const std::array<type, dimensions>& data) : coordinates(data) {}
    };

}

#undef nodiscard