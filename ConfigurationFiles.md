# Configuration Files #

The Unity script (Quadifier.js) loads an XML configuration file, which defines
the number of position of all the screens, and a few other critical settings such as the eye separation and tracking system to world transformation matrix.

The easiest way to create a suitable file is to edit one of the existing examples. Although this is possible with a text editor, it's much easier with an XML editor like this:

> [Microsoft XML Notepad 2007](http://www.microsoft.com/en-us/download/details.aspx?id=7973)

The XML editor makes it easy to edit the parameters for each projection screen:

> ![http://quadifier.googlecode.com/svn/images/xml_editing.jpg](http://quadifier.googlecode.com/svn/images/xml_editing.jpg)

Here is a brief description of the file contents:
  * **screens**: collection of projection screens (see below)
  * **eyeSeparation**: the viewer's eye separation, usually in metres (e.g. 0.07)
  * **networkPort**: the network port used to communicate with the tracking system
  * **trackerMatrix**: matrix to transform from tracker to Unity coordinates

The configuration file can define anything from a single screen to a multiple channel CAVE display. The screens collection defines one or more projection screen definitions. Each projection screen consists of:
  * **name**: the descriptive name (e.g. 'Front')
  * **centre**: coordinates of the screen centre
  * **normal**: normal to the screen surface (unit length vector)
  * **up**: up vector for the screen (unit length vector)
  * **width**: width of screen in metres
  * **height**: height of screen in metres
  * **viewport**: defines the area of the Unity viewport to use for rendering.

For example, if we had a single screen that was 3m by 2.4m, it might look something like this:
  * **name**: Screen
  * **centre**: (0,0,0)
  * **normal**: (0,0,1) - the Z axis
  * **up**: (0,1,0) - the Y axis
  * **width**: 3
  * **height**: 2.4
  * **viewport**: (0,0,1,1) - using the whole Unity Viewport

If we have [multiple screens](MultipleScreens.md), we can define their name, position and orientation however we wish, and can use the viewport to specify which region of the Unity viewport is used to render that view. For example, we could divide the Unity viewport into two regions, one representing the wall, and one for the floor.

The CAVEUnity1 project provided in the source tree includes a complete example for a 4 sided CAVE type display, with Front, Left, Right and Floor projection.