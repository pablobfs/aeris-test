//
//  AFStormCellForecastOverlay.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/7/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import <Aeris/Aeris.h>

@interface AFStormCellForecastPolyline : MKPolyline {
	UIColor *lineColor_;
}

@property (nonatomic, retain) UIColor *lineColor;

+ (AFStormCellForecastPolyline *)polylineFromForecastPeriods:(NSArray *)periods;

+ (AFStormCellForecastPolyline *)polylineToLastForecastPeriodForStormCell:(AFStormCell *)stormCell;

@end
