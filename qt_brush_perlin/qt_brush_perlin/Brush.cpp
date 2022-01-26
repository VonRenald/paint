#include "Brush.h"

Brush::Brush(int rayon)
{
	m_rayon = rayon;
	int diametre = 2 * rayon + 1;
	brush = (float*)malloc(sizeof(float) * diametre * diametre);
    BrushDecCercle(rayon,brush);
}
Brush::~Brush()
{
	free(brush);
}
float Brush::distE(QPoint p1, QPoint p2)
{
	return sqrt((p1.x() - p2.x()) * (p1.x() - p2.x()) + (p1.y() - p2.y()) * (p1.y() - p2.y()));
}
float Brush::f(float x) 
{
    return x * x;
}
void Brush::BrushDecCercle(int rayon, float* tab)
{
    int diametre = 2 * rayon + 1;
    float seuil = distE(QPoint(rayon, rayon), QPoint(rayon, 0)) +0.25f;

    for (int j = 0; j < diametre; j++)
    {
        for (int i = 0; i < diametre; i++)
        {
            float normal =  1 - distE(QPoint(rayon, rayon), QPoint(i, j)) / seuil;
            normal = (normal < 0) ? 0 : normal;
            normal = f(normal);
            tab[i + j * diametre] = normal;
        }

    }
    if (rayon == 0)
    {
        tab[0] = 1.0f;
    }
}
int Brush::linear(int x, int y, int w)
{
    return (x + y * w);
}
float Brush::getValue(int x, int y)
{
    int diametre = 2 * m_rayon + 1;
    if (x < 0 || x >= diametre || y < 0 || y >= diametre)
        return -1.0f;
    return brush[linear(x, y, diametre)];
}
float* Brush::getBrush()
{
    return brush;
}
int Brush::getRayon()
{
    return m_rayon;
}