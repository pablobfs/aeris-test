//
//  AFWeatherMap.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/1/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import <AerisUI/AerisUI.h>
#import <AerisMap/AFOverlayType.h>
#import <AerisMap/AFLegend.h>
#import <AerisMap/AFMapControlView.h>
#import <AerisMap/AFAnimationControlView.h>
#import <AerisMap/AFAnnotation.h>
#import <AerisMap/AFOverlayManagerDelegate.h>
#import <AerisMap/AFOverlayType.h>
#import <AerisMap/AFPointDataType.h>
#import <AerisMap/AFPolygonDataType.h>

@class AFFlexibleCalloutAnnotation;
@class AFFlexibleCalloutAnnotationView;
@class AFTapPointAnnotation;
@protocol AFWeatherMapDelegate;

@interface AFWeatherMap : NSObject <AFOverlayManagerDelegate, AFObjectLoaderDelegate, AFCalloutViewDelegate, MKMapViewDelegate, UIGestureRecognizerDelegate> {
    MKMapView *_mapView;
	AFLegend *_legend;
	AFMapControlView *_controlView;
	AFCircularProgressView *_progressView;
	BOOL _cancelTouches;
	UITouch *_mapTouch;
	NSObject<AFWeatherMapDelegate> *_delegate;
	
	CLLocationCoordinate2D _lastCenterCoordinate;
	NSUInteger _lastZoomLevel;
	MKAnnotationView *_selectedAnnotationView;
	AFFlexibleCalloutAnnotation *_calloutAnnotation;
	AFFlexibleCalloutAnnotationView *_calloutAnnotationView;
	AFAnnotation *_circularAnnotation;
	AFObservationsLoader *_obsLoader;
	AFPlacesLoader *_placeLoader;
	AFPlacesLoader *_citiesLoader;
	BOOL _adjustMapForLocation;
	
	BOOL _isAnimating;
	BOOL _didPauseAnimationForMapGesture;
}

/**
 The map view associated with this weather map object.
 */
@property (nonatomic, retain) MKMapView *mapView;

/**
 The view containing the map and all internal subviews, like legends, controls, etc.
 */
@property (nonatomic, retain) UIView *mapContainerView;

/**
 The map container's frame.
 */
@property (nonatomic, readonly) CGRect mapFrame;

/**
 The legend object associated with the map.
 */
@property (nonatomic, retain) AFLegend *legend;

/**
 The view containing the various map controls and overlay information, such as animation buttons, loading progress, 
 overlay name and overlay timestamp.
 **/
@property (nonatomic, retain) AFMapControlView *controlView;

/**
 The animation loading progress view.
 */
@property (nonatomic, retain) AFCircularProgressView *progressView;

/**
 The animation control view for stepping between animation frames.
 */
@property (nonatomic, retain) AFAnimationControlView *animControlView;

/**
 The current annotation used for displaying point data on the map.
 
 This is used primarily with the tap-and-hold feature for getting local weather conditions for any point on the map.
 */
@property (nonatomic, retain) AFAnnotation *pointAnnotation;

@property (nonatomic, retain) AFFlexibleCalloutAnnotation *calloutAnnotation;

/**
 The image overlay opacity from 0 to 1.
 */
@property (nonatomic, assign) CGFloat overlayAlpha;

/**
 The new animation speed to use in seconds. The minimum value allowed is 0.05 seconds.
 */
@property (nonatomic, assign) CGFloat animationSpeed;

/**
 Whether or not the weather map is animating the current tile overlay.
 */
@property (nonatomic, readonly) BOOL isAnimating;

/**
 The delegate object that receives notifications of certain events.
 */
@property (nonatomic, assign) NSObject<AFWeatherMapDelegate> *delegate;

/**
 Returns a dictionary of all the supported types of overlays broken out into their types (e.g., tile, point data, etc).
 
 This data is typically used when generating a menu or listing of the available map overlay options.
 @returns A dictionary of overlays currently supported by `AFWeatherMap`.
 */
+ (NSDictionary *)supportedOverlays;

/**
 Initializes a new weather map object and associates it with an MKMapView instance. This map view will be used for 
 adding and removing all weather overlays.
 
 @param mapView An MKMapView to associate with this weather map
 */
- (id)initWithMapView:(MKMapView *)mapView;

/**
 Centers the map view based on the coordinate of the `AFPlace` instance provided.
 
 @param place The `AFPlace` instance to use for centering the map.
 */
- (void)centerMapOnPlace:(AFPlace *)place;

/**
 Show or hide the animation control view.
 
 @param show Whether or not to show the animation control view.
 */
- (void)showAnimationControls:(BOOL)show;

///-------------------
/// @name Map Overlays
///-------------------

/**
 Toggles the map overlay on or off depending on its current state. If an overlay has not been created for the specified 
 type, one will be added to the map view as needed.
 
 @param overlayType The overlay type from the list of supported AFOverlayType layers
 */
- (void)toggleOverlayForType:(AFOverlayType)overlayType;

/**
 Displays the overlay for the specified type. If the overlay is already visible on the map, this method will do nothing.
 
 @param overlayType The overlay type from the list of supported AFOverlayType layers
 */
- (void)showOverlayForType:(AFOverlayType)overlayType;

/**
 Removes the overlay for the specified type from the map view. This method does nothing if the overlay does not exist 
 or has already been removed.
 
 @param overlayType The overlay type from the list of supported AFOverlayType layers
 */
- (void)hideOverlayForType:(AFOverlayType)overlayType;

/**
 Returns the current AFOverlay (image or tile) currently displayed on the map, or `nil` if there is no overlay currently displayed.
 */
- (AFOverlay *)currentOverlay;

/**
 Checks if the map view currently has an overlay for the specified type.
 
 @param overlayType The overlay type from the list of supported AFOverlayType layers
 @return True if the overlay is currently on the map, otherwise false.
 */
- (BOOL)hasOverlayForType:(AFOverlayType)overlayType;

/**
 Returns the overlay name for the specified type.
 
 @param overlayType The overlay type from the list of supported AFOverlayType layers.
 */
- (NSString *)overlayNameForType:(AFOverlayType)overlayType;

/**
 Returns the full name for the overlay based on code.
 
 @param code The overlay code to return the full name for.
 */
- (NSString *)overlayNameForCode:(NSString *)code;

/**
 Returns the AFOverlayType based on the provided code.
 
 @param code The overlay code to return the AFOverlayType for.
 */
- (AFOverlayType)overlayTypeForCode:(NSString *)code;

/**
 Returns the code strings for the currently active overlays on the AFWeatherMap instance.
 
 To convert the code strings to their appropriate AFOverlayType enumerated value, use `overlayTypeForCode`.
 @return An array of overlay code strings for the overlays active on the map.
 @since 1.1.3
 */
- (NSArray *)activeOverlayTypeCodes;

/**
 Returns the code string for the currently active overlays broken up by overlay type.
 
 @since 1.1.4
 */
- (NSDictionary *)activeOverlayTypeCodesByOverlayType;

///--------------------------
/// @name Point Data Overlays
///--------------------------

/**
 Toggles the point data overlay on or off depending on its current state. If an overlay has not yet been instantiated 
 for the specified point data type, one will be created and added to the map as needed.
 
 @param pointDataType The point data overlay type from the list of supported AFPointDataType layers
 @deprecated As of 1.1.3
 */
- (void)togglePointDataForType:(AFPointDataType)pointDataType;

/**
 Displays the point data layer for the specified type. If the point data layer is already visible on the map, this
 method will do nothing.
 
 @param pointDataType The point data overlay type from the list of supported AFPointDataType layers
 @deprecated As of 1.1.3
 */
- (void)showPointDataForType:(AFPointDataType)pointDataType;

/**
 Removes the point data layer and all annotations from the map view. This method does nothing if the point data layer
 does not exist or has already been removed.
 
 @param pointDataType The point data overlay type from the list of supported AFPointDataType layers
 @deprecated As of 1.1.3
 */
- (void)hidePointDataForType:(AFPointDataType)pointDataType;

/**
 Checks if the map view currently has a point data layer for the specified type.
 
 @param pointDataType The point data overlay type from the list of supported AFPointDataType layers
 @return True if the point data layer is currently on the map, otherwise false.
 @deprecated As of 1.1.3
 */
- (BOOL)hasPointDataForType:(AFPointDataType)pointDataType;

/**
 Returns the AFPointDataType based on the provided code.
 
 @param code The point data code to return the AFPointDataType for.
 @deprecated As of 1.1.3
 */
- (AFOverlayType)pointDataTypeForCode:(NSString *)code;

///----------------------------
/// @name Polygon Data Overlays
///----------------------------

/**
 Toggles the polygon data overlay on or off depending on its current state. If an overlay has not yet been instantiated
 for the specified polygon data type, one will be created and added to the map as needed.
 
 @param polygonDataType The polygon data type from the list of supported AFPolygonDataType layers.
 @deprecated As of 1.1.3
 */ 
- (void)togglePolygonDataForType:(AFPolygonDataType)polygonDataType;

/**
 Displays the polygon data layer for the specified type. If the polygon data layer is already visible on the map, this
 method will do nothing.
 
 @param polygonDataType The point data overlay type from the list of supported AFPolygonDataType layers
 @deprecated As of 1.1.3
 */
- (void)showPolygonDataForType:(AFPolygonDataType)polygonDataType;


/**
 Removes the polygon data layer and all annotations from the map view. This method does nothing if the polygon data layer
 does not exist or has already been removed.
 
 @param polygonDataType The polygon data overlay type from the list of supported AFPolygonDataType layers
 @deprecated As of 1.1.3
 */
- (void)hidePolygonDataForType:(AFPolygonDataType)polygonDataType;

/**
 Checks if the map view currently has a polygon data layer for the specified type.
 
 @param polygonDataType The polygon data overlay type from the list of supported AFPolygonDataType layers
 @return True if the polygon data layer is currently on the map, otherwise false.
 @deprecated As of 1.1.3
 */
- (BOOL)hasPolygonDataForType:(AFPolygonDataType)polygonDataType;

/**
 Returns the AFPolygonDataType based on the provided code.
 
 @param code The polygon data code to return the AFPolygonDataType for.
 @deprecated As of 1.1.3
 */
- (AFOverlayType)polygonDataTypeForCode:(NSString *)code;

///----------------------------
/// @name Nexrad Radar Overlays
///----------------------------

- (void)showNexradForStationWithId:(NSString *)stationId;

/**
 Refreshes all point data layers currently active and visible on the map. This is usually called whenever there has
 been a region or zoom change from the map view instance.
 
 @deprecated As of 1.0.4.
 */
- (void)refresh;

/**
 Refreshes all tile overlays currently active and visible on the map. This is usually called when returning to the
 map view within an application.
 
 @since 1.0.4
 */
- (void)refreshTileOverlays;

/**
 Refreshes all point data layers currently active and visible on the map. This is usually called whenever there has
 been a region or zoom change from the map view instance, or when returning to the map view within an 
 application.
 
 @since 1.0.4
 */
- (void)refreshPointDataOverlays;

/**
 Refreshes all tile and point data overlays currently active and visible on the map. This is usually called when 
 returning to the map view within an application.
 
 @since 1.0.4
 */
- (void)refreshAllOverlays;

///------------------------
/// @name Animation Control
///------------------------

/**
 Starts animating the currently active tile overlays if they support animations.
 */
- (void)startAnimating;

/**
 Stops animating all currently active tile overlays.
 */
- (void)stopAnimating;

/**
 Steps the current animation forward one frame.
 */
- (void)stepAnimationForward;

/**
 Steps the current animation back one frame.
 */
- (void)stepAnimationBack;

/**
 Advances to a specific frame within the current overlay animation. Note that the animation must have been loaded already by calling `startAnimating` and the 
 loading process completes.
 
 @param frame The index of the frame in the animation to advance to.
 @param stop Whether or not to stop the animation. If NO, animating will continue normally from the specified frame.
 */
- (void)goToAnimationFrame:(NSUInteger)frame stop:(BOOL)stop;

/**
 Performs any layout preparation for the new interface orientation, which should be called before the interface orientation
 actually occurs.
 
 @param interfaceOrientation The `UIInterfaceOrientation` that the device will rotate to.
 */
- (void)prepareLayoutForInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;

/**
 Forces an update of internal view containers for animations and map controls when the device is rotated.
 
 @param interfaceOrientation The `UIInterfaceOrientation` that the device rotated to.
 */
- (void)layoutForInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;

@end

@protocol AFWeatherMapDelegate <NSObject>

@optional
/**
 Called when the user has a single finger on the map for at least the duration specified in the `tapAndHoldDelay` 
 property.
 
 Can be implemented to provide additional custom functionality.
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 @param touch
 */
- (void)weatherMapDidTapAndHold:(AFWeatherMap *)weatherMap touch:(NSDictionary *)touch;

/**
 Called when the user has removed their finger from the map, or has panned/zoomed the map. The tap-and-hold action
 will be cancelled if this was fired before the specified delay in `tapAndHoldDelay`.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 */
- (void)weatherMapDidCancelTapAndHold:(AFWeatherMap *)weatherMap;

/**
 Tells the delegate when an Aeris-specific overlay was added to the map.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 @param code The code associated with the added overlay.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didAddOverlayWithCode:(NSString *)code;

/**
 Tells the delegate when an Aeris-specific overlay was added to the map.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 @param overlay The `AFOverlay` instance that was added.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didAddOverlay:(AFOverlay *)overlay;

/**
 Tells the delegate when an Aeris-specific overlay was removed from the map.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 @param code The code associated with the removed overlay.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didRemoveOverlayWithCode:(NSString *)code;

/**
 Tells the delegate when an Aeris-specific overlay was removed from the map.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 @param overlay The `AFOverlay` instance that was removed.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didRemoveOverlay:(AFOverlay *)overlay;

///----------------------------------
/// @name Responding to Data Requests
///----------------------------------

/**
 Tells the delegate when point or polygon data has finished loading for an overlay currently visible on the map.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 @param code The code associated with the point or polygon data overlay.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didLoadDataForOverlayWithCode:(NSString *)code;

/**
 Tells the delegate when a request for point or polygon data overlay triggers an error.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 @param code The code associated with the point or polygon data overlay.
 @param error The NSError instance
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didFailLoadDataForOverlayWithCode:(NSString *)code withError:(NSString *)error;

///-------------------------------
/// @name Responding to Animations
///-------------------------------

/**
 Called when animations were enabled by the shared AFOverlayManager instance, usually when a tile overlay that supports
 animations was added to the current map view.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 */
- (void)weatherMapDidEnableAnimations:(AFWeatherMap *)weatherMap;

/**
 Called when animations were disabled by the shared AFOverlayManager instance, usually when a tile overlay that supports
 animations was removed from the current map view or replaced with one that doesn't support animating.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 */
- (void)weatherMapDidDisableAnimations:(AFWeatherMap *)weatherMap;

/**
 Called when the tile overlays have started animating.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 */
- (void)weatherMapDidStartAnimating:(AFWeatherMap *)weatherMap;

/**
 Called when the tile overlays have stopped animating.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 */
- (void)weatherMapDidStopAnimating:(AFWeatherMap *)weatherMap;

/**
 Tells the delegate when the loading process for animation frames has started.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 */
- (void)weatherMapDidStartLoadingAnimation:(AFWeatherMap *)weatherMap;

- (void)weatherMap:(AFWeatherMap *)weatherMap didPauseAnimationOnFrame:(NSUInteger)frame;

/**
 Tells the delegate when all frames for the animation have finished loading.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 */
- (void)weatherMapDidFinishLoadingAnimation:(AFWeatherMap *)weatherMap;

/**
 Tells the delegate when the animation frame loading progress has changed.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 @param progress The current loading progress from 0 to 1.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didUpdateAnimationLoadingProgress:(NSNumber *)progress;

/**
 Tells the delegate when the animation frame changed.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 @param frame The frame number the animation is currently displaying.
 @param date The `NSDate` representing the valid date and time for the current frame.
 @param totalIntervals The total number of frames in the animation.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didUpdateAnimationToFrame:(NSUInteger)frame withDate:(NSDate *)date totalIntervals:(NSUInteger)totalIntervals;

///---------------------------------------
/// @name Handling Map Annotation Callouts
///---------------------------------------

/**
 Asks the delegate if the map view should show the point annotation and callout on a long press gesture.
 
 @return Whether or not the callout should appear.
 */
- (BOOL)weatherMapShouldShowCalloutOnTapGesture:(AFWeatherMap *)weatherMap;

/**
 Asks the delegate if the long-press gesture callout should display a disclosure button.
 
 @return Whether or not a disclosure button should be added to the callout view.
 */
- (BOOL)weatherMapShouldShowCalloutDisclosureButton:(AFWeatherMap *)weatherMap;

/**
 Requests a custom view from the delegate to use for the callout content view.
 
 @return The custom view to use for the callout content.
 */
- (UIView *)weatherMap:(AFWeatherMap *)weatherMap contentViewForCallout:(AFCalloutView *)calloutView;

/**
 Tells the delegate when data was successfully loaded to use for the long-press gesture callout.
 
 This should be used i nconjunction with `weatherMap:contentViewForCallout:` in order to set the proper view content based on the
 returned data.
 
 @param weatherMap The `AFWeatherMap` instance on which the callout will appear.
 @param objects An array of objects returned from the internal `AFObjectLoader` for the map coordinate.
 @param calloutView The callout view that requested the data. Set the view's data by accessing the `contentView` property on this callout view instance.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didLoadObjects:(NSArray *)objects forCallout:(AFCalloutView *)calloutView;

/**
 Tells the delegate when data failed to load for the long-press gesture callout.
 
 This should be used i nconjunction with `weatherMap:contentViewForCallout:` in order to set the proper view content based on the
 returned data or returned error.
 
 @param weatherMap The `AFWeatherMap` instance on which the callout will appear.
 @param error The error returned from the failed request.
 @param calloutView The callout view that requested the data. Set the view's data by accessing the `contentView` property on this callout view instance.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didFailLoadingWithError:(NSError *)error forCallout:(AFCalloutView *)calloutView;

///-----------------------------------------
/// @name Responding to Map Position Changes
///-----------------------------------------

/**
 Tells the delegate that the region displayed by the map view is about to change.
 
 @param weatherMap The `AFWeatherMap` instance containing the map view whose region will change.
 @see MKMapViewDelegate
 */
- (void)weatherMapRegionWillChangedAnimated:(AFWeatherMap *)weatherMap;

/**
 Tells the delegate that the region displayed by the map just changed.
 
 @param weatherMap The `AFWeatherMap` instance containing the map view whose region changed.
 @see MKMapViewDelegate
 */
- (void)weatherMapRegionDidChangeAnimated:(AFWeatherMap *)weatherMap;

///---------------------------------
/// @name Tracking the User Location
///---------------------------------

/**
 Tells the delegate that the map view will start tracking the user's position.
 
 @param weatherMap The `AFWeatherMap` instance containing the map view that is tracking the user's location.
 @see MKMapViewDelegate
 */
- (void)weatherMapWillStartLocatingUser;

/**
 Tells the delegate that the map view stopped tracking the user's location.
 
 @param weatherMap The `AFWeatherMap` instance containing the map view that stopped tracking the user's location.
 @see MKMapViewDelegate
 */
- (void)weatherMapDidStopLocatingUser;

/**
 Tells the delegate that the location of the user was updated.
 
 @param weatherMap The `AFWeatherMap` instance that triggered the event.
 @param userLocation The location object representing the user's location.
 @see MKMapViewDelegate
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didUpdateUserLocation:(MKUserLocation *)userLocation;

/**
 Tells the delegate that an attempt to locate the user's position failed.
 
 @param weatherMap The `AFWeatherMap` instance containing the map view that is tracking the user's location.
 @see MKMapViewDelegate
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didFailToLocateUserWithError:(NSError *)error;

/**
 Tells the delegate that the user tracking mode changed.
 
 @param weatherMap The `AFWeatherMap` instance whose user tracking mode changed.
 @param mode The mode used to track the user's location.
 @param animated
 @see MKMapViewAnnotation
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didChangeUserTrackingMode:(MKUserTrackingMode)mode animated:(BOOL)animated;

///--------------------------------
/// @name Managing Annotation Views
///--------------------------------

/**
 Returns the view associated with the specified annotation object.
 
 @param weatherMap The `AFWeatherMap` instance containing the map view that requested the annotation view.
 @param annotation The object representing the annotation that is about to be displayed.
 @see MKMapViewAnnotation
 */
- (MKAnnotationView *)weatherMap:(AFWeatherMap *)weatherMap viewForAnnotation:(id<MKAnnotation>)annotation;

/**
 Tells the delegate that one or more annotation views were added to the map.
 
 @param weatherMap The `AFWeatherMap` instance that added the annotation views.
 @param views An array of `MKAnnotationView` objects representing the views that were added.
 @see MKMapViewAnnotation
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didAddAnnotationViews:(NSArray *)views;

/**
 Tells the delegate that the callout for the selected annotation view is about to appear.
 
 @param weatherMap The `AFWeatherMap` instance that contains the selected annotation view.
 @param annotationView The annotation view that was selected.
 @param calloutView The `AFCalloutView` instance that is about to be presented.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap annotationView:(MKAnnotationView *)annotationView willShowCallout:(AFCalloutView *)calloutView;

/**
 Tells the delegate that the weather map is about to dismiss the current callout view.
 
 @param weatherMap The `AFWeatherMap` instance that will dismiss the callout view.
 @param calloutView The `AFCalloutView` instance that will be dismissed.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap willDismissCallout:(AFCalloutView *)calloutView;

/**
 Tells the delegate that the weather map has dismissed the current callout view.
 
 @param weatherMap The `AFWeatherMap` instance that dismissed the callout view.
 @param calloutView The `AFCalloutView` instance that has been dismissed.
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didDismissCallout:(AFCalloutView *)calloutView;

/**
 Tells the delegate that the user tapped one of the annotation view's accessory buttons.
 
 @param weatherMap The `AFWeatherMap` instance containing the specified annotation view.
 @param view The annotation view whose button was tapped.
 @param control The control that was tapped.
 @see MKMapViewAnnotation
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap annotationView:(MKAnnotationView *)view calloutAccessoryControlTapped:(UIControl *)control;

/**
 Tells the delegate that the drag state of one of its annotation views changed.
 
 @param weatherMap The `AFWeatherMap` instance containing the annotation view.
 @param annotationView The annotation view whose drag state changed.
 @param newState The new drag state of the annotation view.
 @param oldState The old drag state of the annotation view.
 @see MKMapViewAnnotation
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap annotationView:(MKAnnotationView *)annotationView didChangeDragState:(MKAnnotationViewDragState)newState fromOldState:(MKAnnotationViewDragState)oldState;

/**
 Tells the delegate that one of the map view's annotations was selected.
 
 @param weatherMap The `AFWeatherMap` instance containing the map view of the annotation view.
 @param view The annotation view that was selected.
 @see MKMapViewDelegate
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didSelectAnnotationView:(MKAnnotationView *)view;

/**
 Tells the delegate that one of the map view's annotation views was deselected.
 
 @param weatherMap The `AFWeatherMap` instance containing the map view of the annotation view.
 @param view The annotation view that was deselected.
 @see MKMapViewDelegate
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didDeselectAnnotationView:(MKAnnotationView *)view;

///-----------------------------
/// @name Managing Overlay Views
///-----------------------------

/**
 Asks the delegate for the overlay view to use when displaying the specified overlay object.
 
 @param weatherMap The `AFWeatherMap` instance containing the map view requesting the overlay view.
 @param overlay The object representing the overlay that is about to be displayed.
 @see MKMapViewDelegate
 */
- (MKOverlayView *)weatherMap:(AFWeatherMap *)weatherMap viewForOverlay:(id<MKOverlay>)overlay;

/**
 Tells the delegate that one or more overlay views were added to the map.
 
 @param weatherMap The `AFWeatherMap` instance containing the map view that added the overlay views.
 @param overlayViews An array of `MKOverlayView` objects representing the views that were added.
 @see MKMapViewDelegate
 */
- (void)weatherMap:(AFWeatherMap *)weatherMap didAddOverlayViews:(NSArray *)overlayViews;

@end
