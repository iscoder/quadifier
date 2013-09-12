#ifndef hive_Quadifier_h
#define hive_Quadifier_h

//-----------------------------------------------------------------------------
//
// Copyright (c) 2012-13 James Ward, University of Hull
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
//    1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software.
//
//	  2. If you use this software in a product, an acknowledgment in the
//    product documentation is required.
//
//    3. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
//    4. This notice may not be removed or altered from any source
//    distribution.
//
//-----------------------------------------------------------------------------

#include <d3d9.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/wglext.h>
#include <array>
#include "Event.h"
#include "CriticalSection.h"
#include "Extensions.h"
#include "GLWindow.h"

//-----------------------------------------------------------------------------

class Quadifier {
public:
	Quadifier(
		IDirect3DDevice9 *device,
		IDirect3D9 *direct3D
	);

	virtual ~Quadifier();

	void onCreateDX();

	void onPreClearDX(
		DWORD Count,
		CONST D3DRECT *pRects,
		DWORD Flags,
		D3DCOLOR Color,
		float Z,
		DWORD Stencil
	);

	void onPostClearDX();

	void onPrePresentDX(
		CONST RECT *pSourceRect,
		CONST RECT *pDestRect,
		HWND hDestWindowOverride,
		CONST RGNDATA *pDirtyRegion
	);

	void onPostPresentDX();

	void createResources();

	void createWindow();

	bool onCreate();

	void onDestroy();

	void onPaint();
	
	void onResize( UINT type, int w, int h );

	void onIdle();

	void redraw();

	LRESULT CALLBACK windowProc(
		HWND hWnd,      // handle to window
		UINT uMsg,      // message identifier
		WPARAM wParam,  // first message parameter
		LPARAM lParam   // second message parameter
	);
	
	static unsigned __stdcall threadFunc( void *context );

private:

	/**
	 * Send the last rendered frame from DX to GL and swap the render
	 * targets ready for next frame.
	 */
	void sendFrame();

private:
	IDirect3DDevice9	*m_device;
	IDirect3D9			*m_direct3D;
	LPDIRECT3DSURFACE9	 m_backBuffer;

	unsigned m_framesGL;	///< OpenGL frame count
	unsigned m_fieldsGL;	///< OpenGL field count
	unsigned m_framesDX;	///< Direct3D frame count

    unsigned m_samplesDX;   ///< Direct3D multisamples (or 0)
    unsigned m_samplesGL;   ///< OpenGL multisamples (or 0)

	unsigned m_drawBuffer;	///< buffer to draw to
	unsigned m_readBuffer;	///< buffer to read from
	unsigned m_lastBuffer;	///< last buffer drawn to
	unsigned m_lastChannel;	///< last channel (1=left, 2=right)

	unsigned m_width;		///< display width in pixels
	unsigned m_height;		///< display height in pixels

	struct Target {
        LPDIRECT3DSURFACE9  surface;        ///< Direct3D surface
        LPDIRECT3DSURFACE9  depthSurface;   ///< Direct3D depth/stencil surface
        std::tr1::array<HANDLE,2> object;   ///< Handle of interop object(s)
        GLuint              texture;        ///< OpenGL texture
        GLuint              depthTexture;   ///< OpenGL depth texture
        GLuint              renderBuffer;   ///< OpenGL renderbuffer
        GLuint              depthBuffer;    ///< OpenGL depth buffer
        GLuint              frameBuffer;    ///< OpenGL framebuffer

		Target() :
			surface(0),
            depthSurface(0),
            texture(0),
            depthTexture(0),
			renderBuffer(0),
            depthBuffer(0),
            frameBuffer(0)
		{
            object.fill(0);
		}

		void clear() {
			if ( surface != 0 ) {
				surface->Release();
				surface = 0;
			}
		}
	};

	std::tr1::array<Target,3> m_target;	///< DX/GL targets for rendering

	bool	 m_verbose;				///< Verbose logging

	bool	 m_stereoMode;			///< Stereo mode enable/disable
	bool	 m_stereoAvailable;		///< Is quad-buffer stereo available?
	unsigned m_clearCount;			///< Number of clears per frame
	unsigned m_clearCountPersist;	///< Persistent number of clears

	unsigned m_channelRenderCount;	///< number of channels rendered

	uintptr_t m_thread;

	HWND m_sourceWindow;	///< Window handle of source (Direct3D)

	HANDLE m_interopGLDX;

	Event m_newFrame;
	Event m_frameDone;

	CriticalSection m_swapLock;

    Extensions glx;

    GLWindow m_window;
};

//-----------------------------------------------------------------------------

#endif//hive_Quadifier_h
