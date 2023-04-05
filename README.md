# Gesture Recognition with Arduino

Our team decided to work on a project involving an Arduino, and we quickly became interested in gesture recognition, specifically focusing on hand movements. The purpose of this project is to create a system that can be controlled through hand gestures, making it useful for people who may have difficulty controlling a phone or computer with their hands.

We also aimed to develop an application with a user interface that can be controlled through hand gestures. We decided to create an application that can easily and automatically order food.

## Method

We used the gyroscope and accelerometer sensors on the Arduino Nano 33 IoT, as we had some experience working with these sensors during the first week of the project. We first explored the possibilities of measuring and classifying hand movements using these sensors. This turned out to be more challenging than anticipated.

Eventually, we came up with two options:

1. Use the gyroscope to measure tilts in three dimensions. This would allow us to send a command to the application by tilting the device.

2. Use a TinyML to train a model that can recognize and classify hand gestures. This program receives a gesture as input and checks if it can classify the gesture.

The code from this page was used to create the second option

The code is based of this project: https://www.hackster.io/leonardocavagnis/gesture-recognition-tinyml-for-8-bit-microcontroller-1cb0a8