//
//  AFPolygonOverlay.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 10/5/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import <AerisMap/AFOverlay.h>

/**
 Base polygon overlay class.
 */
@interface AFPolygonOverlay : AFOverlay {
	MKPolygon *_polygon;
	CLLocationCoordinate2D _nwCoord;
	CLLocationCoordinate2D _seCoord;
	
	UIColor *_lineColor;
	CGFloat _lineWidth;
	UIColor *_fillColor;
}

/**
 The `MKPolygon` associating with the overlay.
 */
@property (nonatomic, retain) MKPolygon *polygon;

@property (nonatomic, retain) UIColor *lineColor;

@property (nonatomic, assign) CGFloat lineWidth;

@property (nonatomic, retain) UIColor *fillColor;

/**
 Creates a polygon overlay instance with the provided array of coordinate points.
 */
- (id)initWithPoints:(NSArray *)points;

/**
 Calculates the MKMapRect defining the outermost bounds of the overlay.
 */
- (MKMapRect)boundingMapRect;

/**
 Calculates the center coordinate of the overlay.
 */
- (CLLocationCoordinate2D)coordinate;

@end
