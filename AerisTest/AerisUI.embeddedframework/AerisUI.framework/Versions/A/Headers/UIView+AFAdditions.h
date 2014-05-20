//
//  UIView+AFAdditions.h
//  Aeris
//  $Id$
//
//  Created by Nick Shipes on 7/31/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef UIViewAutoresizingFlexibleSize
	#define UIViewAutoresizingFlexibleSize UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight
#endif

#ifndef UIViewAutoresizingFlexibleMargins
	#define UIViewAutoresizingFlexibleMargins UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin
#endif

/**
 * The relative positioning configuration.
 */
typedef enum {
	AFViewPositionNull,
    AFViewPositionTop,
    AFViewPositionMiddle,
    AFViewPositionBottom,
    AFViewPositionLeft,
    AFViewPositionCenter,
    AFViewPositionCenterLeft,
    AFViewPositionCenterRight,
    AFViewPositionRight,
    AFViewPositionTopLeft,
    AFViewPositionTopCenter,
    AFViewPositionTopRight,
    AFViewPositionMiddleLeft,
    AFViewPositionMiddleRight,
    AFViewPositionBottomLeft,
    AFViewPositionBottomCenter,
    AFViewPositionBottomRight
} AFViewPosition;

typedef enum {
    AFViewOrientationOuter,
    AFViewOrientationInner,
	AFViewOrientationHorizontal,
	AFViewOrientationVertical
} AFViewOrientation;

@interface UIView (AFAdditions)

@property (nonatomic) CGPoint frameOrigin;
@property (nonatomic) CGSize frameSize;

@property (nonatomic) CGFloat frameX;
@property (nonatomic) CGFloat frameY;

// Setting these modifies the origin but not the size.
@property (nonatomic) CGFloat frameRight;
@property (nonatomic) CGFloat frameBottom;

@property (nonatomic) CGFloat frameWidth;
@property (nonatomic) CGFloat frameHeight;

@property (nonatomic) CGFloat left;
@property (nonatomic) CGFloat right;
@property (nonatomic) CGFloat top;
@property (nonatomic) CGFloat bottom;

///-------------------------
/// @name Hiding and Showing
///-------------------------

/**
 Sets the `alpha` value of the receiver to `0.0`.
 */
- (void)hide;

/**
 Sets the `alpha` value of the receiver to `1.0`.
 */
- (void)show;

/**
 Determines the X position of the view relative to the screen.
 */
- (CGFloat)screenX;

/**
 Determines the Y position of the view relative to the screen.
 */
- (CGFloat)screenY;

/**
 Returns the frame of the screen view.
 */
- (CGRect)screenFrame;

///-------------------------------
/// @name Positioning and Resizing
///-------------------------------

/**
 Handles relative positioning between two view instances.
 */
- (void)positionRelativeToView:(UIView*)targetView position:(AFViewPosition)position orientation:(AFViewOrientation)orientation;
- (void)positionRelativeToView:(UIView*)targetView alignX:(AFViewPosition)alignX alignY:(AFViewPosition)alignY orientation:(AFViewOrientation)orientation;
- (void)positionRelativeToView:(UIView *)targetView alignX:(AFViewPosition)alignX orientation:(AFViewOrientation)orientation;
- (void)positionRelativeToView:(UIView *)targetView alignY:(AFViewPosition)alignY orientation:(AFViewOrientation)orientation;

/**
 * Returns the right and bottom offsets from a view instance.
 */
- (CGPoint)offsetFromView:(UIView*)otherView;

///----------------
/// @name Centering
///----------------

// Methods for centering.
- (void)addCenteredSubview:(UIView*)subview;
- (void)moveToCenterOfSuperview;
- (void)centerVerticallyInSuperview;
- (void)centerHorizontallyInSuperview;

///----------------
/// @name Debugging
/// ---------------

/**
 Utility for debugging a view by applying a colored stroke around its bounds.
 */
- (void)setDebug:(BOOL)val;

@end
