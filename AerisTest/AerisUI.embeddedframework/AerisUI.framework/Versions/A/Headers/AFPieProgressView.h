//
//  AFPieProgressView.h
//  AerisUI
//	$Id$
//
//  Created by Nicholas Shipes on 4/2/12.
//  Copyright (c) 2012 Urban10 Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AFPieProgressView : UIView

@property (nonatomic, assign) CGFloat progress;

@property (nonatomic, assign) CGFloat pieBorderWidth;

@property (nonatomic, retain) UIColor *pieBorderColor;

@property (nonatomic, retain) UIColor *pieFillColor;

@property (nonatomic, retain) UIColor *pieBackgroundColor;

+ (UIColor *)defaultPieColor;

@end
