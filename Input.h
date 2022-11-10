#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

class Input
{
public:
    static Input* Instance();

public:
    bool IsXClicked();
    bool IsKeyPressed();

    char GetKeyUp();
    char GetKeyDown();

    bool IsLeftButtonClicked();
    bool IsRightButtonClicked();
    bool IsMiddleButtonClicked();

    int GetMouseMotionX();
    int GetMouseMotionY();

    int GetMousePositionX();
    int GetMousePositionY();

public:
    void Update();

private:
    Input();
    Input(const Input&);
    Input& operator=(Input&);

private:
    bool m_isXClicked;
    bool m_isKeyPressed;
    
    char m_keyUp;
    char m_keyDown;
    
    bool m_isLeftButtonClicked;
    bool m_isRightButtonClicked;
    bool m_isMiddleButtonClicked;

    int m_mouseMotionX;
    int m_mouseMotionY;

    int m_mousePositionX;
    int m_mousePositionY;

};

#endif
