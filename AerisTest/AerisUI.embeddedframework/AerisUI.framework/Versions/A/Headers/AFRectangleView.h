//
//  AFRectangleView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 7/29/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface AFRectangleView : UIView {
    
@private
    UIColor* _fillColor;
    
}

/**
 The primary fill color.
 
 The default is `[UIColor grayColor]`.
 */
@property (nonatomic, retain) UIColor* fillColor;

@end
