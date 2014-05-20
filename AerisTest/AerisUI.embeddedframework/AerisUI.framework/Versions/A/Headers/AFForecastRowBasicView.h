//
//  AFForecastRowBasicView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/2/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AFView.h"
#import "AFLabel.h"


@interface AFForecastRowBasicView : AFView {
    AFLabel* _dayView;
	AFLabel* _dateView;
	AFLabel* _weatherView;
	AFLabel* _hightempView;
	AFLabel* _lowtempView;
	UIImageView* _iconView;
}

/**
 The text to display for the day title/name.
 */
@property (nonatomic, retain) NSString* day;

/**
 The text to display for the date.
 */
@property (nonatomic, retain) NSString* date;

/**
 The text to display for the weather phrase.
 */
@property (nonatomic, retain) NSString* weather;

/**
 The text to display for the high temperature.
 */
@property (nonatomic, retain) NSString* hightemp;

/**
 The text to display for the low temperature.
 */
@property (nonatomic, retain) NSString* lowtemp;

/**
 The UIImage to display for the icon.
 */
@property (nonatomic, retain) UIImage* icon;

@end
