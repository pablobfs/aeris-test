//
//  MKMapView+AFAdditions.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/6/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

CLLocationCoordinate2D AFMapTilePointToCoordinate(CGPoint point, NSUInteger zoomLevel);
CGPoint AFMapPointToTilePoint(MKMapPoint mapPoint, NSUInteger zoomLevel);

@interface MKMapView (AFAdditions)

//+ (MKMapRect)mapRectForNorthwestTile:(CGPoint)northwestTile southeastTile:(CGPoint)southeastTile;

+ (NSUInteger)zoomLevelForZoomScale:(MKZoomScale)zoomScale;

/**
 Returns the northwest (top-left) coordinate of the map bounds.
 */
- (CLLocationCoordinate2D)northwestCoordinate;

/**
 Returns the northeast (top-right) coordinate of the map bounds.
 */
- (CLLocationCoordinate2D)northeastCoordinate;

/**
 Returns the southwest (bottom-left) coordinate of the map bounds.
 */
- (CLLocationCoordinate2D)southwestCoordinate;

/**
 Returns the southeast (bottom-right) coordinate of the map bounds.
 */
- (CLLocationCoordinate2D)southeastCoordinate;

/**
 Translates a tile coordinate into the appropriate tile column and row number based on the map view's current zoom
 level.
 
 @param coordinate The CLLocationCoordinate2D to determine the tile for
 @return A CGPoint providing the column (x) and row (y) of the map tile.
 */
- (CGPoint)tileXYForCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 Translates a tile coordinate into the appropriate tile column and row number based on the provided zoom level.
 
 @param coordinate The CLLocationCoordinate2D to determine the tile for.
 @param zoomLevel The zoom level to use for calculating the column and row of the tile.
 @return A CGPoint providing the column (x) and row (y) of the map tile.
 */
- (CGPoint)tileXYForCoordinate:(CLLocationCoordinate2D)coordinate zoomLevel:(NSUInteger)zoomLevel;

/**
 Calculates the coordinate for a tile at the specified column (x) and row (y).
 
 @param x The column of the tile
 @param y The row of the tile
 @return A CLLocationCoordinate2D for the top-left corner of the tile on the map.
 */
- (CLLocationCoordinate2D)coordinateForTileX:(NSUInteger)x y:(NSUInteger)y;
- (CLLocationCoordinate2D)coordinateAdjustedForScreenScaleForTileX:(NSUInteger)x y:(NSUInteger)y;

/**
 Returns the x/y coordinate for the top-left tile for the map view.
 */
- (CGPoint)northwestTileXY;
- (CGPoint)northwestTileXYAdjustedForScreenScale;

/**
 Returns the x/y coordinate for the bottom-right tile for the map view;
 */
- (CGPoint)southeastTileXY;
- (CGPoint)southeastTileXYAdjustedForScreenScale;

/**
 Repositions the map instance based on a coordinate and zoom level.
 
 @param centerCoordinate The CLLocationCoordinate2D to set as the center of the map view
 @param zoomLevel The calculated zoom level to move to
 @param animated Whether or not the map's region change should be animated
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate zoomLevel:(NSUInteger)zoomLevel animated:(BOOL)animated;

/**
 Returns the calculated zoom level for the map instance.
 */
- (NSUInteger)zoomLevel;
- (NSUInteger)zoomLevelAdjustedForScreenScale;

/**
 Calculates and returns the current zoom scale for the map instance.
 */
- (MKZoomScale)zoomScale;

- (MKCoordinateSpan)coordinateSpanWithMapView:(MKMapView *)mapView centerCoordinate:(CLLocationCoordinate2D)centerCoordinate zoomLevel:(NSUInteger)zoomLevel;

/**
 Returns the UIImageView associated with the Google logo on MKMapView.
 */
- (UIImageView *)googleLogo;

@end
