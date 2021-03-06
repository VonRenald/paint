#include "GeometryEngine.h"

#include <QVector2D>
#include <QVector3D>

#include <QDebug>

struct VertexData
{
	QVector3D position;
	QVector2D texCoord;
};

GeometryEngine::GeometryEngine()
    : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();

    // Initializes cube geometry and transfers it to VBOs
    initCubeGeometry();
}
GeometryEngine::~GeometryEngine()
{
    arrayBuf.destroy();
    indexBuf.destroy();
}
void GeometryEngine::initCubeGeometry()
{
    //qInfo("-----------------------------------ok-----------------------------------");
    // For cube we would need only 8 vertices but we have to
    // duplicate vertex for each face because texture coordinate
    // is different.
    VertexData vertices[] = {
        // Vertex data for face 0
        {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(0.0f, 0.0f)},  // v0
        {QVector3D(1.0f, -1.0f,  1.0f), QVector2D(1.0f, 0.0f)}, // v1
        {QVector3D(-1.0f,  1.0f,  1.0f), QVector2D(0.0f, 1.0f)},  // v2
        {QVector3D(1.0f,  1.0f,  1.0f), QVector2D(1.0f, 1.0f)}, // v3

    };
    // Indices for drawing cube faces using triangle strips.
    // Triangle strips can be connected by duplicating indices
    // between the strips. If connecting strips have opposite
    // vertex order then last index of the first strip and first
    // index of the second strip needs to be duplicated. If
    // connecting strips have same vertex order then only last
    // index of the first strip needs to be duplicated.
    GLushort indices[] = {
         0,  1,  2,  3,  3     // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
    };

    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(vertices, 4 * sizeof(VertexData));

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(indices, 5 * sizeof(GLushort));
}

void GeometryEngine::drawCubeGeometry(QOpenGLShaderProgram* program)
{
    // Tell OpenGL which VBOs to use
    //qInfo("-----------------------------------ok5.6.1-----------------------------------");
    arrayBuf.bind();
    //qInfo("-----------------------------------ok5.6.1.0-----------------------------------");
    indexBuf.bind();
    //qInfo("-----------------------------------ok5.6.1.1-----------------------------------");
    // Offset for position
    quintptr offset = 0;
    //qInfo("-----------------------------------ok5.6.1.2-----------------------------------");
    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    //qInfo("-----------------------------------ok5.6.1.3-----------------------------------");
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));
    //qInfo("-----------------------------------ok5.6.2-----------------------------------");
    // Offset for texture coordinate
    offset += sizeof(QVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    int texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));
    //qInfo("-----------------------------------ok5.6.3-----------------------------------");
    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_SHORT, nullptr);
    //qInfo("-----------------------------------ok5.6.4-----------------------------------");
}