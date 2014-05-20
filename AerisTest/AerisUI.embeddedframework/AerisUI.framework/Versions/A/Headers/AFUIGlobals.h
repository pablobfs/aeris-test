//
//  AFUIGlobals.h
//  AerisUI
//	$Id$
//
//  Created by Nicholas Shipes on 8/16/11.
//  Copyright 2011 Urban10 Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


///--------------
/// Color Helpers
///--------------

#define AF_RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define AF_RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]

#define AFCreateUIColorFromHex(hex) [UIColor \
	colorWithRed:((float)((hex & 0xFF0000) >> 16))/255.0 \
	green:((float)((hex & 0xFF00) >> 8))/255.0 \
	blue:((float)(hex & 0xFF))/255.0 alpha:1.0]

#define AFCreateUIColorFromHexWithAlpha (hex,a) [UIColor \
	colorWithRed:((float)((hex & 0xFF0000) >> 16))/255.0 \
	green:((float)((hex & 0xFF00) >> 8))/255.0 \
	blue:((float)(hex & 0xFF))/255.0 alpha:a]

///-------------
/// Math Helpers
///-------------
#define AFRadians(d) d * M_PI / 180.0

///----------
/// Utilities
///----------

/** 
 * Make all categories in the current file loadable without using -load-all.
 *
 * Normally, compilers will skip linking files that contain only categories.
 * Adding a call to this macro adds a dummy class, which causes the linker
 * to add the file.
 *
 * @param UNIQUE_NAME A globally unique name.
 */
#define AFUI_MAKE_CATEGORIES_LOADABLE(UNIQUE_NAME) @interface FORCELOAD_##UNIQUE_NAME @end @implementation FORCELOAD_##UNIQUE_NAME @end

#define AF_IMAGE(name) [UIImage imageNamed:[NSString stringWithFormat:@"AerisUI.bundle/images/%@", [name stringByReplacingOccurrencesOfString:@"gif" withString:@"png"]]]
#define AF_WXICON(name) [UIImage imageNamed:[NSString stringWithFormat:@"AerisUI.bundle/wxicons/%@", [name stringByReplacingOccurrencesOfString:@"gif" withString:@"png"]]]