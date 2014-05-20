//
//  ObservationView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 7/29/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AFView.h"
#import "AFLabel.h"


@interface AFObservationView : AFView {
    UIImageView* _iconView;
	AFLabel* _locationView;
	AFLabel* _tempView;
	AFLabel* _weatherView;
	AFLabel* _feelslikeView;
	AFLabel* _windsView;
	AFLabel* _humidityView;
	AFLabel* _dewpointView;
	AFLabel* _pressureView;
	
	BOOL _showDetail;
}

/**
 The UIImage instance to display for the icon.
 */
@property (nonatomic, retain) UIImage* icon;

/**
 The text to display for the location name/title.
 */
@property (nonatomic, retain) NSString* location;

/**
 The text to display for the temperature.
 */
@property (nonatomic, retain) NSString* temp;

/**
 The text to display for the weather.
 */
@property (nonatomic, retain) NSString* weather;

/**
 The text to display for the feels like temperature.
 */
@property (nonatomic, retain) NSString* feelslike;

/**
 The text to display for the winds.
 */
@property (nonatomic, retain) NSString* winds;

/**
 The text to display for the relative humidity.
 */
@property (nonatomic, retain) NSString* humidity;

/**
 The text to display for the dew point.
 */
@property (nonatomic, retain) NSString* dewpoint;

/**
 The text to display for the barometric pressure.
 */
@property (nonatomic, retain) NSString* pressure;

/**
 Hides the detail view, typically used when there are active advisories that need to be displayed over the detail view.
 */
- (void)hideDetails;

@end
