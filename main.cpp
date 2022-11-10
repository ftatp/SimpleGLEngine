// //#include <GL/glut.h>
// #include <GL/glew.h>
// #include <GL/gl.h>
// #include <GL/glu.h>
// #include <stdio.h>
#include <GL/gl.h>
#include <iostream>
#include <SDL2/SDL.h>

#include "Screen.h"
#include "Input.h"

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
//     glutInit(&agrc, argv);
// 
//     glutCreateWindow("OpenGl example");
//     glutDisplayFunc(MyDisplay);
//     glutMainLoop();
//     

    Screen::Instance()->Initialize();

    float xPos = 0.0f;
    float yPos = 0.0f;

    while(isAppRunning)
    {
        Screen::Instance()->ClearScreen();
        Input::Instance()->Update();


        isAppRunning = !Input::Instance()->IsXClicked();

        char keyPressed = Input::Instance()->GetKeyDown();
        if(keyPressed == 'a')
        {
            std::cout << "\'a\' key pressed" << std::endl;
            xPos -= 0.01f;
        }
        else if(keyPressed == 'd')
        {
            std::cout << "\'a\' key pressed" << std::endl;
            xPos += 0.01f;
        }        
        else if(keyPressed == 'w')
        {
            std::cout << "\'a\' key pressed" << std::endl;
            yPos += 0.01f;
        }        
        else if(keyPressed == 's')
        {
            std::cout << "\'a\' key pressed" << std::endl;
            yPos -= 0.01f;
        }
        
        
        if(Input::Instance()->IsLeftButtonClicked())
        {
            std::cout << "Left mouse button clicked" << std::endl;
        }

        int mouseX = Input::Instance()->GetMousePositionX();
        int mouseY = Input::Instance()->GetMousePositionY();

        std::cout << "Mouse position : " << mouseX << ", " << mouseY << std::endl;

        MyDisplay(xPos, yPos);
        Screen::Instance()->Present();
    }

    Screen::Instance()->Shutdown();

    return 0;
}
