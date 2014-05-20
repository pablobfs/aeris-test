//
//  AFObservationRowBasicView.h
//  AerisUI
//	$Id$
//
//  Created by Nicholas Shipes on 9/5/12.
//  Copyright (c) 2012 HAMweather, LLC. All rights reserved.
//

#import "AFView.h"
#import "AFLabel.h"

@interface AFObservationRowBasicView : AFView {
	AFLabel *_dayView;
	AFLabel *_timeView;
	AFLabel *_weatherView;
	AFLabel *_tempView;
	UIImageView *_iconView;
}

/**
 The text to display for the day title/name.
 */
@property (nonatomic, copy) NSString *day;

/**
 The text to display for the time.
 */
@property (nonatomic, copy) NSString *time;

/**
 The text to display for the weather phrase.
 */
@property (nonatomic, copy) NSString *weather;

/**
 The text to display for the temperature.
 */
@property (nonatomic, copy) NSString *temp;

/**
 The UIImage to display for the icon.
 */
@property (nonatomic, retain) UIImage *icon;

@end
