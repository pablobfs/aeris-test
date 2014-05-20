//
//  AFOverlayManagerDelegate.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/26/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AFOverlayManager, AFOverlay;

@protocol AFOverlayManagerDelegate <NSObject>

@optional
/**
 Tells the delegate the overlay manager added an overlay to the map.
 
 @param overlayManager The `AFOverlayManager` instance that added the overlay to the map.
 @param overlayName The overlay code that was added.
 @see AFTileOverlay for the possible tile overlay codes.
 @see AFPointDataOverlay for the possible point data overlay codes.
 */
- (void)overlayManager:(AFOverlayManager *)overlayManager didAddOverlayOfName:(NSString *)overlayName;

- (void)overlayManager:(AFOverlayManager *)overlayManager didAddOverlay:(AFOverlay *)overlay;

/**
 Tells the delegate the overlay manager removed an overlay from the map.
 
 @param overlayManager The `AFOverlayManager` instance that removed the overlay from the map.
 @param overlayName The overlay code that was added.
 @see AFTileOverlay for the possible tile overlay codes.
 @see AFPointDataOverlay for the possible point data overlay codes.
 */
- (void)overlayManager:(AFOverlayManager *)overlayManager didRemoveOverlayOfName:(NSString *)overlayName;

- (void)overlayManager:(AFOverlayManager *)overlayManager didRemoveOverlay:(AFOverlay *)overlay;

- (void)overlayManager:(AFOverlayManager *)overlayManager didFinishLoadingDataForOverlayWithName:(NSString *)overlayName;

- (void)overlayManager:(AFOverlayManager *)overlayManager didFailLoadingDataForOverlayWithName:(NSString *)overlayName withError:(NSError *)error;

/**
 Tells the delegate the overlay manager enabled animations for the current overlay on the map.
 This is useful in determining when to enable or show custom animation controls within custom applications.
 
 @param overlayManager The `AFOverlayManager` instance that enabled animations.
 */
- (void)overlayManagerDidEnableAnimations:(AFOverlayManager *)overlayManager;

/**
 Tells the delegate the overlay manager disabled animations for the current overlay on the map or when all overlays are
 removed from the map. This is useful in determining when to disable or hide custom animation controls within
 custom applications.
 
 @param overlayManager The `AFOverlayManager` instance that added the overlay to the map.
 */
- (void)overlayManagerDidDisableAnimations:(AFOverlayManager *)overlayManager;

/**
 Tells the delegate when the overlay manager started animating the currently active overlay on the map.
 
 @param overlayManager The `AFOverlayManager` instance that started animating the overlay.
 */
- (void)overlayManagerDidStartAnimatingOverlays:(AFOverlayManager *)overlayManager;

/**
 Tells the delegate when the overlay manager stopped animating the currently active overlay on the map.
 
 @param overlayManager The `AFOverlayManager` instance that stopped aniating the overlay.
 */
- (void)overlayManagerDidStopAnimatingOverlays:(AFOverlayManager *)overlayManger;

- (void)overlayManager:(AFOverlayManager *)overlayManager didPauseAnimationOnFrame:(NSUInteger)frame;

/**
 Tells the delegate when the overlay manager started loading images for the currently active overlay.
 
 @param overlayManager The `AFOverlayManager` instance that started requesting images.
 @param overlayName The overlay code that was added.
 @see AFTileOverlay for the possible tile overlay codes.
 @see AFPointDataOverlay for the possible point data overlay codes.
 */
- (void)overlayManager:(AFOverlayManager *)overlayManager didStartLoadingAnimationOfName:(NSString *)overlayName;

/**
 Tells the delegate when the overlay manager finished loading images for the currently active overlay.
 
 @param overlayManager The `AFOverlayManager` instance that finished requesting images.
 @param overlayName The overlay code associated with the animation.
 @see AFTileOverlay for the possible tile overlay codes.
 @see AFPointDataOverlay for the possible point data overlay codes.
 */
- (void)overlayManager:(AFOverlayManager *)overlayManager didFinishLoadingAnimationOfName:(NSString *)overlayName;

/**
 Tells the delegate when the overlay manager failed loading images for the currently active overlay.
 
 @param overlayManager The `AFOverlayManager` instance that failed requesting images.
 @param overlayName The overlay code associated with the animation.
 @see AFTileOverlay for the possible tile overlay codes.
 @see AFPointDataOverlay for the possible point data overlay codes.
 */
- (void)overlayManager:(AFOverlayManager *)overlayManager didFailLoadingAnimationOfName:(NSString *)overlayName;

/**
 Tells the delegate when the loading process for animation imagery has been updated.
 This is typically used for updating a custom progress loader displayed on top of the map view or with the map controls.
 
 @param overlayManager The `AFOverlayManager` instance that updated the loading process.
 @param progress The current progress of the loading process from 0 to 1.
 */
- (void)overlayManager:(AFOverlayManager *)overlayManager didUpdateAnimationLoadProgress:(NSNumber *)progress;

/**
 Tells the delegate when the current frame during an animation changed.
 This is typically used to update the current time for the overlay or animation frame during an animation process.
 
 @param overlayManager The `AFOverlayManager` instance that updated the animation frame.
 @param date The timestamp of the current frame in the animation.
 */
- (void)overlayManager:(AFOverlayManager *)overlayManager didUpdateAnimationFrameForDate:(NSDate *)date;
- (void)overlayManager:(AFOverlayManager *)overlayManager didUpdateAnimationFrame:(NSUInteger)frame forDate:(NSDate *)date totalIntervals:(NSUInteger)totalIntervals;

/**
 Requests the map container's frame to use for the animation layer from the delegate.
 */
- (CGRect)overlayManagerFrameForMapContainer:(AFOverlayManager *)overlayManager;

@end
