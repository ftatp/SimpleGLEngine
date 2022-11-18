#include <iostream>
#include <SDL2/SDL.h>

#include "Screen.h"
#include "Input.h"
#include "glad.h"
#include "Shader.h"


bool isAppRunning = true;

GLfloat vertices[] = {
    -0.5f,  0.5f, 0.0f, // Left, Up
     0.5f,  0.5f, 0.0f, // Right, Up
    -0.5f, -0.5f, 0.0f, // Left, Down
    -0.5f, -0.5f, 0.0f, // Left, Down
     0.5f,  0.5f, 0.0f, // Right, Up
     0.5f, -0.5f, 0.0f // Right, Down
};

GLfloat colors[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 1.0f,
    0.0f, 1.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f
};

void MyDisplay(float xPos, float yPos){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(xPos - 0.5, yPos - 0.5, 0.0);    
        glVertex3f(xPos + 0.5, yPos - 0.5, 0.0);    
        glVertex3f(xPos + 0.5, yPos + 0.5, 0.0);    
        glVertex3f(xPos - 0.5, yPos + 0.5, 0.0); 
    glEnd();
    glFlush();  
}


int main(int agrc, char **argv)
{
//     glutInit(&agrc, argv);
// 
//     glutCreateWindow("OpenGl example");
//     glutDisplayFunc(MyDisplay);
//     glutMainLoop();
//     

    Screen::Instance()->Initialize();

    if(!Shader::Instance()->CreateProgram())
    {
        return 0;
    }

    if(!Shader::Instance()->CreateShaders())
    {
        return 0;
    }

    if(!Shader::Instance()->CompileShaders("Shaders/Main.vert", Shader::ShaderType::VERTEX_SHADER))
    {}
    if(!Shader::Instance()->CompileShaders("Shaders/Main.frag", Shader::ShaderType::FRAGMENT_SHADER))
    {}

    Shader::Instance()->AttachShaders();
    if(!Shader::Instance()->LinkProgram())
    {}

    float xPos = 0.0f;
    float yPos = 0.0f;

    // if(!Shader::Instance()->SendUniformData("time", 20))
    // {

    // }

    GLuint shaderProgramID = Shader::Instance()->GetShaderProgramID();
    GLint vertexID = glGetAttribLocation(shaderProgramID, "vertexIn");
    GLint colorID = glGetAttribLocation(shaderProgramID, "colorIn");

    GLuint vertexVBO;
    GLuint colorVBO;
    glGenBuffers(1, &vertexVBO);
    glGenBuffers(1, &colorVBO);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO); 

        // Bind generated buffer with graphic card's buffer binding point GL_ARRAY_BUFFER.
        glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
        // Set the graphic card's buffer binding point GL_ARRAY_BUFFER with data (pointer).
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        // Link the shader attribute with GL_ARRAY_BUFFER binded target and define the structure of attribute
        glVertexAttribPointer(vertexID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        // Enable the attribute
        glEnableVertexAttribArray(vertexID);

        glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
        glVertexAttribPointer(colorID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(colorID);

    glBindVertexArray(0);


    while(isAppRunning)
    {
        Screen::Instance()->ClearScreen();
        Input::Instance()->Update();


        isAppRunning = !Input::Instance()->IsXClicked();

        char keyPressed = Input::Instance()->GetKeyDown();
        
        // Direction keys
        if(keyPressed == 'a')
        {
            xPos -= 0.01f;
        }
        else if(keyPressed == 'd')
        {
            xPos += 0.01f;
        }        
        else if(keyPressed == 'w')
        {
            yPos += 0.01f;
        }        
        else if(keyPressed == 's')
        {
            yPos -= 0.01f;
        }
        
        
        if(Input::Instance()->IsLeftButtonClicked())
        {
            std::cout << "Left mouse button clicked" << std::endl;
        }

        int mouseX = Input::Instance()->GetMousePositionX();
        int mouseY = Input::Instance()->GetMousePositionY();

        //std::cout << "Mouse position : " << mouseX << ", " << mouseY << std::endl;

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);

        //MyDisplay(xPos, yPos);
        Screen::Instance()->Present();
    }

    glDeleteBuffers(1, &vertexVBO);
    glDeleteBuffers(1, &colorVBO);
    glDeleteVertexArrays(1, &VAO);

    glDisableVertexAttribArray(vertexID);
    glDisableVertexAttribArray(colorID);

    Shader::Instance()->DetachShaders();
    Shader::Instance()->DestroyShaders();
    Shader::Instance()->DestroyProgram();
    Screen::Instance()->Shutdown();

    return 0;
}
