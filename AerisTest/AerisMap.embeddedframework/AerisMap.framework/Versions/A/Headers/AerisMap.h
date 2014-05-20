//
//  AerisMap.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 8/31/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

// This setting of 1 is best if the code source is copied directly into a project
// The build transforms the 1 to a 0 when building the framework and static lib

#import <AerisMap/AFMapGlobals.h>
#import <AerisMap/AFWeatherMap.h>

#import <AerisMap/AFOverlay.h>
#import <AerisMap/AFImageOverlay.h>
#import <AerisMap/AFTileOverlay.h>
#import <AerisMap/AFPolygonOverlay.h>
#import <AerisMap/AFTileOverlayView.h>
#import <Aerismap/AFPolygonOverlayView.h>

// overlay types
#import <AerisMap/AFTileOverlayType.h>
#import <AerisMap/AFPointDataType.h>
#import <AerisMap/AFPolygonDataType.h>

#import <AerisMap/AFOverlayGroup.h>
#import <AerisMap/AFOverlayType.h>

#import <AerisMap/AFAnnotation.h>	
#import <AerisMap/AFFlexibleCalloutAnnotation.h>	
#import <AerisMap/AFFlexibleCalloutAnnotationView.h>
#import <AerisMap/AFStormCellAnnotation.h>	
#import <AerisMap/AFStormCellAnnotationView.h>
#import <AerisMap/AFStormCellForecastPolyline.h>
#import <AerisMap/AFFireAnnotation.h>
#import <AerisMap/AFFireAnnotationView.h>
#import <AerisMap/AFStormReportAnnotation.h>
#import <AerisMap/AFStormReportAnnotationView.h>
#import <AerisMap/AFRecordAnnotation.h>
#import <AerisMap/AFRecordAnnotationView.h>
#import <AerisMap/AFEarthquakeAnnotation.h>
#import <AerisMap/AFEarthquakeAnnotationView.h>

#import <AerisMap/MKMapView+AFAdditions.h>
#import <AerisMap/MKPolygon+AFAdditions.h>

// view controllers
#import <AerisMap/AFWeatherMapViewController.h>
#import <AerisMap/AFWeatherMapOptionsViewController.h>

// legends & views
#import <AerisMap/AFLegend.h>
#import <AerisMap/AFMapControlView.h>
#import <AerisMap/AFAnimationControlView.h>