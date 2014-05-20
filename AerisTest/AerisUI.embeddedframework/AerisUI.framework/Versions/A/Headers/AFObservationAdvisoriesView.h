//
//  AFObservationAdvisoriesView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/2/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AFView.h"
#import "AFLabel.h"


@interface AFObservationAdvisoriesView : UIView {
    NSUInteger _margin;
	
	UIScrollView* _container;
	NSArray* _advisories;
}

/**
 The scrollable container view for the advisory listing.
 */
@property (nonatomic, retain) UIScrollView* container;

/**
 The array of advisories to display.
 */
@property (nonatomic, retain) NSArray* advisories;

@end
