#ifndef PLATFORM_WINDOW_H
#define PLATFORM_WINDOW_H

#include <GLFW/glfw3.h>
#include "SString.h"
#include "DisplayData.h"
#include "WindowEventHandler.h"

using blaze3dcpp::String;

namespace blaze3dcpp
{
    class Window
    {
    public:
        Window(WindowEventHandler& eventHandler /* Screen Manager */, const DisplayData& displayData, String title);
        static String getPlatform();
        [[nodiscard]] int getRefreshRate() const;
        [[nodiscard]] bool shouldClose() const;


    private:
        static constexpr int BASE_WIDTH = 320;
        static constexpr int BASE_HEIGHT = 240;
        const WindowEventHandler& m_eventHandler;
        GLFWwindow* m_window;
        int m_windowedX{};
        int m_windowedY{};
        int m_windowedWidth;
        int m_windowedHeight;
        // videomode
        bool m_fullscreen;
        bool m_actuallyFullscreen;
        int m_x{};
        int m_y{};
        int m_width;
        int m_height;
        int m_framebufferWidth{};
        int m_framebufferHeight{};
        int m_guiScaledWidth{};
        int m_guiScaledHeight{};
        double m_guiScale{};
        String m_errorSection = "";
        bool m_dirty{};
        bool m_vsync{};
        bool m_iconified{};
        bool m_minimized{};
    };
} // namespace blaze3dcpp
#endif
