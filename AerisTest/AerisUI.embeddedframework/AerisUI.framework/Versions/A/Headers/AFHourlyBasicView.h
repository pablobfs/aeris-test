//
//  AFHourlyBasicView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/1/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AFView.h"
#import "AFLabel.h"


@interface AFHourlyBasicView : AFView {	
	AFLabel* _periodView;
	AFLabel* _tempView;
	UIImageView* _iconView;
	UIView* _headerBackground;
}

/**
 The text to display for the period.
 */
@property (nonatomic, retain) NSString* period;

/**
 The text to display for the temperature.
 */
@property (nonatomic, retain) NSString* temp;

/**
 The UIImage instance to display for the icon.
 */
@property (nonatomic, retain) UIImage* icon;

/**
 The UIView instance to display for the header background.
 */
@property (nonatomic, retain) UIView* headerBackground;

@end
