# Multiple Screens #

In conjunction with a suitable graphics card, Quadifier can be used to create multi-screen configurations with Unity, such as CAVEs. The basic principle is as follows:
  * The graphics card has multiple outputs, one for each display.
  * Using multi-monitor support or NVIDIA Mosaic, these displays are tiled together into a single desktop.
  * The Unity viewport is sized to match the desktop area used by the displays.
  * The Unity viewport is divided up into separate regions, corresponding to each display.

It's possible to create any number of screens, of any size, and to place them at any position and orientation in space. This makes it possible to use a single large screen display, an L-shaped display or a multi-channel CAVE configuration. The same Unity scene could be used with all of these displays without modification, and you would simply create a different configuration file for each display.

# Example: 4-sided CAVE Display #

We have a CAVE type display, consisting of four separate screens: left, front, right and floor. This forms a 2.5m cube, open on two faces (top and back). Each screen is covered by two projectors, each having 1280x720 resolution. They overlap by 160 pixels to produce an image of 1280x1280 resolution on each screen. Therefore, each pixel is just under 2mm in size, and the display has 4x1280x1280 pixels (about 6.6MP). There are 8 projectors in total.

We drive this display with two [NVIDIA Quadro Plex 7000](http://www.nvidia.co.uk/object/product-quadroplex-7000-uk.html) units, each one having four video outputs. These outputs are configured with [NVIDIA Mosaic](http://www.nvidia.com/object/nvidia-mosaic-technology.html) to appear as a single display of 5120x1280 resolution. Projector overlap, edge-blending and warping is implemented on the graphics card, using the desktop overlap and NVIDIA [Warp & Blend](http://www.nvidia.com/content/siggraph/Nash_Seamless_Display.pdf) API.

The displays are laid out in a 4x2 array (4 columns and 2 rows). The two rows represent the projector pairs for each screen. The columns represent the screen. These are laid out from left to right as follows:

Left, Front, Right, Floor

The Unity window is run in full-screen at 5120x1280 pixels, to cover the entire display. The window is divided into four equally sized regions of 1280x1280 pixels, one for each screen. Again, these are laid out side to side as shown below:

![http://quadifier.googlecode.com/svn/images/unity_viewport.jpg](http://quadifier.googlecode.com/svn/images/unity_viewport.jpg)

When displayed on the projectors, the end result looks like this (note the double-image due to this photo being taken in stereo mode):

![http://quadifier.googlecode.com/svn/images/on_the_cube.jpg](http://quadifier.googlecode.com/svn/images/on_the_cube.jpg)

This is accomplished using the [Quadifier.js](http://quadifier.googlecode.com/svn/trunk/unity/CAVEUnity1/Assets/Scripts/Quadifier.js) script in Unity. This reads an XML configuration file called [settings.xml](http://quadifier.googlecode.com/svn/trunk/unity/CAVEUnity1/settings.xml), which describes the size and position of each screen. The configuration file is described in more detail [here](ConfigurationFiles.md)