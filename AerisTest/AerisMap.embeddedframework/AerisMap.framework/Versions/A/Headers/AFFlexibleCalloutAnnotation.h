//
//  AFFlexibleCalloutAnnotation.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/16/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import "AFAnnotation.h"


@interface AFFlexibleCalloutAnnotation : AFAnnotation {
	id<MKAnnotation> parentAnnotation_;
	BOOL isDataLoaded_;
}

@property (nonatomic, retain) id<MKAnnotation> parentAnnotation;

@property (nonatomic, assign) BOOL isDataLoaded;

@end
