//
//  AFSidebarObservationView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/10/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AFView.h"
#import "AFLabel.h"


@interface AFSidebarObservationView : AFView {
    UIImageView* _icon;
	AFLabel* _location;
	AFLabel* _temp;
	AFLabel* _weather;
	AFLabel* _feelslike;
	AFLabel* _winds;
	AFLabel* _humidity;
	AFLabel* _dewpoint;
	AFLabel* _pressure;
}

@property (nonatomic, retain) UIImageView* icon;
@property (nonatomic, retain) AFLabel* location;
@property (nonatomic, retain) AFLabel* temp;
@property (nonatomic, retain) AFLabel* weather;
@property (nonatomic, retain) AFLabel* feelslike;
@property (nonatomic, retain) AFLabel* winds;
@property (nonatomic, retain) AFLabel* humidity;
@property (nonatomic, retain) AFLabel* dewpoint;
@property (nonatomic, retain) AFLabel* pressure;

@end
