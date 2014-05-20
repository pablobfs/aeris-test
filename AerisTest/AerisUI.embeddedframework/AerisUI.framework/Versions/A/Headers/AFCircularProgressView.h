//
//  AFProgressView.h
//  AerisUI
//	$Id$
//
//  Created by Nicholas Shipes on 4/6/12.
//  Copyright (c) 2012 Urban10 Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@interface AFCircularProgressLayer : CALayer

@property (nonatomic) CGFloat progress;

@end


@interface AFCircularProgressView : UIView

@property (nonatomic) CGFloat progress;

@property (nonatomic, retain) UIColor *backgroundColor;

@property (nonatomic, retain) UIColor *borderColor;

@property (nonatomic) CGFloat borderWidth;

- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;

@end
