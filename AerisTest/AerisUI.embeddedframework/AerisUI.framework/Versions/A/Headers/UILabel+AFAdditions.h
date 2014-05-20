//
//  UILabel+AFAdditions.h
//  Aeris
//	$Id$
//
//  Created by Nicholas Shipes on 7/29/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//


@interface UILabel (AFAdditions)

/**
 Returns a new autoreleased UILabel instance based on the passed formatting values.
 
 @param font The UIFont instance to use as the font type
 @param color A UIColor instance to apply to the text
 @param align An enumerated UITextAlignment value
 @param bgcolor A UIColor instance to use as the background fill color for the UILabel
 @param fontSize An integer indicating the minimum font size allowed for resizing; set to `nil` for no minimum value
 
 @return A new autoreleased UILabel instance with the applied properties.
 */
+ (UILabel *)labelWithFont:(UIFont *)font color:(UIColor *)color align:(UITextAlignment)align backgroundColor:(UIColor *)bgcolor minFontSize:(NSUInteger)fontSize;

@end
