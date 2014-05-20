//
//  UIColor+AFAdditions.h
//  AerisUI
//	$Id$
//
//  Created by Nicholas Shipes on 5/14/12.
//  Copyright (c) 2012 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (AFAdditions)

+ (UIColor *)colorWithHexString:(NSString *)hexString;

+ (UIColor *)colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

+ (CGFloat)colorComponentFrom:(NSString *)string start:(NSUInteger)start length:(NSUInteger)length;

@end
