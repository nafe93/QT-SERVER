#ifndef TRAINGLE_H
#define TRAINGLE_H

#include <vector>

class Traingle
{
public:
    Traingle();

    void initVertices();
    void initColors();

    std::vector<float>m_vertices;
    std::vector<float>m_colors;
};

#endif // TRAINGLE_H
