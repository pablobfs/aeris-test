//
//  AFCalloutRemoteContentView.h
//  AerisUI
//	$Id$
//
//  Created by Nicholas Shipes on 3/13/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AFCalloutRemoteContentView : UIView

@property (nonatomic, retain) UIView *contentView;

- (void)updateViews:(BOOL)loading;
- (void)showEmptyState;

@end
