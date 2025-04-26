#ifndef PLATFORM_WINDOWEVENTHANDLER_H
#define PLATFORM_WINDOWEVENTHANDLER_H

class WindowEventHandler
{
public:
    virtual ~WindowEventHandler() = default;

private:
    virtual void setWindowActive(bool) = 0;
    virtual void resizeDisplay() = 0;
    virtual void cursorEntered() = 0;
};

#endif
