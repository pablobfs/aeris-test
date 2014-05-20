//
//  AFLayout.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/2/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface AFLayout : NSObject {
    
}

/**
 Positions and sizes an array of subviews inside another view.
 
 @param subviews A NSArray of subviews to layout
 @param view The UIView instance to layout subviews within
 */
- (CGSize)layoutSubviews:(NSArray*)subviews forView:(UIView*)view;

/**
 Positions an array of subviews in columns equally across a width.
 
 @param subviews A NSArray of subviews to layout
 @param width The width to distribute and position the subviews across
 */
- (CGSize)layoutSubviews:(NSArray*)subviews forWidth:(CGFloat)width;

/**
 Positions an array of subviews in rows equally across a height.
 
 @param subviews A NSArray of subviews to layout
 @param height The height to distribute and position the subviews across
 */
- (CGSize)layoutSubviews:(NSArray *)subviews forHeight:(CGFloat)height;

@end
