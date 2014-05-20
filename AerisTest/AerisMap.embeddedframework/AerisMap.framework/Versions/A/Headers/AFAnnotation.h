//
//  AFAnnotation.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/6/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@interface AFAnnotation : NSObject <MKAnnotation> {
	CLLocationCoordinate2D _coordinate;
	NSString *_title;
	NSString *_subtitle;
	NSObject *_model;
	NSString *_identifier;
}

@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, readonly) NSObject *model;
@property (nonatomic, readonly) NSString *identifier;

- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate;
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate model:(NSObject *)model;

@end
