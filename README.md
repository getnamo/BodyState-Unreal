## Overview ##

An abstract skeleton target for body tracking input devices. These hardware devices pass information to the BodyState plugin which then holds a composite body for developer to query and use in the game without concern for actual hardware implementation of body tracking.

*Note that the plugin is currently in a non-functioning state and is in heavy development*

### General Idea

<img src ="http://i.imgur.com/EDNCitF.png">

### Example input devices (non-exhaustive) 

HMD mounted systems: [Leap Motion](https://www.leapmotion.com/)

Systems with motion controllers: [Razer Hydra](http://www.razerzone.com/gb-en/gaming-controllers/razer-hydra-portal-2-bundle), [Sixense STEM](http://sixense.com/wireless), [HTC Vive (Lighthouse)](https://www.htcvive.com/us/), [Oculus Touch](https://www.oculus.com/en-us/touch/)

Camera based systems: [Microsoft Kinect](https://dev.windows.com/en-us/kinect/develop), [Intel RealSense](http://www.intel.com/content/www/us/en/architecture-and-technology/realsense-overview.html)

Single IMU based systems: [Thalmic Myo](https://www.myo.com/), [SensorTag 2](http://www.ti.com/tool/cc2650stk)

Fullbody/Mixed systems: [PrioVR](http://www.priovr.com/), [Perception Neuron](https://neuronmocap.com/)