#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "glad.h"

class Shader
{
public:
    enum class ShaderType{ VERTEX_SHADER, FRAGMENT_SHADER };

public: 
    static Shader* Instance();

public: 
    bool CreateProgram();
    bool CreateShaders();

    bool CompileShaders(const std::string& filename, ShaderType shaderType);
    void AttachShaders();
    bool LinkProgram();

    void DetachShaders();
    void DestroyShaders();
    void DestroyProgram();

private:
    Shader();
    Shader(const Shader&);
    Shader& operator=(const Shader&);

private:
    GLuint m_shaderProgramID;
    GLuint m_vertexShaderID;
    GLuint m_fragmentShaderID;
};

#endif
