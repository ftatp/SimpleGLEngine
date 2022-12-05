#include "Buffer.h"
#include "Shader.h"

Buffer::Buffer()
{
    m_VAO = 0;
    m_vertexVBO = 0;
    m_colorVBO = 0;
    m_textureVBO = 0;
    m_totalVertices = 0;
}

void Buffer::CreateBuffer(GLuint totalVertices)
{
    glGenBuffers(1, &m_vertexVBO);
    glGenBuffers(1, &m_colorVBO);
    glGenBuffers(1, &m_textureVBO);
    glGenVertexArrays(1, &m_VAO);
    m_totalVertices = totalVertices;
}

void Buffer::FillVBO(VBOType vboType, GLfloat* data, GLsizeiptr bufferSize, FillType fillType)
{
    glBindVertexArray(m_VAO); 

    // Bind generated buffer with graphic card's buffer binding point GL_ARRAY_BUFFER.
    if(vboType == VERTEX_BUFFER)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexVBO);
    }
    else if(vboType == COLOR_BUFFER)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_colorVBO);
    }
    else
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_textureVBO);
    }
    
    // Set the graphic card's buffer binding point GL_ARRAY_BUFFER with data (pointer).
    glBufferData(GL_ARRAY_BUFFER, bufferSize, data, fillType);
    glBindVertexArray(0);
}

void Buffer::LinkBuffer(const std::string& attribute, VBOType vboType, ComponentType componentType, DataType dataType)
{
    GLuint shaderProgramID = Shader::Instance()->GetShaderProgramID();

    GLint ID = glGetAttribLocation(shaderProgramID, attribute.c_str());
    
    glBindVertexArray(m_VAO); 
    //Bind generated buffer with graphic card's buffer binding point GL_ARRAY_BUFFER.
    if(vboType == VERTEX_BUFFER)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexVBO);
    }
    else if(vboType == COLOR_BUFFER)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_colorVBO);
    }
    else
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_textureVBO);
    }

    // Link the shader attribute with GL_ARRAY_BUFFER binded target and define the structure of attribute
    glVertexAttribPointer(ID, componentType, GL_FLOAT, GL_FALSE, 0, nullptr);
    // Enable the attribute
    glEnableVertexAttribArray(ID);
    glBindVertexArray(0); 
}

void Buffer::CreateAndLinkVBO(VBOType vboType, GLfloat* data, GLsizeiptr bufferSize, FillType fillType,
                            const std::string& attribute, ComponentType componentType, DataType dataType)
{

    GLuint shaderProgramID = Shader::Instance()->GetShaderProgramID();
    GLint ID = glGetAttribLocation(shaderProgramID, attribute.c_str());

    glBindVertexArray(m_VAO); 

    // Bind generated buffer with graphic card's buffer binding point GL_ARRAY_BUFFER.
    if(vboType == VERTEX_BUFFER)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexVBO);
    }
    else if(vboType == COLOR_BUFFER)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_colorVBO);
    }
    else
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_textureVBO);
    }

    // Set the graphic card's buffer binding point GL_ARRAY_BUFFER with data (pointer).
    glBufferData(GL_ARRAY_BUFFER, bufferSize, data, fillType);

    // Link the shader attribute with GL_ARRAY_BUFFER binded target and define the structure of attribute
    glVertexAttribPointer(ID, componentType, GL_FLOAT, GL_FALSE, 0, nullptr);
    // Enable the attribute
    glEnableVertexAttribArray(ID);
    glBindVertexArray(0);
}

void Buffer::Render(DrawType drawType)
{
    glBindVertexArray(m_VAO);
    glDrawArrays(drawType, 0, m_totalVertices);
    glBindVertexArray(0);
}

void Buffer::DestroyBuffer()
{
    glDeleteBuffers(1, &m_vertexVBO);
    glDeleteBuffers(1, &m_colorVBO);
    glDeleteBuffers(1, &m_textureVBO);
    glDeleteVertexArrays(1, &m_VAO);
}
