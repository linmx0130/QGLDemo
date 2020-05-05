#ifndef PAINTINGWIDGET_H
#define PAINTINGWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QElapsedTimer>
#include <QKeyEvent>

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
    void keyPressEvent(QKeyEvent *keyEvent);
private:
    QOpenGLBuffer *m_vbo, *m_cbo, *m_uvbo;
    QOpenGLVertexArrayObject *m_vao;
    QOpenGLShaderProgram *m_shader;
    QOpenGLTexture *m_texture;
    QElapsedTimer *m_timer;
    float aspectRatio;
    GLfloat colorBuffer[4 * 3 *3];
    GLfloat vertexData[4 * 3 * 3];
    GLfloat uvData[4 * 3 * 2];
    QVector3D camera_pos;
};

#endif // PAINTINGWIDGET_H
