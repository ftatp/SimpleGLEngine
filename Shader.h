#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <string>
#include "glad.h"

class Shader
{
public:
    enum class ShaderType{ VERTEX_SHADER, FRAGMENT_SHADER };

public: 
    static Shader* Instance();

public: 
    GLuint GetShaderProgramID();

    bool CreateProgram();
    bool CreateShaders();

    bool CompileShaders(const std::string& filename, ShaderType shaderType);
    void AttachShaders();
    bool LinkProgram();

    void DetachShaders();
    void DestroyShaders();
    void DestroyProgram();

    bool SendUniformData(const std::string& uniformName, GLint data);
    bool SendUniformData(const std::string& uniformName, GLuint data);
    bool SendUniformData(const std::string& uniformName, GLfloat data);
    bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y);
    bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z);
    bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    bool SendUniformData(const std::string& uniformName, const glm::mat4& data);

private:
    Shader();
    Shader(const Shader&);
    Shader& operator=(const Shader&);

private:
    bool IsUniformLocationFound(std::string uniformName, GLint* ID);

private:
    GLuint m_shaderProgramID;
    GLuint m_vertexShaderID;
    GLuint m_fragmentShaderID;
};

#endif
