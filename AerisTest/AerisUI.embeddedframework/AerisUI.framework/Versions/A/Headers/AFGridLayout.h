//
//  AFGridLayout.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/2/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import "AFLayout.h"


@interface AFGridLayout : AFLayout {
    NSInteger _columnCount;
	NSInteger _rowCount;
	CGFloat _padding;
	CGFloat _spacing;
}

/**
 Number of columns for the layout.
 */
@property (nonatomic) NSInteger columnCount;

/**
 Number of rows for the layout.
 */
@property (nonatomic) NSInteger rowCount;

/**
 Amount of padding around the layout.
 */
@property (nonatomic) CGFloat padding;

/**
 Amount of spacing between views.
 */
@property (nonatomic) CGFloat spacing;

@end
