#include <iostream>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "Screen.h"
#include "Input.h"
#include "glad.h"
#include "Shader.h"

#include "Camera.h"
#include "Quad.h"

bool isAppRunning = true;

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

    Quad quad;
    Camera camera;
    camera.Set3DView();
    // if(!Shader::Instance()->SendUniformData("time", 20))
    // {

    // }

    while(isAppRunning)
    {
        Screen::Instance()->ClearScreen();
        Input::Instance()->Update();

        isAppRunning = !Input::Instance()->IsXClicked();

        if(Input::Instance()->IsLeftButtonClicked())
        {
            std::cout << "Left mouse button clicked" << std::endl;
        }

        int mouseX = Input::Instance()->GetMousePositionX();
        int mouseY = Input::Instance()->GetMousePositionY();

        //std::cout << "Mouse position : " << mouseMotionX << ", " << mouseMotionY << std::endl;

        camera.Update();
        quad.Update();
        quad.Render();
        Screen::Instance()->Present();
    }


    Shader::Instance()->DetachShaders();
    Shader::Instance()->DestroyShaders();
    Shader::Instance()->DestroyProgram();
    Screen::Instance()->Shutdown();

    return 0;
}
