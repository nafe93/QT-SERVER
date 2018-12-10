#include "scene.h"

Scene::Scene(QWidget *parent):
    QOpenGLWidget(parent)
{

}
Scene::~Scene()
{

}

void Scene::initializeGL()
{
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f); //Задаю цвет
}
void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);         //Цвет поумолчанию
}
void Scene::resize(int w, int h)
{
    glViewport(0,0,w,h);
}
