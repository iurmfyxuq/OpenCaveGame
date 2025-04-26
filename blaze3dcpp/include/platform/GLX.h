#ifndef PLATFORM_GLX_H
#define PLATFORM_GLX_H

#include <GLFW/glfw3.h>
#include "SString.h"

namespace blaze3dcpp
{
    class GLX
    {
        static String m_cpuInfo;

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
}

#endif