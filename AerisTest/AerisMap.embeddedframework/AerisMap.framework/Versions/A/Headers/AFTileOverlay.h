//
//  AFTileOverlay.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 8/31/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import <Aeris/Aeris.h>
#import <AerisMap/AFImageOverlay.h>
#import "ASIHTTPRequestDelegate.h"

#define kAFTileOverlayTypeNamesArray @"", @"radar", @"sat", @"sat_visible", @"sat_global", @"alerts", @"snowdepth", @"current_temps", @"current_winds", @"current_dewpoint", @"current_humidity", @"current_windchill", @"current_heatindex", @"current_chlorophyll", @"current_sst", nil

#define kAFTileOverlayTypeCodesArray @"", @"radar", @"sat", @"sat_vistrans", @"globalsat", @"alerts", @"snowdepth_snodas", @"current_2mt_toi", @"current_winds", @"current_dp", @"current_rh", @"current_windchill", @"current_heat_index", @"modis_chlo_14day", @"modis_sst_14day", nil 


@protocol AFTileOverlayDelegate;
@protocol AFTileOverlay <AFOverlay>

typedef void (^AFTileOverlayRequestCompletionBlock)(MKMapRect mapRect, MKZoomScale zoomScale);

@property (nonatomic, assign) NSObject<AFTileOverlayDelegate> *delegate;
@required
- (NSString *)urlForPointWithX:(NSUInteger)x y:(NSUInteger)y zoomLevel:(NSUInteger)zoomLevel;

@optional
- (NSString *)urlForPointWithX:(NSUInteger)x y:(NSUInteger)y zoomLevel:(NSUInteger)zoomLevel timestamp:(NSString *)timestamp;
- (UIImage *)tileForMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale;
- (void)requestTileForMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale completion:(AFTileOverlayRequestCompletionBlock)completion;
- (void)cancelAllOperations;

@end

/**
 Base tile overlay class that provides core properties and methods for all `AFTileOverlay` classes.
 */
@interface AFTileOverlay : AFImageOverlay <AFTileOverlay, AFRequestDelegate, ASIHTTPRequestDelegate> {
	NSObject<AFTileOverlayDelegate> *_delegate;
}

/**
 
 */
@property (nonatomic, assign) NSObject<AFTileOverlayDelegate> *delegate;

@end

@protocol AFTileOverlayDelegate <NSObject>

-(void)tileOverlayDidFinishLoading:(AFTileOverlay *)tileOverlay;

@end