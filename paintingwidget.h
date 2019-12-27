#ifndef PAINTINGWIDGET_H
#define PAINTINGWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

class PaintingWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    PaintingWidget(QWidget *partent);
    ~PaintingWidget();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    QOpenGLBuffer *m_vbo, *m_cbo;
    QOpenGLVertexArrayObject *m_vao;
    QOpenGLShaderProgram *m_shader;
    float aspectRatio;
    GLfloat colorBuffer[4 * 3 *3];
    GLfloat vertexData[4 * 3 * 3];
};

#endif // PAINTINGWIDGET_H
