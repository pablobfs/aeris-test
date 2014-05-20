//
//  AFFlexibleCalloutAnnotationView.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/6/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@interface AFFlexibleCalloutAnnotationView : MKAnnotationView {
	MKAnnotationView *_parentAnnotationView;
	MKMapView *_mapView;
	UIView *_contentView;
	UIView *_loadingView;
	UIActivityIndicatorView *_indicatorView;
	
	CGRect _endFrame;
	CGFloat _yShadowOffset;
	CGPoint _offsetFromParent;
	CGSize _contentSize;
	CGPathRef _pathRef;
}

@property (nonatomic, retain) MKAnnotationView *parentAnnotationView;
@property (nonatomic, retain) MKMapView *mapView;
@property (nonatomic, readonly) UIView *contentView;
@property (nonatomic) CGPoint offsetFromParent;
@property (nonatomic) CGSize contentSize;

- (void)showLoadingView;
- (void)showContentView;
- (void)reset;

@end
