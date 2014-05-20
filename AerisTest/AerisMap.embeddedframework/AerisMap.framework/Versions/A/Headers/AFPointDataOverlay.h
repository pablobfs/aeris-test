//
//  AFPointDataOverlay.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/6/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import <Aeris/Aeris.h>
#import <AerisMap/AFPointDataType.h>
#import "AFOverlay.h"

#define kAFPointDataTypeNamesArray @"", @"obs", @"river", @"tides", @"buoys", @"stormcells", @"stormreports", @"fires", @"lightning", @"records", @"earthquakes", nil

@protocol AFPointDataOverlayDelegate;

/**
 Base point data overlay class that provides core properties and methods for loading, storing and removing map
 annotations and overlays associated with this instance.
 */
@interface AFPointDataOverlay : AFOverlay <AFObjectLoaderDelegate> {
	NSArray *_objects;
	AFObjectLoader *_loader;
	NSArray *_annotations;
	NSArray *_polylines;
	NSArray *_polygons;
	NSObject<AFPointDataOverlayDelegate> *_delegate;
}

/**
 An array of objects currently loaded into the internal data store.
 */
@property (nonatomic, retain) NSArray *objects;

/**
 An array of map annotations associated with this overlay.
 */
@property (nonatomic, readonly) NSArray *annotations;

/**
 An array of polylines associated with this overlay.
 */
@property (nonatomic, readonly) NSArray *polylines;

/**
 An array of polygons associated with this overlay.
 */
@property (nonatomic, readonly) NSArray *polygons;

/**
 The delegate object that receives notifications about data requests and statuses.
 
 The delegate must implement the `AFPointDataOverlayDelegate` protocol.
 */
@property (nonatomic, assign) NSObject<AFPointDataOverlayDelegate> *delegate;

/**
 Loads data for a specific geographical coordinate.
 
 @param latitude The horizontal coordinate
 @param longitude The vertical coordinate
 */
- (void)loadForLatitude:(CGFloat)latitude longitude:(CGFloat)longitude;

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

- (void)instructDelegateToRemoveOverlays;

@end

@protocol AFPointDataOverlayDelegate <NSObject>

/**
 Called when the internal data for this overlay successfully loaded.
 
 @param overlay The `AFPointDataOverlay` instance that requested the data.
 @param objects An `NSArray` of objects loaded from the request.
 */
- (void)pointDataOverlay:(AFPointDataOverlay *)overlay didLoadObjects:(NSArray *)objects;

/**
 Called when there was an error loading the internal data necessary for this overlay.
 
 @param overlay The `AFPointDataOverlay` instance that requested the data.
 @param error The `NSError` that occurred.
 */
- (void)pointDataOverlay:(AFPointDataOverlay *)overlay didFailLoadWithError:(NSError *)error;

- (void)pointDataOverlay:(AFPointDataOverlay *)overlay canRemoveAnnotations:(NSArray *)annotations andOverlays:(NSArray *)overlays;

@end