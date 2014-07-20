/******************************************************************************
    QtAV:  Media play library based on Qt and FFmpeg
    Copyright (C) 2014 Wang Bin <wbsecg1@gmail.com>

*   This file is part of QtAV

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
******************************************************************************/

#ifndef QTAV_VIDEORENDEREROPENGL_H
#define QTAV_VIDEORENDEREROPENGL_H

#include <QtAV/VideoRenderer.h>
#include <QtOpenGL/QGLWidget>

namespace QtAV {

class VideoRendererOpenGLPrivate;
/*!
 * \brief The VideoRendererOpenGL class
 * Renderering video frames using GLSL. A more generic high level class OpenGLVideo is used internally.
 * TODO: for Qt5, no QtOpenGL, use QWindow instead.
 */
class Q_AV_EXPORT VideoRendererOpenGL : public QGLWidget, public VideoRenderer
{
    DPTR_DECLARE_PRIVATE(VideoRendererOpenGL)
public:
    VideoRendererOpenGL(QWidget* parent = 0, const QGLWidget* shareWidget = 0, Qt::WindowFlags f = 0);
    virtual VideoRendererId id() const;
    virtual bool isSupported(VideoFormat::PixelFormat pixfmt) const;
    virtual QWidget* widget() { return this; }

protected:
    virtual bool receiveFrame(const VideoFrame& frame);
    virtual bool needUpdateBackground() const;
    //called in paintEvent before drawFrame() when required
    virtual void drawBackground();
    //draw the current frame using the current paint engine. called by paintEvent()
    virtual void drawFrame();
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int w, int h);
    virtual void resizeEvent(QResizeEvent *);
    virtual void showEvent(QShowEvent *);
private:
    virtual void onSetOutAspectRatioMode(OutAspectRatioMode mode);
    virtual void onSetOutAspectRatio(qreal ratio);
    virtual bool onSetBrightness(qreal b);
    virtual bool onSetContrast(qreal c);
    virtual bool onSetHue(qreal h);
    virtual bool onSetSaturation(qreal s);
};

} //namespace QtAV

#endif // QTAV_VIDEORENDEREROPENGL_H