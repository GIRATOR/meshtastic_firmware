//  GUI localisation by defining string literals in separate files
//  DO NOT translate radio preset and device role names, yet it causes issues

#ifdef GUI_UA
    #include "lang_ua.h"
#else
    #include "lang_en.h"
#endif