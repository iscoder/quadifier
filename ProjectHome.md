This project enables the [Unity](http://www.unity3d.com) 3D game engine to display in quad-buffer OpenGL stereo under both [Windows](Windows.md) and [Linux](Linux.md). It requires some scripts on the Unity side to render the left and right channels in the correct order.

It could potentially be adapted for use with other Direct3D applications under Windows.

The motivation for developing this software was to support quad-buffer stereo rendering with head-tracking and [multiple screens](MultipleScreens.md), including a 4 sided CAVE display, and a second display with an L-shaped screen (wall and floor projection).

The main aims of the project:
  * Enable Unity to render in Stereoscopic 3D (OpenGL quad-buffer stereo)
  * Support multiple display screens
  * Support head tracking
  * Allow the same Unity scene to run on a variety of different VR displays
  * Compatible with both the free and professional version of Unity