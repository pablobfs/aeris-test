//
//  MapViewController.m
//  AerisTest
//
//  Created by Ignacio Rodrigo on 5/20/14.
//  Copyright (c) 2014 Ignacio Rodrigo. All rights reserved.
//

#import "MapViewController.h"

@interface MapViewController ()

@property AFWeatherMap *weatherMap;

@end

@implementation MapViewController

- (void)showMapOptions {
    AFWeatherMapOptionsViewController *optionsController = [[AFWeatherMapOptionsViewController alloc] initWithWeatherMap:self.weatherMap];
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:optionsController];
    [self presentViewController:navController animated:YES completion:nil];
}

@end
