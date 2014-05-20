//
//  AFForecastDetailView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/1/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AFView.h"
#import "AFLabel.h"


@interface AFForecastDetailView : AFView {	
	AFLabel* _periodView;
	AFLabel* _tempView;
	AFLabel* _weatherView;
	AFLabel* _windsView;
	AFLabel* _precipView;
	AFLabel* _snowView;
	UIImageView* _iconView;
	
	AFLabel *_precipLabel;
}

/**
 The text to display for the period.
 */
@property (nonatomic, copy) NSString* period;

/**
 The text to display for the temperature.
 */
@property (nonatomic, copy) NSString* temp;

/**
 The text to display for the weather.
 */
@property (nonatomic, copy) NSString* weather;

/**
 The text to display for the winds.
 */
@property (nonatomic, copy) NSString* winds;

/**
 The text to display for the precipitation total.
 */
@property (nonatomic, copy) NSString* precip;

/**
 The text to display for the snow total.
 */
@property (nonatomic, copy) NSString* snow;

/**
 The UIImage to display for the icon.
 */
@property (nonatomic, copy) UIImage* icon;

@end
