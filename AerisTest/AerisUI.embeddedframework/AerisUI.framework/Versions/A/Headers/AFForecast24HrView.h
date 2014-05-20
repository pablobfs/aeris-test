//
//  Forecast24HrView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/1/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AFForecastDetailView.h"
#import "AFView.h"
#import "AFLabel.h"


@interface AFForecast24HrView : AFView {
	AFLabel* _periodView;
	AFLabel* _dateView;
	UIView* _titleBackground;
	AFForecastDetailView* _dayView;
	AFForecastDetailView* _nightView;
}

/**
 The UIView instance to use as the background.
 */
@property (nonatomic, retain) UIView* titleBackground;

/**
 The text to display for the period title/name.
 */
@property (nonatomic, copy) NSString* period;

/**
 The text to display for the date.
 */
@property (nonatomic, copy) NSString* date;

/**
 The `AFForecastDetailView` instance for the day portion of the period.
 */
@property (nonatomic, retain) AFForecastDetailView* dayView;

/**
 The `AFForecastDetailView` instance for the night portion of the period.
 */
@property (nonatomic, retain) AFForecastDetailView* nightView;

@end
