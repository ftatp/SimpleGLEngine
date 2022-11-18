#include <fstream>
#include <string>
#include "Shader.h"
#include <iostream>

Shader* Shader::Instance()
{
    static Shader* shaderObject = new Shader();
    return shaderObject;
}

bool Shader::CreateProgram()
{
    m_shaderProgramID = glCreateProgram();
    if(m_shaderProgramID == 0)
    {
        std::cout << "Error creating shader program." << std::endl;
        return false;
    }

    return true;
}

bool Shader::CreateShaders()
{
    m_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    if(m_vertexShaderID == 0)
    {
        std::cout << "Error creating vertex shader object." << std::endl;
        return false;
    }
    
    m_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    if(m_fragmentShaderID == 0)
    {
        std::cout << "Error creating fragment shader object." << std::endl;
        return false;
    }

    return true;
}

bool Shader::CompileShaders(const std::string& filename, ShaderType shaderType)
{
    std::string sourceCode;
    std::string text;
    std::fstream file;
    GLuint shaderID;

    shaderID = (shaderType == ShaderType::VERTEX_SHADER) ? m_vertexShaderID : m_fragmentShaderID;

    file.open(filename);
    if(!file)
    {
        std::cout << "Error reading shader file : " << filename << std::endl;
        return false;
    }

    while(!file.eof())
    {
        std::getline(file, text);
        sourceCode += text + "\n";
    }

    file.close();

    const GLchar* finalSourceCode = reinterpret_cast<const GLchar*>(sourceCode.c_str());
    glShaderSource(shaderID, 1, &finalSourceCode, nullptr);

    glCompileShader(shaderID);

    GLint errorCode;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &errorCode);
    if(errorCode == GL_TRUE)
    {
        std::cout << "Shader compilation successful" << std::endl;
    }
    else
    {
        GLchar errorMessage[1000];
        GLsizei bufferSize = 1000;
        
        glGetShaderInfoLog(shaderID, bufferSize, &bufferSize, errorMessage);
        std::cout << errorMessage << std::endl;
    }

    return true;
}

void Shader::AttachShaders()
{
    glAttachShader(m_shaderProgramID, m_vertexShaderID);
    glAttachShader(m_shaderProgramID, m_fragmentShaderID);
    
    return;
}

bool Shader::LinkProgram()
{
    glLinkProgram(m_shaderProgramID);
    glUseProgram(m_shaderProgramID);

    GLint errorCode;
    glGetProgramiv(m_shaderProgramID, GL_LINK_STATUS, &errorCode);
    if(errorCode == GL_TRUE)
    {
        std::cout << "Shader linking successful" << std::endl;
    }
    else
    {
        GLchar errorMessage[1000];
        GLsizei bufferSize = 1000;
        
        glGetShaderInfoLog(m_shaderProgramID, bufferSize, &bufferSize, errorMessage);
        std::cout << errorMessage << std::endl;
    }

    return false;
}

void Shader::DetachShaders()
{
    glDetachShader(m_shaderProgramID, m_vertexShaderID);
    glDetachShader(m_shaderProgramID, m_fragmentShaderID);
    
    return;
}

void Shader::DestroyShaders()
{
    glDeleteShader(m_vertexShaderID); 
    glDeleteShader(m_fragmentShaderID); 
    
    return;
}

void Shader::DestroyProgram()
{
    glDeleteProgram(m_shaderProgramID);

    return;
}

bool Shader::SendUniformData(const std::string& uniformName, GLint data)
{
    GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());
    if(ID == -1)
    {
        std::cout << "Shader Variable " << uniformName << " not found or used." << std::endl;
        return false;
    }
    glUniform1i(ID, data);

    return true;
}
bool Shader::SendUniformData(const std::string& uniformName, GLuint data)
{
    GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());
    if(ID == -1)
    {
        std::cout << "Shader Variable " << uniformName << " not found or used." << std::endl;
        return false;
    }
    glUniform1ui(ID, data);

    return false;
}
bool Shader::SendUniformData(const std::string& uniformName, GLfloat data)
{
    GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());
    if(ID == -1)
    {
        std::cout << "Shader Variable " << uniformName << " not found or used." << std::endl;
        return false;
    }
    glUniform1f(ID, data);

    return false;
}
bool Shader::SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y)
{
    GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());
    if(ID == -1)
    {
        std::cout << "Shader Variable " << uniformName << " not found or used." << std::endl;
        return false;
    }
    glUniform2f(ID, x, y);

    return false;
}
bool Shader::SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z)
{
    GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());
    if(ID == -1)
    {
        std::cout << "Shader Variable " << uniformName << " not found or used." << std::endl;
        return false;
    }
    glUniform3f(ID, x, y, z);

    return false;
}
bool Shader::SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());
    if(ID == -1)
    {
        std::cout << "Shader Variable " << uniformName << " not found or used." << std::endl;
        return false;
    }
    glUniform4f(ID, x, y, z, w);

    return false;
}

Shader::Shader()
{
    m_shaderProgramID = 0;
    m_vertexShaderID = 0;
    m_fragmentShaderID = 0;
}
