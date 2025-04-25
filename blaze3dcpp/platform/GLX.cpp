#include "platform/GLX.h"

using blaze3dcpp::GLX;
using blaze3dcpp::String;

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

// static void checkGlfwError(const std::function<void(int, const std::string&)>& callback)
// {
//     const char *desc;
//     const auto error = glfwGetError(&desc);
//     if(error != GLFW_NO_ERROR)
//     {
//         std::string errorMsg = (desc != nullptr) ? desc : "Unknown error";
//     }
//     callback(error, desc);
// }

long GLX::initGlfw()
{
    // checkGlfwError([](int a, const std::string& n) { throw std::runtime_error("GLFW error before init: [0x%X]%s" + std::string(n)); });
    // std::vector<String> list;
    if(!glfwInit())
    {
        // throw std::runtime_error("Failed to initialize GLFW");
    }
    else
    {
        const long longSupplier = glfwGetTime() * static_cast<long>(1.0e9);
        return longSupplier;
        // glfwSetErrorCallback()
    }
}
void GLX::setGlfwErrorCallback(const GLFWerrorfun _errorfun)
{
    glfwSetErrorCallback(_errorfun);
}
bool GLX::shouldClose(GLFWwindow* _window) noexcept
{
    return glfwWindowShouldClose(_window);
}
void GLX::init(int, bool)
{

}

