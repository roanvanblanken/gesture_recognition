#ifndef NEUTON_MODEL_MODEL_H
#define NEUTON_MODEL_MODEL_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Model info */
#define NEUTON_MODEL_HEADER_VERSION 3
#define NEUTON_MODEL_QLEVEL 8
#define NEUTON_MODEL_FLOAT_SUPPORT 1
#define NEUTON_MODEL_TASK_TYPE 0  // multiclass classification
#define NEUTON_MODEL_NEURONS_COUNT 6
#define NEUTON_MODEL_WEIGHTS_COUNT 25
#define NEUTON_MODEL_INPUTS_COUNT 300
#define NEUTON_MODEL_INPUT_LIMITS_COUNT 300
#define NEUTON_MODEL_OUTPUTS_COUNT 3
#define NEUTON_MODEL_LOG_SCALE_OUTPUTS 0
#define NEUTON_MODEL_HAS_CLASSES_RATIO 0
#define NEUTON_MODEL_HAS_NEGPOS_RATIO 0

/* Preprocessing */
#define NEUTON_PREPROCESSING_ENABLED 0
#define NEUTON_DROP_ORIGINAL_FEATURES 0
#define NEUTON_BITMASK_ENABLED 1
#define NEUTON_INPUTS_IS_INTEGER 0
#define NEUTON_MODEL_SA_PRECISION 24

/* Types */
typedef float input_t;
typedef float extracted_feature_t;
typedef uint8_t coeff_t;
typedef int8_t weight_t;
typedef int32_t acc_signed_t;
typedef uint32_t acc_unsigned_t;
typedef uint16_t sources_size_t;
typedef uint8_t weights_size_t;
typedef uint8_t neurons_size_t;

/* Limits */
static const input_t modelInputMin[] = {
	-2.0469999, -4, 0.509, -337.341, -413.147, -1137.6949, -2.1619999, -4,
	0.336, -372.314, -526.367, -1166.443, -2.273, -3.5969999, -0.72600001,
	-507.202, -363.83099, -1254.7, -1.258, -3.4289999, -1.005, -578.00299,
	-249.146, -1169.373, -0.81199998, -3.4070001, -1.021, -577.14801, -250.67101,
	-1186.829, -0.33199999, -2.6559999, -1.013, -392.33401, -293.15201, -1171.021,
	-0.33000001, -3.142, -0.60299999, -396.97299, -265.38101, -1078.674, -0.60500002,
	-4, -0.90499997, -426.819, -200.5, -938.72101, -1.005, -4, -0.31099999,
	-442.26099, -190.125, -806.51898, -0.75199997, -3.467, 0.36000001, -492.004,
	-150.39101, -491.51599, -0.60600001, -2.6930001, 0.50300002, -478.45499,
	-183.899, -368.04199, -0.48800001, -2.322, 0.37599999, -421.509, -191.95599,
	-257.14099, -0.30500001, -1.745, 0.39199999, -160.767, -195.007, -104.065,
	-0.30899999, -1.388, 0.40200001, -128.90601, -183.411, -118.042, -0.31799999,
	-1.0319999, 0.175, -110.657, -133.423, -133.24001, -0.34299999, -0.78200001,
	0.147, -89.477997, -94.237999, -175.842, -0.39500001, -0.85000002, 0.25099999,
	-68.176003, -78.490997, -208.069, -0.57999998, -1.1109999, 0.079000004,
	-43.945, -106.079, -270.142, -0.55199999, -1.3559999, -0.071000002, -48.522999,
	-107.544, -297.974, -0.48500001, -1.181, -0.176, -42.603001, -98.083, -381.77499,
	-0.52399999, -1.117, -0.12800001, -71.349998, -93.872002, -396.54501, -0.583,
	-1.118, -0.027000001, -134.58299, -78.978996, -399.71899, -0.53899997,
	-1.159, 0.176, -213.92799, -80.932999, -407.59299, -0.59500003, -1.2029999,
	0.149, -182.007, -83.191002, -405.27301, -0.88800001, -0.89700001, 0.059,
	-69.763, -103.21, -372.742, -0.87199998, -0.78100002, 0.077, -78.612999,
	-101.929, -348.267, -0.801, -0.903, 0.338, -70.496002, -183.838, -358.15399,
	-0.71100003, -0.87, 0.377, -78.978996, -217.834, -354.67499, -0.56, -0.81699997,
	0.40700001, -84.167, -228.821, -290.466, -0.74800003, -0.74699998, 0.28099999,
	-100.037, -196.411, -240.05099, -0.75800002, -0.85500002, 0.30700001, -94.237999,
	-177.91701, -223.08299, -0.53299999, -0.98400003, 0.42399999, -87.462997,
	-150.879, -206.543, -0.60299999, -0.96600002, 0.46000001, -83.313004, -161.92599,
	-210.327, -0.78200001, -1.104, 0.46000001, -101.868, -168.823, -281.43301,
	-0.81300002, -0.69199997, 0.495, -111.572, -151.91701, -341.492, -0.792,
	-0.65499997, 0.51800001, -102.966, -140.442, -404.90701, -0.60000002, -0.65399998,
	0.47600001, -70.679001, -171.936, -497.98599, -0.57099998, -0.69199997,
	0.44800001, -77.209, -176.575, -529.78497, -0.52700001, -0.88200003, 0.435,
	-68.114998, -145.87399, -560.05902, -0.52200001, -1.5369999, 0.47799999,
	-61.707001, -136.23, -543.70099, -0.505, -2.171, 0.479, -141.052, -134.033,
	-517.39502, -1.36, -1.71, 0.34599999, -138.733, -134.58299, -497.49799,
	-1.457, -1.482, 0.28999999, -102.173, -147.15601, -536.86499, -1.147, -1.61,
	0.134, -90.697998, -209.839, -605.896, -1.364, -1.3890001, 0.093999997,
	-143.799, -234.192, -651.06201, -0.91399997, -1.794, 0.41600001, -157.47099,
	-284.60699, -672.79102, -0.81999999, -1.915, 0.50999999, -113.464, -313.84299,
	-636.53601, -1.058, -2.1949999, 0.602, -124.39, -314.819, -600.40302, -1.341,
	-1.682, 0.70599997, -108.459, -188.72099, -583.25201, -1.374, -1.998, 0.67400002,
	-85.693001, -176.20799, -534.11902 };
static const input_t modelInputMax[] = {
	3.4330001, 3.3310001, 2.385, 580.68799, 168.76199, 934.875, 3.5369999,
	3.618, 2.569, 630.06598, 270.32501, 907.71503, 2.97, 2.711, 2.2880001,
	572.69299, 268.311, 779.11401, 3.306, 1.531, 2.178, 540.64899, 318.35901,
	961.24298, 3.6010001, 0.93800002, 2.207, 588.92798, 352.966, 1127.2581,
	3.227, 0.52700001, 2.1029999, 522.52197, 276.85501, 1141.418, 3.592, 0.47099999,
	1.885, 415.10001, 191.03999, 1062.1949, 3.7479999, 0.73199999, 2.852, 192.078,
	226.80701, 975.28101, 3.543, 1.386, 2.858, 169.373, 248.291, 907.59302,
	3.5969999, 1.601, 2.6900001, 186.52299, 261.71899, 640.80798, 3.9979999,
	2.895, 2.1630001, 181.82401, 294.79999, 503.845, 3.306, 2.085, 2.635, 204.16299,
	385.315, 438.72101, 2.0250001, 1.175, 2.4649999, 207.03101, 293.15201,
	266.11301, 1.507, 0.82200003, 1.949, 220.642, 296.14301, 225.09801, 1.239,
	1.08, 1.396, 241.028, 298.52301, 242.31, 0.722, 1.048, 1.357, 239.502,
	288.02499, 237.793, 0.53299999, 0.92900002, 1.362, 226.50101, 267.45599,
	223.45, 0.37099999, 0.67400002, 1.24, 198.05901, 237.61, 231.995, 0.29100001,
	0.55699998, 1.175, 199.097, 210.937, 229.004, 0.236, 0.421, 1.173, 255.24899,
	164.49001, 311.82901, 0.264, 0.421, 1.153, 264.95401, 151.367, 408.81299,
	0.28099999, 0.40900001, 1.443, 250.12199, 117.065, 574.40198, 0.78500003,
	0.28099999, 1.901, 234.192, 96.435997, 609.375, 1.063, 0.26699999, 2.279,
	221.67999, 89.050003, 603.76001, 1.251, 0.331, 1.95, 212.524, 88.257004,
	485.71799, 1.222, 0.39300001, 1.836, 198.547, 81.177002, 449.82901, 1.63,
	0.44499999, 1.9349999, 171.692, 113.953, 376.83099, 1.649, 0.463, 1.834,
	165.588, 153.381, 293.091, 1.406, 0.495, 1.7079999, 150.513, 216.30901,
	275.452, 0.88800001, 0.56099999, 1.3430001, 162.659, 230.53, 298.27899,
	0.67799997, 0.53399998, 1.256, 159.851, 227.722, 312.68301, 0.634, 0.58899999,
	1.245, 174.683, 210.26601, 319.27499, 0.67900002, 0.64399999, 1.3430001,
	177.185, 197.632, 313.72101, 0.787, 0.69800001, 1.3710001, 154.48, 140.259,
	333.19101, 0.85399997, 0.639, 1.531, 164.429, 128.72301, 329.52899, 0.85399997,
	0.61199999, 1.4170001, 175.537, 111.267, 317.68799, 0.833, 0.61400002,
	1.444, 204.16299, 57.799999, 293.64001, 0.85699999, 0.62699997, 1.335,
	216.431, 52.612, 286.49899, 1.05, 0.64200002, 1.2640001, 207.214, 69.397003,
	311.09601, 1.087, 0.66799998, 1.339, 188.354, 79.894997, 313.78201, 1.069,
	0.65399998, 1.3890001, 170.22701, 82.335999, 302.30701, 1.0549999, 0.704,
	1.301, 160.645, 70.007004, 298.21799, 1.0930001, 0.73799998, 1.369, 149.71899,
	72.693001, 299.194, 1.252, 0.62099999, 1.335, 143.005, 73.668999, 283.508,
	1.467, 0.52600002, 1.3559999, 153.381, 69.213997, 268.37201, 1.516, 0.43099999,
	1.4069999, 145.996, 82.824997, 276.54999, 1.223, 0.359, 1.582, 110.718,
	88.988998, 281.92099, 1.122, 0.31799999, 1.668, 108.521, 98.022003, 286.68201,
	0.72000003, 0.345, 1.875, 111.145, 142.883, 299.62201, 0.72399998, 0.43399999,
	1.472, 130.92, 162.10899, 314.14801 };

static const uint8_t modelUsedInputsMask[] = {
	0x04, 0x00, 0x00, 0x00, 0x10, 0x00, 0x01, 0x20, 0x02, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x09, 0x00, 0x00, 0x02, 0x08, 0x00, 0x00, 0x02, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
	0x00, 0x00 };

/* Structure */
static const weight_t modelWeights[] = {
	125, 4, -113, 64, -128, -3, -128, 33, 11, 93, -98, 72, -103, 60, -128,
	24, -80, 65, 127, 123, -123, -34, -6, -121, 18 };

static const sources_size_t modelLinks[] = {
	2, 36, 147, 217, 225, 300, 0, 300, 111, 112, 115, 137, 169, 300, 2, 300,
	2, 48, 61, 65, 233, 281, 300, 4, 300 };

static const weights_size_t modelIntLinksBoundaries[] = { 0, 7, 8, 15, 16, 24 };
static const weights_size_t modelExtLinksBoundaries[] = { 6, 8, 14, 16, 23, 25 };

static const coeff_t modelFuncCoeffs[] = { 105, 82, 145, 117, 140, 83 };
static const uint8_t modelFuncTypes[] = { 0, 0, 0, 0, 0, 0 };

static const neurons_size_t modelOutputNeurons[] = { 1, 3, 5 };

#ifdef __cplusplus
}
#endif

#endif // NEUTON_MODEL_MODEL_H

