//
//  AnimationControlView.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 6/24/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AFAnimationControlView : UIView

/**
 The `UIPageControl` instance for the control view.
 */
@property (nonatomic, retain) UIPageControl *pageControl;

/**
 The next button for advancing the animation frame by one.
 */
@property (nonatomic, retain) UIButton *nextButton;

/**
 The previous button for shifting the animation frame back by one.
 */
@property (nonatomic, retain) UIButton *previousButton;

@end
