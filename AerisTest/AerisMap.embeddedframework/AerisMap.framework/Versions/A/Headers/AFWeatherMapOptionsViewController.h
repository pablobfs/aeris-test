//
//  AFWeatherMapOptionsViewController.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/7/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AFWeatherMap.h"

@interface AFWeatherMapOptionsViewController : UITableViewController {
	AFWeatherMap *_weatherMap;
	NSArray *_sections;
	NSArray *_groupTypeCodes;
	NSMutableDictionary *_cellSelections;
	NSMutableDictionary *_currentRowSelections;
}

/**
 An array of sections and rows for each section defining which map options to display in the table.
 
 By default, this will consist of three sections populated from `[AFWeatherMap supportedOverlays]`:
 - overlays
 - point data
 - base map
 
 To include your own custom options, set the value as an array of sections each containing an NSDictionary of rows.
 **/
@property (nonatomic, retain) NSArray *sections;

@property (nonatomic, retain) AFWeatherMap *weatherMap;

- (id)initWithWeatherMap:(AFWeatherMap *)weatherMap;
- (void)closeOptions;

@end
