//
//  AFView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/2/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface AFView : UIView {
    CGFloat _padding;
	CGFloat _margin;
	UIView* _background;
	
	CGSize _defaultSize;
}

/**
 The internal padding within the view.
 */
@property (nonatomic) CGFloat padding;

/**
 The external margin around this view.
 */
@property (nonatomic) CGFloat margin;

/**
 The view to use as the background for this view.
 */
@property (nonatomic, retain) UIView* background;

///---------------------
/// @name Content Region
///---------------------

/**
 The inner content width of the view.
 */
@property (nonatomic) CGFloat innerWidth;

/**
 The inner content height of the view.
 */
@property (nonatomic) CGFloat innerHeight;


@end
