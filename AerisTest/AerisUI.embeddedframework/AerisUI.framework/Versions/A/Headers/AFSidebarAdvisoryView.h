//
//  AFSidebarAdvisoryView.h
//  AerisSamples
//	$Id$
//
//  Created by Nick Shipes on 8/12/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AFView.h"
#import "AFLabel.h"

@interface AFSidebarAdvisoryView : AFView {
	UIScrollView* _container;
	NSArray* _advisories;
}

@property (nonatomic, retain) UIScrollView* container;
@property (nonatomic, retain) NSArray* advisories;

@end
