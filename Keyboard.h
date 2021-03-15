#ifndef KEYBOARD_H
#define KEYBOARD_H


class KeyPressed
{
public:
    KeyPressed();
    void press();
    void release();
    bool status();
private:
   bool key_;
};

class Keyboard
{
public:
    Keyboard();
    ~Keyboard();

    KeyPressed* left_=nullptr;
    KeyPressed* right_=nullptr;
};

#endif // KEYBOARD_H
