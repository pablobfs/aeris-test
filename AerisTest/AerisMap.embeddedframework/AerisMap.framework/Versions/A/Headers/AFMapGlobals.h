//
//  AFMapGlobals.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/7/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AF_RADIANS_TO_DEGREES(radians) ((radians) * (180.0 / M_PI))
#define AF_DEGREES_TO_RADIANS(degrees) ((degrees) / 180.0 * M_PI)

#define kAFTileOverlayCodeRadar				@"radar"
#define kAFTileOverlayCodeSatellite			@"sat"
#define kAFTileOverlayCodeVisibleSatellite	@"sat_vistrans"
#define kAFTileOverlayCodeGlobalSatellite	@"globalsat"
#define kAFTileOverlayCodeSnowDepth			@"snowdepth_snodas"
#define kAFTileOverlayCodeAdvisory			@"alerts"
#define kAFTileOverlayCodeCurrentTemp		@"current_2mt_toi"
#define kAFTileOverlayCodeCurrentWind		@"current_winds"
#define kAFTileOverlayCodeCurrentDewPoint	@"current_dp"
#define kAFTileOverlayCodeCurrentHumidity	@"current_humidity"
#define kAFTileOverlayCodeCurrentWindChill	@"current_windchill"
#define kAFTileOverlayCodeCurrentHeatIndex	@"current_heatindex"


///----------------
/// @name Utilities
///----------------

#define AF_CONTROL(name) [UIImage imageNamed:[NSString stringWithFormat:@"AerisMap.bundle/controls/%@", name]]
#define AF_MARKER(name) [UIImage imageNamed:[NSString stringWithFormat:@"AerisMap.bundle/markers/%@", [name stringByReplacingOccurrencesOfString:@"gif" withString:@"png"]]]
#define AF_LEGEND(name) [UIImage imageNamed:[NSString stringWithFormat:@"AerisMap.bundle/legends/%@", [name stringByReplacingOccurrencesOfString:@"gif" withString:@"png"]]]