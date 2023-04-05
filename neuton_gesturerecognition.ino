/* Includes ------------------------------------------------------------------*/
#include <Arduino_LSM6DS3.h>

#include "src/neuton.h"

/* Private define ------------------------------------------------------------*/
#define NUM_SAMPLES         50
#define G                   9.80665f
#define ACC_THRESHOLD       (2.5f*G)          // threshold of significant in G's
#define GESTURE_ARRAY_SIZE  (6*NUM_SAMPLES+1) // 6 measurements (a,g)/sample + target

/* Private variables ---------------------------------------------------------*/
int   samplesRead                       = NUM_SAMPLES;
float gestureArray[GESTURE_ARRAY_SIZE]  = {0};

void setup() {
  // init serial port
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  // init IMU sensor
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1) {
      delay(10);
    }
  }

  Serial.println("Neuton neural network model: Gesture recognition system");
}

void loop() {
  float aX, aY, aZ, gX, gY, gZ;
  
  // wait for significant motion
  while (samplesRead == NUM_SAMPLES) {
    // read the acceleration data
    if (IMU.gyroscopeAvailable() && IMU.accelerationAvailable()) {
      IMU.readAcceleration(aX, aY, aZ);
      IMU.readGyroscope(gX, gY, gZ);
    }
    
    // sum up the absolutes
    float aSum = fabs(aX) + fabs(aY) + fabs(aZ);
    
    // check if it's above the threshold
    if (aSum >= ACC_THRESHOLD) {
      // reset the sample read count
      samplesRead = 0;
      break;
    }
  }

  // read samples of the detected motion
  while (samplesRead < NUM_SAMPLES) {
    // read the acceleration and gyroscope data
    if (IMU.gyroscopeAvailable() && IMU.accelerationAvailable()) {
      IMU.readAcceleration(aX, aY, aZ);
      IMU.readGyroscope(gX, gY, gZ);
    }

    // fill gesture array (model input)
    gestureArray[samplesRead*6 + 0] = (float) aX;
    gestureArray[samplesRead*6 + 1] = (float) aY;
    gestureArray[samplesRead*6 + 2] = (float) aZ;
    gestureArray[samplesRead*6 + 3] = (float) gX;
    gestureArray[samplesRead*6 + 4] = (float) gY;
    gestureArray[samplesRead*6 + 5] = (float) gZ;
    
    samplesRead++;

    delay(10);

    // check the end of gesture acquisition
    if (samplesRead == NUM_SAMPLES) {
      neuton_model_set_inputs(gestureArray);
      uint32_t size_out = 0;
      
      // run model inference
      float* result = neuton_model_run_inference(gestureArray, GESTURE_ARRAY_SIZE, &size_out);

      // check if model inference result is valid
      if (result && size_out) {
        // check if problem is binary classification
        if (size_out >= 2) { 
          // check if one of the result has >50% of accuracy
          if (result[0] > 0.5) {
            Serial.print("Detected gesture: 0 ");
            Serial.print("[Accuracy: ");
            Serial.print(result[0]);
            Serial.println("]");
          } else if (result[1] > 0.5) {
            Serial.print("Detected gesture: 1 ");
            Serial.print("[Accuracy: ");
            Serial.print(result[1]);
            Serial.println("]");
          } else if (result[2] > 0.5) {
            Serial.print("Detected gesture: 2 ");
            Serial.print("[Accuracy: ");
            Serial.print(result[1]);
            Serial.println("]");
          } else {
            // solution is not reliable
            Serial.println("Detected gesture: NONE");
          }
        } else {
          Serial.println("Inference result not valid");
        }
      } else {
        Serial.println("Inference fail to execute");
      }
    }
  }
}
