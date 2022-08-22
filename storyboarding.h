#pragma once
#include <chrono>
#include <format>
#include <filesystem>
#include "type.h"

namespace nimiat::storyboard
{
  

    enum class easing2
    {
        Linear,
        Easing_Out,
        Easing_In,
        Quad_In,
        Quad_Out,
        Quad_In_Out,
        Cubic_In,
        Cubic_Out,
        Cubic_In_Out,
        Quart_In,
        Quart_Out,
        Quart_In_Out,
        Quint_In,
        Quint_Out,
        Quint_In_Out,
        Sine_In,
        Sine_Out,
        Sine_In_Out,
        Expo_In,
        Expo_Out,
        Expo_In_Out,
        Circ_In,
        Circ_Out,
        Circ_In_Out,
        Elastic_In,
        Elastic_Out,
        ElasticHalf_Out,
        ElasticQuarter_Out,
        Elastic_In_Out,
        Back_In,
        Back_Out,
        Back_In_Out,
        Bounce_In,
        Bounce_Out,
        Bounce_In_Out
    };

    enum class layer
    {
        Background,
        Fail,
        Pass,
        Foreground
    };

    enum class origin
    {
        TopLeft,
        Centre,
        CentreLeft,
        TopRight,
        BottomCentre,
        TopCentre,
        CentreRight = 7,
        BottomLeft,
        BottomRight,
    };

    enum class looptype
    {
        LoopForever,
        LoopOnce
    };

    struct coordinates
    {
        coordinates() : x(0), y(0) { }
        coordinates(const int& X, const int& Y) :x(x), y(y) { }
        int x;
        int y;
    };

    struct rgb
    {
        rgb() : red(0), green(0), blue(0) { }
        rgb(const int& r, const int& g, const int& b) : red(r), green(g), blue(b) { }
        int red;
        int green;
        int blue;
    };

    inline const rgb white(255, 255, 255);
    inline const rgb black(0, 0, 0);
    inline const rgb grey(128, 128, 128);

    inline const rgb red(255, 0, 0);
    inline const rgb green(0, 255, 0);
    inline const rgb blue(0, 0, 255);

    inline const rgb cyan(0, 255, 255);
    inline const rgb magenta(255, 0, 255);
    inline const rgb yellow(255, 255, 0);


    //F - fade()  _F,(easing),(starttime),(endtime),(start_opacity),(end_opacity)
    void fade(easing Easing, sch::milliseconds start, sch::milliseconds end, double start_opacity, double end_opacity) {}

    //M - move() M,(easing),(starttime),(endtime),(start_x),(start_y),(end_x),(end_y)
    void move(easing Easing, sch::milliseconds start, sch::milliseconds end, coordinates start_coordinates, coordinates end_coordinates) {}
    void moveX(easing Easing, sch::milliseconds start, sch::milliseconds end, coordinates start_coordinates, coordinates end_coordinates) {}
    void moveY(easing Easing, sch::milliseconds start, sch::milliseconds end, coordinates start_coordinates, coordinates end_coordinates) {}

    //S - scale() _S,<easing>,<starttime>,<endtime>,<start_scale>,<end_scale>
    void scale(easing Easing, sch::milliseconds start, sch::milliseconds end, double start_scale, double end_scale) {}

    //V - vector scale(width and height separately) _V,(easing),(starttime),(endtime),(start_scale_x),(start_scale_y),(end_scale_x),(end_scale_y
    void vector_scale(easing Easing, sch::milliseconds start, sch::milliseconds end, double start_scale_x, double end_scale_x, double start_scale_y, double end_scale_y) {}

    //R - rotate() _R,<easing>,<starttime>,<endtime>,<start_rotate>,<end_rotate>
    void rotate(easing Easing, sch::milliseconds start, sch::milliseconds end, double start_rad, double end_rad) {}

    //C - colour() _C,(easing),(starttime),(endtime),(start_r),(start_g),(start_b),(end_r),(end_g),(end_b)
    void colour(easing Easing, sch::milliseconds start, sch::milliseconds end, rgb start_rgb, rgb end_rgb) {}

    //P - H, V, A
    void flip_horizontally(easing Easing, sch::milliseconds start, sch::milliseconds end) {}
    void flip_vertically(easing Easing, sch::milliseconds start, sch::milliseconds end) {}
    void additive_color(easing Easing, sch::milliseconds start, sch::milliseconds end) {}

    //L - loop() (starttime),(loopcount)
    void loop(sch::milliseconds start, unsigned long long loopcount) {}

    //T - Event - triggered loop _T,(triggerType),(starttime),(endtime)
    struct triggerType
    {
        //HitSound[SampleSet][AdditionsSampleSet][Addition][CustomSampleSet]
        //Passing
        //Failing

        void hitsounds(hitsounds_SampleSet SampleSet, hitsounds_SampleSet AdditionsSampleSet, hitsounds_Addition Addition, unsigned int CustomSampleSet) {}

    };

    void triggered(triggerType type, sch::milliseconds start, sch::milliseconds end) {}

    enum class hitsounds_SampleSet
    {
        All,
        Normal,
        Soft,
        Drum
    };
    enum class hitsounds_Addition
    {
        Whistle,
        Finish,
        Clap
    };

    //Sprite, (layer), (origin), "(filepath)", (x), (y)
    void Sprite(layer Layer, origin Origin, sfs::path Path, coordinates Coordinates) {}

    //Animation, (layer), (origin), "(filepath)", (x), (y), (frameCount), (frameDelay), (looptype)
    void Animation(layer Layer, origin Origin, sfs::path Path, coordinates Coordinates, long long frameCount, sch::milliseconds frameDelay, looptype Looptype) {}



    // audio -> Sample, <time>, <layer_num>, "<filepath>", <volume>
    void Sample(sch::milliseconds start, layer layer, sfs::path Path, unsigned int volume) {}




    class storyboard_obj
    {
    public: // constructors
        storyboard_obj() = default;
    private:
        class basic_commands
        {
        public:
            virtual std::string str() = 0;
            basic_commands(easing Easing, sch::milliseconds start, sch::milliseconds end) : _easing(Easing), _start(start), _end(end) {}
        protected:
            const easing _easing;
            const sch::milliseconds _start;
            const sch::milliseconds _end;
        };
        //fade
        class fade : public basic_commands
        {
        public: // constructor
            fade(const easing& Easing, const sch::milliseconds& start, const sch::milliseconds& end, const double& start_opacity, const double& end_opacity) :
                basic_commands(Easing, start, end), _start_opacity(start_opacity), _end_opacity(end_opacity) { }
        protected: // data
            double _start_opacity;
            double _end_opacity;
        public: // srt
            std::string str() override //_F, (easing), (starttime), (endtime), (start_opacity), (end_opacity)
            {
                return std::format("F, {}, {}, {}, {}", static_cast<int>(_easing), _start.count(), _end.count(), _start_opacity, _end_opacity);
            }
        };

    private:
        std::vector<basic_commands> events;

    public:
        std::string str()
        {
            if (!events.empty())
            {
                std::string temp("");
                for (auto it = events.begin(); it != events.end(); ++it)
                {
                    temp += " " + (*it).str() + "\n";
                }
                return temp;
            }
            return std::string();
        }

        void add_fade()
        {
            fade a(easing::Sine_In, sch::milliseconds(0), sch::milliseconds(10000), 0, 1);
            events.emplace_back(a);
        }
    };


    class sprite : public storyboard_obj
    {
        sprite();
    };


}