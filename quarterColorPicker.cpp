/**
 * @file quarterColorPicker.cpp
 * @description Implements the QuarterColorPicker constructor and () function
 *              for CPSC 221 2023S PA2
 *
 *              THIS FILE WILL BE SUBMITTED
 */

#include "quarterColorPicker.h"
// #include "quarterColorPicker_private.h"

#include <cmath>
#define PI 3.14159265358979323846

QuarterColorPicker::QuarterColorPicker(PNG& inputimg)
{
    // Complete your implementation below

    // unsigned int referenceX = 0;
    // unsigned int referenceY = 0;

    // referenceimg.resize(inputimg.width() / 2, inputimg.height() / 2);

    // for (unsigned int x = 0; x < inputimg.width(); x +=2) {
    //     for (unsigned int y = 0; y < inputimg.height(); y += 2) {
    //         // first iteration  --> (0, 0), (0, 1), (1, 0), (1, 1)
    //         // second iteration --> (0, 2), (0, 3), (1, 2), (1, 3)
    //         HSLAPixel* tl = inputimg.getPixel(x, y);
    //         HSLAPixel* tr = inputimg.getPixel(x + 1, y);
    //         HSLAPixel* bl = inputimg.getPixel(x, y + 1);
    //         HSLAPixel* br = inputimg.getPixel(x + 1, y + 1);

    //         // tl and tr hue average

    //         double tlradians = tl->h * PI / 180.0;
    //         double trradians = tr->h * PI / 180.0;

    //         // Convert to Cartesian coordinates.
    //         double tlcartx = std::cos(tlradians), tlcarty = std::sin(tlradians);
    //         double trcartx = std::cos(trradians), trcarty = std::sin(trradians);

    //         // Average the coordinates.
    //         double taverageX = (tlcartx + trcartx) / 2.0;
    //         double taverageY = (tlcarty + trcarty) / 2.0;

    //         // Convert back to polar coordinates.
    //         double taveHue = std::atan2(taverageY, taverageX) * 180.0 / PI;
            
    //         // atan2 returns a value in the range -180 to 180, we want 0 to 360.
    //         if (taveHue < 0) {
    //             taveHue += 360.0;
    //         }

    //         // bl and br hue average

    //         double blradians = bl->h * PI / 180.0;
    //         double brradians = br->h * PI / 180.0;

    //         // Convert to Cartesian coordinates.
    //         double blcartx = std::cos(blradians), blcarty = std::sin(blradians);
    //         double brcartx = std::cos(brradians), brcarty = std::sin(brradians);

    //         // Average the coordinates.
    //         double baverageX = (blcartx + brcartx) / 2.0;
    //         double baverageY = (blcarty + brcarty) / 2.0;

    //         // Convert back to polar coordinates.
    //         double baveHue = std::atan2(baverageY, baverageX) * 180.0 / PI;
            
    //         // atan2 returns a value in the range -180 to 180, we want 0 to 360.
    //         if (baveHue < 0) {
    //             baveHue += 360.0;
    //         }

    //         // top and bottom hue average

    //         double radTop = taveHue * PI / 180.0;
    //         double radBot = baveHue * PI / 180.0;

    //         // Convert to Cartesian coordinates.
    //         double cartTopX = std::cos(radTop), cartTopY = std::sin(radTop);
    //         double cartBotX = std::cos(radBot), cartBotY = std::sin(radBot);

    //         // Average the coordinates.
    //         double averageX = (cartTopX + cartBotX) / 2.0;
    //         double averageY = (cartTopY + cartBotY) / 2.0;

    //         // Convert back to polar coordinates.
    //         double aveHue = std::atan2(averageY, averageX) * 180.0 / PI;
            
    //         // atan2 returns a value in the range -180 to 180, we want 0 to 360.
    //         if (aveHue < 0) {
    //             aveHue += 360.0;
    //         }
    //         // // average tl and tr hue
    //         // double topHue = QuarterColorPickerPrivate::averageHue(tl->h, tr->h);

    //         // // average bl and br hue
    //         // double botHue = QuarterColorPickerPrivate::averageHue(bl->h, br->h);

    //         // // average top and bottom hue
    //         // double aveHue = QuarterColorPickerPrivate::averageHue(topHue, botHue);

    //         double aveSat = (tl->s + tr->s + bl->s + br->s) / 4.0;
    //         double aveLum = (tl->l + tr->l + bl->l + br->l) / 4.0;
    //         double aveAlp = (tl->a + tr->a + bl->a + br->a) / 4.0;

    //         HSLAPixel* pixel = referenceimg.getPixel(referenceX, referenceY);
            
    //         *pixel = HSLAPixel(aveHue, aveSat, aveLum, aveAlp);
    //         referenceY++;
    //     }
    //     referenceX++;
    // }

    referenceimg =  inputimg;

}

/**
 * Picks the color for pixel (x, y).
 *
 * Using the private reference image, scale each dimension by half
 * and tile the smaller image in a 2 x 2 grid over the original dimensions
 * of the image, and return the pixel at the appropriate coordinate from
 * the tiled image.
 *
 * The value of each pixel in the scaled image will be a bilinear interpolation
 * of a 2x2 pixel region from the original image, with each of the H/S/L/A channels
 * processed individually. Interpolate over the x-axis before the y-axis.
 *
 * Since interpolation will be the exact average between exactly two pixels, then
 * the Hue channel should be averaged over the shortest arc between the two values.
 * e.g. The average of H_1 = 10 and H_2 = 320 is H_avg = 345 and NOT 165.
 * In the case of two diametric hues being averaged, e.g. 10 and 190, the average will
 * have the smaller value, i.e. 100 and NOT 280.
 * 
 * @pre referenceimg width and height are both even
 */
HSLAPixel QuarterColorPicker::operator()(PixelPoint p)
{
    // Replace the line below with your implementation

    // int px = p.x % referenceimg.width();
    // int py = p.y % referenceimg.height();

    // // return HSLAPixel();
    // return *referenceimg.getPixel(px, py);

    unsigned int halfWidth = referenceimg.width() / 2;
    unsigned int halfHeight = referenceimg.height() / 2;

    unsigned int x = (p.x % halfWidth) * 2;
    unsigned int y = (p.y % halfHeight) * 2;

    HSLAPixel* tl = referenceimg.getPixel(x, y);
    HSLAPixel* tr = referenceimg.getPixel(x + 1, y);
    HSLAPixel* bl = referenceimg.getPixel(x, y + 1);
    HSLAPixel* br = referenceimg.getPixel(x + 1, y + 1);

    // tl and tr hue average
    double tlradians = tl->h * PI / 180.0;
    double trradians = tr->h * PI / 180.0;

    // Convert to Cartesian coordinates.
    double tlcartx = std::cos(tlradians), tlcarty = std::sin(tlradians);
    double trcartx = std::cos(trradians), trcarty = std::sin(trradians);

    // Average the coordinates.
    double taverageX = (tlcartx + trcartx) / 2.0;
    double taverageY = (tlcarty + trcarty) / 2.0;

    // Convert back to polar coordinates.
    double taveHue = std::atan2(taverageY, taverageX) * 180.0 / PI;
    
    // atan2 returns a value in the range -180 to 180, we want 0 to 360.
    if (taveHue < 0) {
        taveHue += 360.0;
    }

    // bl and br hue average
    double blradians = bl->h * PI / 180.0;
    double brradians = br->h * PI / 180.0;

    // Convert to Cartesian coordinates.
    double blcartx = std::cos(blradians), blcarty = std::sin(blradians);
    double brcartx = std::cos(brradians), brcarty = std::sin(brradians);

    // Average the coordinates.
    double baverageX = (blcartx + brcartx) / 2.0;
    double baverageY = (blcarty + brcarty) / 2.0;

    // Convert back to polar coordinates.
    double baveHue = std::atan2(baverageY, baverageX) * 180.0 / PI;
    
    // atan2 returns a value in the range -180 to 180, we want 0 to 360.
    if (baveHue < 0) {
        baveHue += 360.0;
    }

    // top and bottom hue average
    double radTop = taveHue * PI / 180.0;
    double radBot = baveHue * PI / 180.0;

    // Convert to Cartesian coordinates.
    double cartTopX = std::cos(radTop), cartTopY = std::sin(radTop);
    double cartBotX = std::cos(radBot), cartBotY = std::sin(radBot);

    // Average the coordinates.
    double averageX = (cartTopX + cartBotX) / 2.0;
    double averageY = (cartTopY + cartBotY) / 2.0;

    // Convert back to polar coordinates.
    double aveHue = std::atan2(averageY, averageX) * 180.0 / PI;
    
    // atan2 returns a value in the range -180 to 180, we want 0 to 360.
    if (aveHue < 0) {
        aveHue += 360.0;
    }

    double aveSat = (tl->s + tr->s + bl->s + br->s) / 4.0;
    double aveLum = (tl->l + tr->l + bl->l + br->l) / 4.0;
    double aveAlp = (tl->a + tr->a + bl->a + br->a) / 4.0;

    // return HSLAPixel();
    return HSLAPixel(aveHue, aveSat, aveLum, aveAlp);
}

/**
 * Add your private QuarterColorPicker function implementations below
 */


// double QuarterColorPickerPrivate::sin(double radian) {
//     double term = radian, sum = term;
//     int i = 1;
//     while (abs(term) > 1e-10) {
//         term *= -radian * radian / (2 * i * (2 * i + 1));
//         sum += term;
//         i++;
//     }
//     return sum;
// }

// double QuarterColorPickerPrivate::cos(double radian) {
//     return sin(PI / 2 - radian);
// }

// double QuarterColorPickerPrivate::atan(double x) {
//     double term = x, sum = term;
//     int i = 1;
//     while (abs(term) > 1e-10) {
//         term *= -x * x / (2 * i + 1);
//         sum += term;
//         i++;
//     }
//     return sum;
// }


// double QuarterColorPickerPrivate::atan2(double y, double x) {
//     if (x > 0) {
//         return atan(y / x);
//     } else if (y >= 0 && x < 0) {
//         return atan(y / x) + PI;
//     } else if (y < 0 && x < 0) {
//         return atan(y / x) - PI;
//     } else if (y > 0 && x == 0) {
//         return PI / 2;
//     } else if (y < 0 && x == 0) {
//         return -PI / 2;
//     } else {
//         return 0;  // x = y = 0
//     }
// }

// double QuarterColorPickerPrivate::averageHue(double left, double right) {
//     double lradians = left * PI / 180.0;
//     double rradians = right * PI / 180.0;
    
//     // Convert to Cartesian coordinates.
//     double lcartx = cos(lradians), lcarty = sin(lradians);
//     double rcartx = cos(rradians), rcarty = sin(rradians);

//     // Average the coordinates.
//     double averageX = (lcartx + rcartx) / 2.0;
//     double averageY = (lcarty + rcarty) / 2.0;

//     // Convert back to polar coordinates.
//     double aveHue = atan2(averageY, averageX) * 180.0 / PI;
    
//     // atan2 returns a value in the range -180 to 180, we want 0 to 360.
//     if (aveHue < 0) {
//         aveHue += 360.0;
//     }

//     return aveHue;
// }
