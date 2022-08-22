#pragma once
#include "type.h"

class easing
{
public: // type
    using string_type = nimiat::string;
    using number_type = nimiat::natural;
private: // type
    class basic_easing
    {
    public: // data
        string_type name;
        number_type id;
    public: // constructor
        constexpr basic_easing(const string_type& Name, const number_type& Id) : name(Name), id(Id) {}
    };
public: // static data
    static inline const basic_easing linear = basic_easing("Linear", 1);
    static inline const basic_easing Easing_Out = basic_easing("Easing_Out", 1);
    static inline const basic_easing Easing_In = basic_easing("Easing_In", 1);
    static inline const basic_easing Quad_In = basic_easing("Quad_In", 1);
    static inline const basic_easing Quad_Out = basic_easing("Quad_Out", 1);
    static inline const basic_easing Quad_In_Out = basic_easing("Quad_In_Out", 1);
    static inline const basic_easing Cubic_In = basic_easing("Cubic_In", 1);
    static inline const basic_easing Cubic_Out = basic_easing("Cubic_Out", 1);
    static inline const basic_easing Cubic_In_Out = basic_easing("Cubic_In_Out", 1);
    static inline const basic_easing Quart_In = basic_easing("Quart_In", 1);
    static inline const basic_easing Quart_Out = basic_easing("Quart_Out", 1);
    static inline const basic_easing Quart_In_Out = basic_easing("Quart_In_Out", 1);
    static inline const basic_easing Quint_In = basic_easing("Quint_In", 1);
    static inline const basic_easing Quint_Out = basic_easing("Quint_Out", 1);
    static inline const basic_easing Quint_In_Out = basic_easing("Quint_In_Out", 1);
    static inline const basic_easing Sine_In = basic_easing("Sine_In", 1);
    static inline const basic_easing Sine_Out = basic_easing("Sine_Out", 1);
    static inline const basic_easing Sine_In_Out = basic_easing("Sine_In_Out", 1);
    static inline const basic_easing Expo_In = basic_easing("Expo_In", 1);
    static inline const basic_easing Expo_Out = basic_easing("Expo_Out", 1);
    static inline const basic_easing Expo_In_Out = basic_easing("Expo_In_Out", 1);
    static inline const basic_easing Circ_In = basic_easing("Circ_In", 1);
    static inline const basic_easing Circ_Out = basic_easing("Circ_Out", 1);
    static inline const basic_easing Circ_In_Out = basic_easing("Circ_In_Out", 1);
    static inline const basic_easing Elastic_In = basic_easing("Elastic_In", 1);
    static inline const basic_easing Elastic_Out = basic_easing("Elastic_Out", 1);
    static inline const basic_easing ElasticHalf_Out = basic_easing("ElasticHalf_Out", 1);
    static inline const basic_easing ElasticQuarter_Out = basic_easing("ElasticQuarter_Out", 1);
    static inline const basic_easing Elastic_In_Out = basic_easing("Elastic_In_Out", 1);
    static inline const basic_easing Back_In = basic_easing("Back_In", 1);
    static inline const basic_easing Back_Out = basic_easing("Back_Out", 1);
    static inline const basic_easing Back_In_Out = basic_easing("Back_In_Out", 1);
    static inline const basic_easing Bounce_In = basic_easing("Bounce_In", 1);
    static inline const basic_easing Bounce_Out = basic_easing("Bounce_Out", 1);
    static inline const basic_easing Bounce_In_Out = basic_easing("Bounce_In_Out", 1);
private: // constructor
    easing() = delete;
};

