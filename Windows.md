# Using Quadifier on Windows #

The Windows version of Quadifier consists of three components:
  * **Module**: this is a DLL that is injected into Unity.
  * **Launcher**: this is an executable which starts Unity and injects the Module into Unity.
  * **Scripts**: a set of Unity scripts are used to render the different views needed by Quadifier.

The Quadifier Module is a DLL which is injected into Unity. It intercepts the Direct3D rendering calls made by Unity, and redirects them to an off-screen buffer. They are then rendered back to the screen using OpenGL quad-buffer stereo.

We use scripts in Unity to render the left and right eye views. These are then captured and redirected to the GL\_BACK\_LEFT and GL\_BACK\_RIGHT buffers by Quadifier.

There is also a [Linux](Linux.md) version of Quadifier available.

# Getting Started #

The basic steps are as follows:
  1. Check-out the source code using Subversion
  1. Download any dependencies (VRPN and OpenGL headers for example)
  1. Build Quadifier using Microsoft Visual Studio, using the solution provided
  1. Build the CAVEUnity1 project with Unity (or roll your own, using the scripts provided in that project)
  1. If using head tracking, run 'vrpnbridge' to connect to your tracker
  1. Drag your Unity EXE onto the Quadifier Launcher
  1. Enter an amazing virtual world, where anything is possible..