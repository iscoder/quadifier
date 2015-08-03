# Performance Testing #

Test environment:
  * Window 7 Pro 64-bit
  * Intel Core i7-3740QM @ 2.70GHz and 16GB RAM
  * NVIDIA Quadro K2000M with 340.66 drivers
  * FSAA disabled
  * VSync disabled

Vertical sync was disabled to assess maximum frame rate.

Running the CAVEUnity1.exe at 1920x1080 full-screen, rendering 8 views (left and right channels for 4 screens of a CAVE type display).

```
Without Quadifier: ~360fps (2.78ms/frame)
With Quadifier:    ~240fps (4.17ms/frame, cost is ~1.39ms/frame)
```

Overhead of Quadifier should be fairly constant, and independent of scene complexity, but will be affected by fill rate (i.e. screen resolution).