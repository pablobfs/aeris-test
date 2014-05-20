//
//  AFPolygonDataOverlay.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 5/15/12.
//  Copyright (c) 2012 HAMweather, LLC. All rights reserved.
//

#import "AFPointDataOverlay.h"
#import "AFOverlay.h"

#define kAFPolygonDataTypeNamesArray @"", @"warnings", nil

@protocol AFPolygonDataOverlayDelegate;

@interface AFPolygonDataOverlay : AFOverlay <AFObjectLoaderDelegate> {
	NSArray *_objects;
	AFObjectLoader *_loader;
	NSArray *_polygons;
	NSObject<AFPolygonDataOverlayDelegate> *_delegate;
}

/**
 An array of objects currently loaded into the internal data store.
 */
@property (nonatomic, retain) NSArray *objects;

/**
 An array of polygons associated with this overlay.
 */
@property (nonatomic, readonly) NSArray *polygons;

/**
 The delegate object that receives notifications about data requests and statuses.
 
 The delegate must implement the `AFPointDataOverlayDelegate` protocol.
 */
@property (nonatomic, assign) NSObject<AFPolygonDataOverlayDelegate> *delegate;

/**
 Loads all data within the specified bounds of the map.
 
 @param mapRect The `MKMapRect` defining the current bounds to query against.
 */
- (void)loadForMapRect:(MKMapRect)mapRect;

/**
 Loads all data within the bounds with a specified northeast and southwest coordinate.
 
 @param northeast The CLLocationCoordinate2D describing the coordinate at the top-right of the bounds
 @param southwest The CLLocationCoordinate2D describing the coordinate at the bottom-left of the bounds
 */
- (void)loadForBoundsWithNortheast:(CLLocationCoordinate2D)northeast southwest:(CLLocationCoordinate2D)southwest;

@end

@protocol AFPolygonDataOverlayDelegate <NSObject>

/**
 Called when the internal data for this overlay successfully loaded.
 
 @param overlay The `AFPolygonDataOverlayDelegate` instance that requested the data.
 @param objects An `NSArray` of objects loaded from the request.
 */
- (void)polygonDataOverlay:(AFPolygonDataOverlay *)overlay didLoadObjects:(NSArray *)objects;

/**
 Called when there was an error loading the internal data necessary for this overlay.
 
 @param overlay The `AFPolygonDataOverlayDelegate` instance that requested the data.
 @param error The `NSError` that occurred.
 */
- (void)polygonDataOverlay:(AFPolygonDataOverlay *)overlay didFailLoadWithError:(NSError *)error;

@end