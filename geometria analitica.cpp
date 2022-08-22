#include "type.h"
#include "io.h"
#include "lyrics.h"
/*

#include "validable.h"
#include "angle.h"
#include "math.h"
#include "geometric.h"
#include "colors.h"
#include "osu_file.h"
#include "time_stamp.h"
#include "storyboarding.h"
#include "storyboarding_types.h"

#include "string_tools.h"

*/

// nodiscard 
#ifndef nodiscard
#ifndef __has_cpp_attribute
#define nodiscard
#elif __has_cpp_attribute(nodiscard) >= 201603L
#define nodiscard [[nodiscard]]
#else
#define nodiscard
#endif
#endif

int main()
{
    using namespace nimiat;
    namespace sfs = std::filesystem;
    
    string sus = io::inputf<character>(sfs::path(L"C:\\Users\\anonimo\\Desktop\\Various_Artists_-_Anime_2020_Mix_Net0.osb"));

    //auto sus2 = sub::inputf_str<character_w>(sus);

}

#undef nodiscard
