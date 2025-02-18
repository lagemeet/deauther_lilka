#include "fmath.h"

namespace lilka {

// Таблиці значень функції sin(x) для кутів від 0 до 359 градусів
// Крок: 1 градус (360 поділок)
float sin360[360] = {
    0.000000,  0.017452,  0.034899,  0.052336,  0.069756,  0.087156,  0.104528,  0.121869,  0.139173,  0.156434,
    0.173648,  0.190809,  0.207912,  0.224951,  0.241922,  0.258819,  0.275637,  0.292372,  0.309017,  0.325568,
    0.342020,  0.358368,  0.374607,  0.390731,  0.406737,  0.422618,  0.438371,  0.453990,  0.469472,  0.484810,
    0.500000,  0.515038,  0.529919,  0.544639,  0.559193,  0.573576,  0.587785,  0.601815,  0.615662,  0.629320,
    0.642788,  0.656059,  0.669131,  0.681998,  0.694658,  0.707107,  0.719340,  0.731354,  0.743145,  0.754710,
    0.766044,  0.777146,  0.788011,  0.798636,  0.809017,  0.819152,  0.829038,  0.838671,  0.848048,  0.857167,
    0.866025,  0.874620,  0.882948,  0.891007,  0.898794,  0.906308,  0.913545,  0.920505,  0.927184,  0.933580,
    0.939693,  0.945519,  0.951057,  0.956305,  0.961262,  0.965926,  0.970296,  0.974370,  0.978148,  0.981627,
    0.984808,  0.987688,  0.990268,  0.992546,  0.994522,  0.996195,  0.997564,  0.998630,  0.999391,  0.999848,
    1.000000,  0.999848,  0.999391,  0.998630,  0.997564,  0.996195,  0.994522,  0.992546,  0.990268,  0.987688,
    0.984808,  0.981627,  0.978148,  0.974370,  0.970296,  0.965926,  0.961262,  0.956305,  0.951057,  0.945519,
    0.939693,  0.933580,  0.927184,  0.920505,  0.913545,  0.906308,  0.898794,  0.891007,  0.882948,  0.874620,
    0.866025,  0.857167,  0.848048,  0.838671,  0.829038,  0.819152,  0.809017,  0.798636,  0.788011,  0.777146,
    0.766044,  0.754710,  0.743145,  0.731354,  0.719340,  0.707107,  0.694658,  0.681998,  0.669131,  0.656059,
    0.642788,  0.629320,  0.615662,  0.601815,  0.587785,  0.573576,  0.559193,  0.544639,  0.529919,  0.515038,
    0.500000,  0.484810,  0.469472,  0.453990,  0.438371,  0.422618,  0.406737,  0.390731,  0.374607,  0.358368,
    0.342020,  0.325568,  0.309017,  0.292372,  0.275637,  0.258819,  0.241922,  0.224951,  0.207912,  0.190809,
    0.173648,  0.156434,  0.139173,  0.121869,  0.104528,  0.087156,  0.069756,  0.052336,  0.034899,  0.017452,
    0.000000,  -0.017452, -0.034899, -0.052336, -0.069756, -0.087156, -0.104528, -0.121869, -0.139173, -0.156434,
    -0.173648, -0.190809, -0.207912, -0.224951, -0.241922, -0.258819, -0.275637, -0.292372, -0.309017, -0.325568,
    -0.342020, -0.358368, -0.374607, -0.390731, -0.406737, -0.422618, -0.438371, -0.453990, -0.469472, -0.484810,
    -0.500000, -0.515038, -0.529919, -0.544639, -0.559193, -0.573576, -0.587785, -0.601815, -0.615662, -0.629320,
    -0.642788, -0.656059, -0.669131, -0.681998, -0.694658, -0.707107, -0.719340, -0.731354, -0.743145, -0.754710,
    -0.766044, -0.777146, -0.788011, -0.798636, -0.809017, -0.819152, -0.829038, -0.838671, -0.848048, -0.857167,
    -0.866025, -0.874620, -0.882948, -0.891007, -0.898794, -0.906308, -0.913545, -0.920505, -0.927184, -0.933580,
    -0.939693, -0.945519, -0.951057, -0.956305, -0.961262, -0.965926, -0.970296, -0.974370, -0.978148, -0.981627,
    -0.984808, -0.987688, -0.990268, -0.992546, -0.994522, -0.996195, -0.997564, -0.998630, -0.999391, -0.999848,
    -1.000000, -0.999848, -0.999391, -0.998630, -0.997564, -0.996195, -0.994522, -0.992546, -0.990268, -0.987688,
    -0.984808, -0.981627, -0.978148, -0.974370, -0.970296, -0.965926, -0.961262, -0.956305, -0.951057, -0.945519,
    -0.939693, -0.933580, -0.927184, -0.920505, -0.913545, -0.906308, -0.898794, -0.891007, -0.882948, -0.874620,
    -0.866025, -0.857167, -0.848048, -0.838671, -0.829038, -0.819152, -0.809017, -0.798636, -0.788011, -0.777146,
    -0.766044, -0.754710, -0.743145, -0.731354, -0.719340, -0.707107, -0.694658, -0.681998, -0.669131, -0.656059,
    -0.642788, -0.629320, -0.615662, -0.601815, -0.587785, -0.573576, -0.559193, -0.544639, -0.529919, -0.515038,
    -0.500000, -0.484810, -0.469472, -0.453990, -0.438371, -0.422618, -0.406737, -0.390731, -0.374607, -0.358368,
    -0.342020, -0.325568, -0.309017, -0.292372, -0.275637, -0.258819, -0.241922, -0.224951, -0.207912, -0.190809,
    -0.173648, -0.156434, -0.139173, -0.121869, -0.104528, -0.087156, -0.069756, -0.052336, -0.034899, -0.017452,
};

// Крок: 11.25 градусів (32 поділки)
float sin32[32] = {
    0.000000,  0.195090,  0.382683,  0.555570,  0.707107,  0.831470,  0.923880,  0.980785,
    1.000000,  0.980785,  0.923880,  0.831470,  0.707107,  0.555570,  0.382683,  0.195090,
    0.000000,  -0.195090, -0.382683, -0.555570, -0.707107, -0.831470, -0.923880, -0.980785,
    -1.000000, -0.980785, -0.923880, -0.831470, -0.707107, -0.555570, -0.382683, -0.195090,
};

float fSin360(int deg) {
    // Convert the degree to a positive value in the range [0, 359].
    deg = deg % 360;
    if (deg < 0) {
        deg += 360;
    }
    return sin360[deg];
}

float fCos360(int deg) {
    // Convert the degree to a positive value in the range [0, 359].
    deg = deg % 360;
    if (deg < 0) {
        deg += 360;
    }
    // The cosine function is the sine function with an offset of 90 degrees.
    return sin360[(deg + 90) % 360];
}

float fSin32(int fract) {
    // Convert the fraction to a positive value in the range [0, 31].
    fract = fract % 32;
    if (fract < 0) {
        fract += 32;
    }
    return sin32[fract];
}

float fCos32(int fract) {
    // Convert the fraction to a positive value in the range [0, 31].
    fract = fract % 32;
    if (fract < 0) {
        fract += 32;
    }
    // The cosine function is the sine function with an offset of 90 degrees.
    return sin32[(fract + 8) % 32];
}

} // namespace lilka
