//
//  AFImageOverlay.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 5/24/12.
//  Copyright (c) 2012 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "AFOverlay.h"
#import "ASIHTTPRequest.h"

@protocol AFImageOverlay <AFOverlay>

@property (nonatomic, assign) CGFloat alpha;
@property (nonatomic, readonly) NSString *urlPath;
@property (nonatomic, readonly) BOOL cropsToMapBounds;
@property (nonatomic, readonly) BOOL cropsToTileBounds;

- (NSString *)urlForZoomLevel:(NSUInteger)zoomLevel;

@optional
- (NSString *)urlForZoomLevel:(NSUInteger)zoomLevel northwestTile:(CGPoint)northwestTile southeastTile:(CGPoint)southeastTile;
- (NSString *)urlForZoomLevel:(NSUInteger)zoomLevel northwestCoordinate:(CLLocationCoordinate2D)northwestCoord southeastCoordinate:(CLLocationCoordinate2D)southeastCoord;

@end

@interface AFImageOverlay : AFOverlay <AFImageOverlay> {
	CGFloat _defaultAlpha;
	CGFloat _alpha;
	NSString *_urlPath;
	BOOL _cropsToMapBounds;
	BOOL _cropsToTileBounds;
}

/**
 The full URL path to the tiles for this overlay.
 */
@property (nonatomic, readonly) NSString *urlPath;

/**
 The opacity of the overlay.
 */
@property (nonatomic, assign) CGFloat defaultAlpha;

/**
 The current opacity of the overlay.
 */
@property (nonatomic, assign) CGFloat alpha;

@property (nonatomic, assign) ASICachePolicy cachePolicy;

/**
 The cache storage policy to use for images loaded by this overlay.
 */
@property (nonatomic, assign) ASICacheStoragePolicy cacheStoragePolicy;

/**
 Whether or not the overlay images are cropped to the map bounds.
 */
@property (nonatomic, readonly) BOOL cropsToMapBounds;

/**
 Whether or not the overlay images are cropped to tile bounds.
 */
@property (nonatomic, readonly) BOOL cropsToTileBounds;

- (id)initWithCoordinate:(CLLocationCoordinate2D)coord boundingRect:(MKMapRect)boundingRect;

@end