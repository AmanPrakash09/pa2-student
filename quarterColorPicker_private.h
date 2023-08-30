/**
 * @file quarterColorPicker_private.h
 * @description student declarations of private functions
 *              for QuarterColorPicker, CPSC 221 2023S PA2
 *
 *              THIS FILE WILL BE SUBMITTED.
 *
 *              Simply declare your function prototypes here.
 *              No other scaffolding is necessary.
 */

 // begin your declarations below

// #ifndef QUARTERCOLORPICKER_PRIVATE_H_
// #define QUARTERCOLORPICKER_PRIVATE_H_

#define PI 3.14159265358979323846

#include "colorPicker.h"
#include "quarterColorPicker.h"

class QuarterColorPickerPrivate {
public:
    static double sin(double radian);
 
    static double cos(double radian);

    static double atan(double x);

    static double atan2(double y, double x);

    static double averageHue(double left, double right);
};

// #endif
