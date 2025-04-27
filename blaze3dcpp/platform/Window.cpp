#include "Window.h"

#include "GLX.h"

blaze3dcpp::Window::Window(WindowEventHandler& eventHandler, const DisplayData& displayData, String title) :
    m_eventHandler(eventHandler),
    // videomode
    m_fullscreen(displayData.m_isFullscreen), m_width(displayData.m_width), m_height(displayData.m_height), m_errorSection("Pre startup")
{
    m_actuallyFullscreen = m_fullscreen;
    m_windowedWidth = m_width;
    m_windowedHeight = m_height;
    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    m_window = glfwCreateWindow(m_width, m_height, title.c_str(), NULL, NULL);
    glfwMakeContextCurrent(m_window);
    glfwSetWindowSizeLimits(m_window, -1, -1, 800, 600);
    //
}
String blaze3dcpp::Window::getPlatform()
{
    switch(glfwGetPlatform())
    {
    case GLFW_PLATFORM_ERROR:
        return { "<error>" };
    case GLFW_PLATFORM_WIN32:
        return { "win32" };
    case GLFW_PLATFORM_COCOA:
        return { "cocoa" };
    case GLFW_PLATFORM_WAYLAND:
        return { "wayland" };
    case GLFW_PLATFORM_X11:
        return { "x11" };
    case GLFW_PLATFORM_NULL:
        return { "null" };
    default:
        return { "unknown" };
    }
}
int blaze3dcpp::Window::getRefreshRate() const
{
    return GLX::getRefreshRate(this->m_window);
}
bool blaze3dcpp::Window::shouldClose() const
{
    return GLX::shouldClose(this->m_window);
}
