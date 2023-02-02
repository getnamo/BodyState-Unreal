## Overview ##

An abstract skeleton target for body tracking input devices. These hardware devices pass information to the BodyState plugin which then holds a composite body for developer to query and use in the game without concern for actual hardware implementation of body tracking.

### Example input devices (non-exhaustive) 

HMD mounted systems: [Leap Motion](https://www.leapmotion.com/) - See Example plugin using bodystate https://github.com/ultraleap/UnrealPlugin/

Systems with motion controllers: [Razer Hydra](http://www.razerzone.com/gb-en/gaming-controllers/razer-hydra-portal-2-bundle), [Sixense STEM](http://sixense.com/wireless), [HTC Vive (Lighthouse)](https://www.htcvive.com/us/), [Oculus Touch](https://www.oculus.com/en-us/touch/)

Camera based systems: [Microsoft Kinect](https://dev.windows.com/en-us/kinect/develop), [Intel RealSense](http://www.intel.com/content/www/us/en/architecture-and-technology/realsense-overview.html)

Single IMU based systems: [SensorTag 2](http://www.ti.com/tool/cc2650stk)

Fullbody/Mixed systems: [Perception Neuron](https://neuronmocap.com/)
