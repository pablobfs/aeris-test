//
//  AFTileOverlayView.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 8/31/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <Aeris/Aeris.h>
#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@interface AFTileOverlayView : MKOverlayView <AFRequestDelegate, ASIHTTPRequestDelegate>

/**
 Clears and resets the request queue used for loading tile imagery.
 */
- (void)resetQueue;

@end
