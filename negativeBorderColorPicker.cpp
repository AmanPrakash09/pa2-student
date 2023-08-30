/**
 * @file negativeBorderColorPicker.cpp
 * @description Implements the NegativeBorderColorPicker constructor and () function
 *              for CPSC 221 2023S PA2
 *
 *              THIS FILE WILL BE SUBMITTED
 */

#include "negativeBorderColorPicker.h"
#include <math.h>

NegativeBorderColorPicker::NegativeBorderColorPicker(PNG& inputimg, PixelPoint src_px, unsigned int width, double tol)
{
    // Complete your implementation below

    referenceimg = inputimg;
    source_px = src_px;
    borderwidth = width;
    tolerance = tol;

}

/**
 * Picks the color for pixel (x, y).
 *
 * Leaves a pixel unchanged if it is not on the border of a fill region
 *
 * If a pixel is on the border of a fill region, change it to the "negative"
 * of the original colour value in the Hue and Luminance channels.
 * Saturation and Alpha should remain unchanged.
 * Based on your understanding of HSL colour space from Lab_intro,
 * think about what would be an appropriate "negative" transformation for the
 * Hue and Luminance channels.
 *
 * Hint: a pixel is on the border of a fill region, if it is within "width"
 * pixels of a pixel which is NOT in the fill region!
 * 
 * Also: the border of the image is considered to be a border of the fill region.
 */
HSLAPixel NegativeBorderColorPicker::operator()(PixelPoint p)
{
    // Replace the line below with your implementation

    // PNG referenceimg;
    // PixelPoint source_px;
    // unsigned int borderwidth;
    // double tolerance;

    // step 1: iterate through pixels within given "border"
    // step 2: check if pixel is within the image dimensions
    // step 3: calculate distance and check if it is greater than tolerance
    // step 4: convert pixel

    HSLAPixel* pixel = referenceimg.getPixel(p.x, p.y);

    for (int dx = -borderwidth; dx <= int(borderwidth); ++dx) {
        for (int dy = -borderwidth; dy <= int(borderwidth); ++dy) {
            // check if within image
            // if (p.x + dx >= referenceimg.width() || p.y + dy >= referenceimg.width()) {
            //     continue;
            // }
            // if (int(p.x) + dx >= 0 && p.x + dx < referenceimg.width() && 
            //     int(p.y) + dy >= 0 && p.y + dy < referenceimg.height() &&
            //     dx*dx + dy*dy <= int(borderwidth * borderwidth)) {
            if (dx*dx + dy*dy <= int(borderwidth * borderwidth)) {

                    // (width>0 && height>0 && x>=0 && y>=0 && x<width && y<height)
                
                HSLAPixel* neighbor = referenceimg.getPixel(p.x + dx, p.y + dy);

                double distance = source_px.color.distanceTo(*neighbor);

                if ((distance > tolerance) ||
                    dx + p.x >= referenceimg.width() ||
                    dy + p.y >= referenceimg.height()) {

                    HSLAPixel negative = *pixel;

                    double hue = pixel->h;
                    double lum = pixel->l;

                    if (hue > 180.0) {
                        negative.h = hue - 180.0;
                    }
                    else {
                        negative.h = hue + 180.0;
                    }
                    negative.l = (1 - lum);

                    return negative;
                }
            }
        }
    }

    return *pixel;
}

/**
 * Add your private QuarterColorPicker function implementations below
 */
