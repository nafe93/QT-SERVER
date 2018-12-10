#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>

class Scene : public QOpenGLWidget
{
public:
    Scene( QWidget *parent = 0);
    ~Scene();

    void initializeGL();
    void paintGL();
    void resize(int w, int h);
};

#endif // SCENE_H
