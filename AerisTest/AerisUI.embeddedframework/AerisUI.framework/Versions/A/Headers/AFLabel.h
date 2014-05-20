//
//  AFLabel.h
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
#import "UIView+AFAdditions.h"

/**
 The vertical alignment of text within a label.
 */
typedef enum {
	/** Aligns the text vertically at the top in the label (the default). */
	AFLabelVerticalTextAlignmentTop = UIControlContentVerticalAlignmentTop,
	
	/** Aligns the text vertically in the center of the label. */
	AFLabelVerticalTextAlignmentMiddle = UIControlContentVerticalAlignmentCenter,
	
	/** Aligns the text vertically at the bottom in the label. */
	AFLabelVerticalTextAlignmentBottom = UIControlContentVerticalAlignmentBottom
} AFLabelVerticalTextAlignment;

/**
 Simple label subclass that adds the ability to align your text to the top or bottom.
 */
@interface AFLabel : UILabel {
	
@private
	AFLabelVerticalTextAlignment _verticalTextAlignment;
	UIEdgeInsets _textEdgeInsets;
}

/**
 The vertical text alignment of the receiver.
 
 The default is `AFLabelVerticalTextAlignmentMiddle` to match `UILabel`.
 */
@property (nonatomic, assign) AFLabelVerticalTextAlignment verticalTextAlignment;

/**
 The edge insets of the text.
 
 The default is `UIEdgeInsetsZero` so it behaves like `UILabel` by default.
 */
@property (nonatomic, assign) UIEdgeInsets textEdgeInsets;

/*
 * Returns a new autoreleased UILabel instance based on the passed formatting values
 */
+ (AFLabel *)labelWithFont:(UIFont *)font color:(UIColor *)color align:(UITextAlignment)align backgroundColor:(UIColor *)bgcolor minFontSize:(NSUInteger)fontSize;

/**
 * Allows a label to have a variable multiline height but a fixed width.
 */
- (void)sizeToFitFixedWidth:(CGFloat)fixedWidth;

/**
 * Resizes the size of the UILabel so that just the text will fit within.
 */
- (void)sizeToFitText;

- (void)scaleToView:(UIView *)view orientation:(AFViewOrientation)orientation;

@end
