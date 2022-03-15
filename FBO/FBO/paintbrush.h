#ifndef PAINTBRUSH_H
#define PAINTBRUSH_H


#include "brush.h"
#include "brushmultiple.h"
#include "perlinds.h"

#include <stdlib.h>
class PaintBrush
{
public:
    PaintBrush(int rayon);
    ~PaintBrush();
    float getValue(int x, int y);
    float* getBrush();
    int getRayon();
    void init_risize_brush(int rayon);
private:
    int linear(int x, int y, int width);

    float* tab = nullptr;
    float* tab_resize = nullptr;
    int m_rayon = 0;
    int m_diametre = 0;
    int m_rayon_resize = 0;
};



#endif // PAINTBRUSH_H
