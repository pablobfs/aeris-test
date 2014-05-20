//
//  AFWeatherMapViewController.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/7/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <AerisMap/AFWeatherMap.h>

/**
 A UIViewController that automatically creates an instance of `MKMapView` and `AFWeatherMap` to provide the core weather 
 map functionality. The `MKMapView` instance is added as a subview of this controller's view and passed to the `AFWeatherMap` 
 instance, which manages the weather data overlays actively presented on the map view.
 
 This controller automatically handles all of the necessary MKOverlayView and MKAnnotationView creation for the map view 
 based on the types of weather data currently presented on the map. It also handles the tap-and-hold feature for displaying
 current weather conditions at any point on the map in an annotation callout.
 
 Custom UIViewControllers in place of AFWeatherMapViewController as long as an instance of `AFWeatherMap` is created and
 passed the appropriate `MKMapView` instance to control the weather data overlays on.
 */
@interface AFWeatherMapViewController : UIViewController <AFWeatherMapDelegate> {
	MKMapView *_mapView;
	AFWeatherMap *_wxmap;
}

/**
 The MKMapView instance assigned to this controller.
 */
@property (nonatomic, retain) MKMapView *mapView;

/**
 The AFWeatherMap instance that this controller will manage.
 */
@property (nonatomic, retain) AFWeatherMap *weatherMap;

@end
