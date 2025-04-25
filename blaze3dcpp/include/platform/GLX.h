#ifndef GLX_H
#define GLX_H

#include <GLFW/glfw3.h>
#include <string>
#include <spdlog/spdlog.h>

namespace blaze3dcpp
{
using String = std::string;

class GLX
{
    static String cpuInfo;

public:
    GLX() = delete;
    GLX(const GLX&) = delete;
    GLX(GLX&&) = delete;
    GLX& operator=(const GLX&) = delete;
    GLX& operator=(GLX&&) = delete;

    static String getOpenGLVersionString();
    static int getRefreshRate(GLFWwindow*);
    static long initGlfw();
    static void setGlfwErrorCallback(GLFWerrorfun);
    static bool shouldClose(GLFWwindow*) noexcept;
    static void init(int, bool);
    static String getCpuInfo() noexcept;
};
} // namespace blaze3dcpp

#endif