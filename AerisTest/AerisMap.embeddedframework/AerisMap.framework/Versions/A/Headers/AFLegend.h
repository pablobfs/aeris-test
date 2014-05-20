//
//  AFLegend.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 9/22/11.
//  Copyright (c) 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisUI/AerisUI.h>

@interface AFLegend : UIView

/**
 Updates which legends are currently displayed based on the active overlays on the map.
 */
- (void)updateLegends;

@end
