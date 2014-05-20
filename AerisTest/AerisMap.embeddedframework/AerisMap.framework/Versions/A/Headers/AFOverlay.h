//
//  AFOverlay.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 5/30/12.
//  Copyright (c) 2012 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "AFOverlayType.h"
#import "AFOverlayGroup.h"

@protocol AFOverlay <MKOverlay>

@property (nonatomic, readonly) AFOverlayType overlayType;
@property (nonatomic, readonly) AFOverlayGroup overlayGroup;
@property (nonatomic, readonly) AFOverlayGroupType overlayGroupType;
@property (nonatomic) NSUInteger expires;
@property (nonatomic, copy) NSString *timestamp;
@property (nonatomic, retain) NSDate *datetime;
@property (nonatomic, readonly) BOOL animates;
@property (nonatomic, retain) UIImage *legendImage;
//@property (nonatomic, assign) NSObject<AFTileOverlayDelegate> *delegate;

@optional

@property (nonatomic, readonly) NSString *animationUrlPath;

@end

@interface AFOverlay : NSObject <AFOverlay> {
	AFOverlayType _overlayType;
	AFOverlayGroup _overlayGroup;
	AFOverlayGroupType _overlayGroupType;
	NSUInteger _interval;
	NSUInteger _expires;
	NSString *_timestamp;
	NSDate *_datetime;
	UIImage *_legendImage;
	BOOL _animates;
}

/**
 The type of tile overlay for this instance.
 */
@property (nonatomic, readonly) AFOverlayType overlayType;

/**
 The overlay group this tile overlay belongs to.
 */
@property (nonatomic, readonly) AFOverlayGroup overlayGroup;

/**
 The type group this overlay belongs to.
 */
@property (nonatomic, readonly) AFOverlayGroupType overlayGroupType;

/**
 The expiration time, in seconds, for data loaded into this overlay.
 */
@property (nonatomic, assign) NSUInteger expires;

/**
 Defines whether or not this overlay supports animations.
 */
@property (nonatomic, readonly) BOOL animates;

/**
 The archive interval to be used for this overlay.
 
 By default, the latest is used (0), but when doing animated overlays each instance would have a different
 interval value based on its index in the animation.
 */
@property (nonatomic, assign) NSUInteger interval;

/**
 The timestamp used for this overlay.
 */
@property (nonatomic, copy) NSString *timestamp;

@property (nonatomic, retain) NSDate *datetime;

/**
 The image to display as the legend for this overlay. No legend will be displayed if this value is nil.
 */
@property (nonatomic, retain) UIImage *legendImage;

@end
