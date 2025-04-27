#include <glad/glad.h>
#include "GLX.h"

using blaze3dcpp::GLX;
using blaze3dcpp::String;

String GLX::m_cpuInfo = "unknow";

String GLX::getOpenGLVersionString()
{
    if(const auto glVersion = glGetString(GL_VERSION))
    {
        return reinterpret_cast<const char*>(glVersion);
    }
    return "OpenGL version unknown";
}
int GLX::getRefreshRate(GLFWwindow* _window)
{
    GLFWmonitor* wmonitor = glfwGetWindowMonitor(_window);
    if(!wmonitor)
    {
        wmonitor = glfwGetPrimaryMonitor();
    }
    const GLFWvidmode* vidmode = wmonitor == nullptr ? nullptr : glfwGetVideoMode(wmonitor);
    return wmonitor == nullptr ? -1 : vidmode->refreshRate;
}

// UNFINISHED
long GLX::initGlfw()
{
    // checkGlfwError([](int a, const std::string& n) { throw std::runtime_error("GLFW error before init: [0x%X]%s" + std::string(n)); });
    // std::vector<String> list;
    if(!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    else
    {
        const long longSupplier = static_cast<long>(glfwGetTime() * 1.0e9);
        return longSupplier;
        // glfwSetErrorCallback()
    }
}
void GLX::setGlfwErrorCallback(const GLFWerrorfun _errorfun)
{
    glfwSetErrorCallback(_errorfun);
}
bool GLX::shouldClose(GLFWwindow* _window)
{
    return glfwWindowShouldClose(_window);
}
void GLX::init(int, bool) {}

String GLX::getCpuInfo() noexcept
{
    return m_cpuInfo;
}