#include "Window.h"

blaze3dcpp::Window::Window(WindowEventHandler& eventHandler, const DisplayData& displayData, String title) :
    m_eventHandler(eventHandler), m_errorSection("Pre startup"),
    // videomode
    m_fullscreen(displayData.m_isFullscreen), m_width(displayData.m_width), m_height(displayData.m_height)
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
    
    return;
}