//
//  AFLineView.h
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

#import <UIKit/UIKit.h>

typedef enum {
	AFLineViewOrientationHorizontal,
	AFLineViewOrientationVertical
} AFLineViewOrientation;

/** 
 The recommended height is `2.0` points if you are using the inset and `1.0` if you are not.
 The inset is drawn under the line if `insetColor` is not `nil`.
 */
@interface AFLineView : UIView {
	
@private
	UIColor *_lineColor;
	UIColor *_insetColor;
	CGFloat _dashPhase;
	NSArray *_dashLengths;
	AFLineViewOrientation _lineOrientation;
}

///--------------------
/// @name Drawing Lines
///--------------------

/**
 The primary color of the line.
 
 The default is `[UIColor grayColor]`.
 */
@property (nonatomic, retain) UIColor* lineColor;

/**
 The color of the line inset.
 
 The default is 50% opaque white.
 */
@property (nonatomic, retain) UIColor* insetColor;

/**
 The line orientation.
 
 The default is AFLineViewOrientationHorizontal.
 */
@property (nonatomic, assign) AFLineViewOrientation lineOrientation;

///---------------------
/// @name Drawing Dashes
///---------------------

/**
 A float that specifies how far into the dash pattern the line starts, in points.
 
 For example, passing a value of 3 means the line is drawn with the dash pattern starting at 3 points from its
 beginning. Passing a value of 0 draws a line starting with the beginning of a dash pattern.
 
 The default is `0.0`.
 */
@property (nonatomic, assign) CGFloat dashPhase;

/**
 An array of values that specify the lengths of the painted segments and unpainted segments, respectively, of the
 dash pattern—or `nil` for no dash pattern.
 
 For example, passing an array with the values [2,3] sets a dash pattern that alternates between a 2 point long painted
 segment and a 3 point long unpainted segment. Passing the values [1,3,4,2] sets the pattern to a 1 point painted
 segment, a 3 point unpainted segment, a 4 oiunt painted segment, and a 2 point unpainted segment.
 
 The default is `nil`.
 */
@property (nonatomic, copy) NSArray* dashLengths;

@end
