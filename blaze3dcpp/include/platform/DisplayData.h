#ifndef PLATFORM_DISPLAYDATA_H
#define PLATFORM_DISPLAYDATA_H

namespace blaze3dcpp
{
    class DisplayData
    {
    public:
        DisplayData(const int width, const int height, const int fullscreenWidth, const int fullscreenHeight, const bool isFullscreen) :
            m_width(width), m_height(height), m_fullscreenWidth(fullscreenWidth), m_fullscreenHeight(fullscreenHeight), m_isFullscreen(isFullscreen)
        {}
        const int m_width;
        const int m_height;
        const int m_fullscreenWidth;
        const int m_fullscreenHeight;
        const bool m_isFullscreen;
    };
} // namespace blaze3dcpp
#endif
