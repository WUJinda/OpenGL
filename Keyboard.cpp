#include "Keyboard.h"

KeyPressed::KeyPressed()
{
    key_=false;
}

void KeyPressed::press()
{
    key_=true;
}

void KeyPressed::release()
{
    key_=false;
}

bool KeyPressed::status()
{
    return(key_);
}

Keyboard::Keyboard()
{
    left_=new KeyPressed();
    right_=new KeyPressed();
}

Keyboard::~Keyboard()
{
    delete [] left_;
    delete [] right_;
}
