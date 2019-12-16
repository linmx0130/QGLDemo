#include "paintingwidget.h"

static const char* VERTEX_SHADER_CODE =
        "#version 330 \n"
        "layout(location = 0) in vec3 posVertex;\n"
        "layout(location = 1) in vec3 colVertex;\n"
        "out vec4 cols;\n"
        "void main() {\n"
        "  gl_Position = vec4(posVertex, 1.0f);\n"
        "  cols = vec4(colVertex, 1.0f);"
        "}\n";

static const char* FRAGMENT_SHADER_CODE =
        "#version 330\n"
        "in vec4 cols;\n"
        "out vec4 fragColor;\n"
        "void main() {\n"
        "  fragColor = cols;\n"
        "}\n";

PaintingWidget::PaintingWidget(QWidget* parent):
    QOpenGLWidget (parent), m_vbo(nullptr), m_vao(nullptr), m_shader(nullptr){
    const GLfloat VERTEX_INIT_DATA[] = {
           -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
           0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
           -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f
       };
    memcpy(this->vertexData, VERTEX_INIT_DATA, sizeof(this->vertexData));
    memset(this->colorBuffer, 0, sizeof(this->colorBuffer));
    colorBuffer[0] = 1.0f;
}
PaintingWidget::~PaintingWidget(){

}

void PaintingWidget::setColor(GLfloat r, GLfloat g, GLfloat b)
{
    colorBuffer[0] = r;
    colorBuffer[1] = g;
    colorBuffer[2] = b;
    fillColorBuffer();
    update();
}

void PaintingWidget::initializeGL()
{
    QOpenGLFunctions *f = this->context()->functions();
    m_shader = new QOpenGLShaderProgram();
    m_shader->addShaderFromSourceCode(QOpenGLShader::Vertex, VERTEX_SHADER_CODE);
    m_shader->addShaderFromSourceCode(QOpenGLShader::Fragment, FRAGMENT_SHADER_CODE);
    if (m_shader->link()) {
        qDebug("Shaders link success.");
    } else {
        qDebug("Shaders link failed!");
    }
    // 初始化VAO
    m_vao = new QOpenGLVertexArrayObject();
    m_vbo = new QOpenGLBuffer(QOpenGLBuffer::Type::VertexBuffer);
    m_vao->create();
    m_vao->bind();
    m_vbo->create();
    m_vbo->bind();
    m_vbo->allocate(this->vertexData, 3 * 6 * sizeof(GLfloat));
    f->glEnableVertexAttribArray(0);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), 0);
    f->glEnableVertexAttribArray(1);
    f->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat),
                             (void*)(3 * sizeof(GLfloat)));
    m_vbo->release();
    m_vao->release();
}

void PaintingWidget::paintGL()
{
    QOpenGLFunctions *f = this->context()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    f->glClearColor(0.0f, 0.2f, 0.0f, 1.0f);
    m_vao->bind();
    m_shader->bind();
    f->glDrawArrays(GL_TRIANGLES, 0, 3);
    m_shader->release();
    m_vao->release();
}

void PaintingWidget::resizeGL(int w, int h)
{
    Q_UNUSED(w);
    Q_UNUSED(h);
}

void PaintingWidget::fillColorBuffer()
{
    for (int i=0;i<3;++i) {
        memcpy(&this->vertexData[i*6 + 3], this->colorBuffer, 3 * sizeof(GLfloat));
    }
    m_vbo->bind();
    m_vbo->write(0, this->vertexData, 3*6*sizeof(GLfloat));
    m_vbo->release();
}

