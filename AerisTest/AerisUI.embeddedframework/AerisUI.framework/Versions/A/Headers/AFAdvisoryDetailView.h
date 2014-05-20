//
//  AFAdvisoryDetailView.h
//  AerisSamples
//	$Id$
//
//  Created by Nicholas Shipes on 8/5/11.
//  Copyright 2011 WeatherNation, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AFView.h"
#import "AFLabel.h"


@interface AFAdvisoryDetailView : AFView {
    AFLabel* _nameView;
	AFLabel* _expiresView;
	AFLabel* _bodyView;
}

/**
 The text to display for the title for the advisory.
 */
@property (nonatomic, copy) NSString* name;

/**
 The text to display for the expiration for the advisory.
 */
@property (nonatomic, copy) NSString* expires;

/**
 The text to display for the body of the advisory.
 */
@property (nonatomic, copy) NSString* body;

@end
