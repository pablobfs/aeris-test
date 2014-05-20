//
//  AFMapControlView.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 4/20/12.
//  Copyright (c) 2012 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AerisUI.h>

@interface AFMapControlView : AFView {
	UIView *baseView_;
	UIButton *playButton_;
	UIButton *pauseButton_;
	AFCircularProgressView *progressView_;
	AFLabel *overlayLabel_;
	AFLabel *datetimeLabel_;
	
	NSUInteger minWidth_;
	NSUInteger spacing_;
	CGFloat radius_;
	CAShapeLayer *baseShape_;
	CGPathRef pathRef_;
	
	BOOL _hasResizedForLoading;
}

/**
 The button used for starting the overlay animations.
 */
@property (nonatomic, retain) UIButton *playButton;

/**
 The button used for stopping the overlay animations.
 */
@property (nonatomic, retain) UIButton *pauseButton;

/**
 The progress view used for displaying the loading progress for animation frames.
 */
@property (nonatomic, retain) AFCircularProgressView *progressView;

/**
 The name to display for the currently active overlay.
 */
@property (nonatomic, retain) NSString *overlayName;

/**
 The date/time string to display for the currently active overlay or animation frame.
 */
@property (nonatomic, retain) NSString *datetime;

/**
 Notifies the internal controls that an animation has started playing.
 */
- (void)animationHasStarted:(NSString *)overlayName;

/**
 Notifies the internal controls that an animation has stopped playing.
 */
- (void)animationHasEnded;

/**
 Notifies the internal controls that an animation has started loading.
 */
- (void)animationHasStartedLoading:(NSString *)overlayName;

/**
 Notifies the internal controls that an animation has finished loading.
 */
- (void)animationHasFinishedLoading:(NSString *)overlayName;

/**
 Notifies the internal controls that an overlay was removed from the current map view.
 */
- (void)overlayWasRemoved;

@end
