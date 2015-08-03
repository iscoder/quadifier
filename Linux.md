# Using Quadifier on Linux #

The Linux version of Quadifier consists of two components:
  * **quadifier.so**: this module is injected into Unity.
  * **Scripts**: a set of Unity scripts are used to render the different views needed by Quadifier.

The implementation for Linux is simpler than the [Windows](Windows.md) implementation because Linux already uses OpenGL for rendering, so there is no need to intercept and translate Direct3D calls.

To load Quadifier into a Unity executable, we simply use the [LD\_PRELOAD](http://man7.org/linux/man-pages/man8/ld.so.8.html) variable as follows:
```
LD_PRELOAD=$PWD/quadifier.so <YourUnityExecutableHere>
```

This causes the Quadifier module (an ELF shared library) to be loaded into the Unity executable. It then intercepts the OpenGL and GLX calls made by Unity, including glClear, glXSwapBuffers and glXChooseFBConfig.

When Unity creates an OpenGL Window, Quadifier modifies it to have the GLX\_STEREO attribute, adding quad-buffer stereo support. Unity scripts are then used to render the left and right eye views in sequence, which are redirected by Quadifier to the GL\_BACK\_LEFT and GL\_BACK\_RIGHT buffers.