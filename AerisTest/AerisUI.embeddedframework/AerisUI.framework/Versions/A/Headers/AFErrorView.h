//
//  AFErrorView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/5/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface AFErrorView : UIView {
    UIImageView* _imageView;
	UILabel* _titleView;
	UILabel* _subtitleView;
}

@property (nonatomic, retain) UIImage* image;
@property (nonatomic, copy) NSString* title;
@property (nonatomic, copy) NSString* subtitle;

- (id)initWithTitle:(NSString*)title subtitle:(NSString*)subtitle image:(UIImage*)image;

@end
