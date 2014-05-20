//
//  AFOverlayGroup.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/26/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

typedef enum {
	AFOverlayGroupSingle = 0,
	AFOverlayGroupMultiple
} AFOverlayGroup;

typedef enum {
	AFOverlayGroupTypeImage = 0,
	AFOverlayGroupTypePointData,
	AFOverlayGroupTypePolygon
} AFOverlayGroupType;

#define kAFOverlayGroupTypeCodesArray @"image", @"pointdata", @"polygon", nil