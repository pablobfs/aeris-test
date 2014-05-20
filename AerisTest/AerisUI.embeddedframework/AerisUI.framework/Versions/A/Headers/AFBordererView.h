//
//  AFBordererView.h
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

#import <UIKit/UIKit.h>


/**
 Simple UIView for drawing top and bottom borders with optional insets in a view.
 */
@interface AFBordererView : UIView {
	
@private
	UIColor* _topBorderColor;
	UIColor* _topInsetColor;
	UIColor* _bottomInsetColor;
	UIColor* _bottomBorderColor;
}

///-----------------------------
/// @name Drawing the Top Border
///-----------------------------

/**
 The top border color. The default is `nil`.
 
 @see bottomBorderColor
 */
@property (nonatomic, retain) UIColor* topBorderColor;

/**
 The top inset color. The default is `nil`.
 
 @see bottomInsetColor
 */
@property (nonatomic, retain) UIColor* topInsetColor;

///--------------------------------
/// @name Drawing the Bottom Border
///--------------------------------

/**
 The bottom inset color. The default is `nil`.
 
 @see topInsetColor
 */
@property (nonatomic, retain) UIColor* bottomInsetColor;

/**
 The bottom border color. The default is `nil`.
 
 @see topBorderColor
 */
@property (nonatomic, retain) UIColor* bottomBorderColor;

@end

