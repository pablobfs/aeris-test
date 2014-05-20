//
//  UIImage+AFAdditions.h
//  AerisUI
//	$Id$
//
//  Created by Nicholas Shipes on 4/30/12.
//  Copyright (c) 2012 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (AFAdditions)

+ (UIImage *)imageNamedSmart:(NSString *)name;

+ (UIImage *)imageWithImage:(UIImage *)sourceImage scaledToSizeWithSameAspectRatio:(CGSize)targetSize;

+ (UIImage *)imageWithImage:(UIImage *)sourceImage newSize:(CGSize)targetSize;

@end
