//
//  AFStormCellsTableViewCell.h
//  AerisSamples
//  $Id$
//
//  Created by Nick Shipes on 8/3/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AFView.h"
#import "AFLabel.h"

@interface AFStormCellsTableViewCell : UITableViewCell {
    AFLabel* _primaryText;
    AFLabel* _secondaryText;
	UIImageView* _icon;
}

@property (nonatomic, retain) AFLabel* primaryText;
@property (nonatomic, retain) AFLabel* secondaryText;
@property (nonatomic, retain) UIImageView* icon;

@end
