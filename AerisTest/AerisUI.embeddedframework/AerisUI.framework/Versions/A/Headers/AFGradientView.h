//
//  AFGradientView.h
//  AerisSamples
//  $Id$
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
//  Modified and implemented by Nicholas Shipes on 7/31/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//


#import "AFBordererView.h"

/**
 The direction the gradient.
 */
typedef enum {
	/** The gradient is horizontal. */
	AFGradientViewDirectionHorizontal,
	
	/** The gradient is vertical. */
	AFGradientViewDirectionVertical
} AFGradientViewDirection;

/**
 Simple `UIView` wrapper for `CGGradient`.
 */
@interface AFGradientView : AFBordererView {
	
@private
	
	NSArray *_colors;
	NSArray *_locations;
	AFGradientViewDirection _direction;
    
	CGGradientRef _gradient;
}

///---------------------------
/// @name Drawing the Gradient
///---------------------------

/**
 An array of `UIColor` objects used to draw the gradient. If the value is `nil`, the `backgroundColor` will be drawn
 instead of a gradient.
 
 The default is `nil`.
 */
@property (nonatomic, copy) NSArray *colors;

/**
 An optional array of `NSNumber` objects defining the location of each gradient stop.
 
 The gradient stops are specified as values between `0` and `1`. The values must be monotonically
 increasing. If `nil`, the stops are spread uniformly across the range. Defaults to `nil`.
 */
@property (nonatomic, copy) NSArray *locations;

/**
 The direction of the gradient.
 
 The default is `AFGradientViewDirectionHorizontal`.
 */
@property (nonatomic, assign) AFGradientViewDirection direction;

@end
