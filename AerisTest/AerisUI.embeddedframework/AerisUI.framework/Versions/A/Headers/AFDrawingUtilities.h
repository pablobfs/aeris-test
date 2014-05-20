//
//  AFDrawingUtilities.m
//  AerisSamples
//	$Id$
//	
//	Original utilities distributed as part of SSToolkit (original license below).
//	https://github.com/samsoffes/sstoolkit/tree/master/SSToolkit
//	
//	Copyright (c) 2010 Sam Soffes
//	
//	Permission is hereby granted, free of charge, to any person obtaining
//	a copy of this software and associated documentation files (the
//	"Software"), to deal in the Software without restriction, including
//	without limitation the rights to use, copy, modify, merge, publish,
//	distribute, sublicense, and/or sell copies of the Software, and to
//	permit persons to whom the Software is furnished to do so, subject to
//	the following conditions:
//	
//	The above copyright notice and this permission notice shall be
//	included in all copies or substantial portions of the Software.
//	
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
//	LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//	OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//	WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//	
//	
//
//  Modified and implemented by Nicholas Shipes on 7/29/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef AFDRAWINGUTILITIES
#define AFDRAWINGUTILITIES

///-----------------------------------
/// @name Degree and Radian Conversion
///-----------------------------------

/**
 A macro that converts a number from degress to radians.
 @param d number in degrees
 @return The number converted to radians.
 */
#define DEGREES_TO_RADIANS(d) ((d) * 0.0174532925199432958f)

/**
 A macro that converts a number from radians to degrees.
 @param r number in radians
 @return The number converted to degrees.
 */
#define RADIANS_TO_DEGREES(r) ((r) * 57.29577951308232f)

#endif

/**
 Limits a float to the `min` or `max` value. The float is between `min` and `max` it will be returned unchanged.
 
 @param f The float to limit.
 @param min The minumum value for the float.
 @param max The minumum value for the float.
 @return A float limited to the `min` or `max` value.
 */
extern CGFloat AFFLimit(CGFloat f, CGFloat min, CGFloat max);

///-----------------------------
/// @name Rectangle Manipulation
///-----------------------------

extern CGRect CGRectSetX(CGRect rect, CGFloat x);
extern CGRect CGRectSetY(CGRect rect, CGFloat y);
extern CGRect CGRectSetWidth(CGRect rect, CGFloat width);
extern CGRect CGRectSetHeight(CGRect rect, CGFloat height);
extern CGRect CGRectSetOrigin(CGRect rect, CGPoint origin);
extern CGRect CGRectSetSize(CGRect rect, CGSize size);
extern CGRect CGRectSetZeroOrigin(CGRect rect);
extern CGRect CGRectSetZeroSize(CGRect rect);
extern CGSize CGSizeAspectScaleToSize(CGSize size, CGSize toSize);
extern CGRect CGRectAddPoint(CGRect rect, CGPoint point);

///---------------------------------
/// @name Drawing Rounded Rectangles
///---------------------------------

extern void AFDrawRoundedRect(CGContextRef context, CGRect rect, CGFloat cornerRadius);

///-------------------------
/// @name Creating Gradients
///-------------------------

extern CGGradientRef AFCreateGradientWithColors(NSArray* colors);
extern CGGradientRef AFCreateGradientWithColorsAndLocations(NSArray* colors, NSArray* locations);

///------------------------
/// @name Drawing Gradients
///------------------------

extern void AFDrawGradientInRect(CGContextRef context, CGGradientRef gradient, CGRect rect);
