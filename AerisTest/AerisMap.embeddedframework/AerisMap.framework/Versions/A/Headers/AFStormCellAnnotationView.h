//
//  AFStormCellAnnotationView.h
//  AerisMap
//
//  Created by Nicholas Shipes on 9/6/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "AFStormCellForecastConeOverlay.h"

@interface AFStormCellAnnotationView : MKAnnotationView {
	AFStormCellForecastConeOverlay *forecastConeOverlay_;
}

@property (nonatomic, retain) AFStormCellForecastConeOverlay *forecastConeOverlay;

@end
