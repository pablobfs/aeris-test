//
//  AFCalloutView.h
//  AerisUI
//	$Id$
//
//	Based on the SMCallout class originally developed by Nick Farina (@nfarina)
//	and contributed to by Nicholas Shipes: https://github.com/u10int/calloutview
//
//  Created by Nicholas Shipes on 1/22/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

// options for which directions the callout is allowed to "point" in.
enum {
    AFCalloutArrowDirectionUp = 1UL << 0,
    AFCalloutArrowDirectionDown = 1UL << 1,
    AFCalloutArrowDirectionAny = AFCalloutArrowDirectionUp | AFCalloutArrowDirectionDown
};
typedef NSUInteger AFCalloutArrowDirection;

// options for the callout present/dismiss animation
enum {
    AFCalloutAnimationBounce, // the "bounce" animation we all know and love from UIAlertView
    AFCalloutAnimationFade, // a simple fade in or out
    AFCalloutAnimationStretch // grow or shrink linearly, like in the iPad Calendar app
};
typedef NSInteger AFCalloutAnimation;

// when delaying our popup in order to scroll content into view, you can use this amount to match the
// animation duration of UIScrollView when using -setContentOffset:animated.
extern NSTimeInterval kAFCalloutViewRepositionDelayForUIScrollView;

@protocol AFCalloutViewDelegate;

//
// Callout view.
//
@interface AFCalloutView : UIView

@property (nonatomic, assign) id<AFCalloutViewDelegate> delegate;
@property (nonatomic, copy) NSString *title, *subtitle; // title/titleView relationship mimics UINavigationBar.
@property (nonatomic, retain) UIView *leftAccessoryView, *rightAccessoryView;

// Custom title/subtitle views. if these are set, the respective title/subtitle properties will be ignored.
// Keep in mind that AFCalloutView calls -sizeThatFits on titleView/subtitleView if defined, so your view
// may be resized as a result of that (especially if you're using UILabel/UITextField). You may want to subclass
// and override -sizeThatFits, or just wrap your view in a "generic" UIView if you do not want it to be auto-sized.
@property (nonatomic, retain) UIView *titleView, *subtitleView;

// Custom "content" view that can be any width/height. If this is set, title/subtitle/titleView/subtitleView are all ignored.
@property (nonatomic, retain) UIView *contentView;

// calloutOffset is the offset in screen points from the top-middle of the annotation view, where the anchor of the callout should be shown.
@property (nonatomic, assign) CGPoint calloutOffset;

@property (nonatomic, assign) AFCalloutAnimation presentAnimation, dismissAnimation; // default AFCalloutAnimationBounce, AFCalloutAnimationFade respectively

// Presents a callout view by adding it to "inView" and pointing at the given rect of inView's bounds.
// Constrains the callout to the bounds of the given view. Optionally scrolls the given rect into view (plus margins)
// if -delegate is set and responds to -delayForRepositionWithSize.
- (void)presentCalloutFromRect:(CGRect)rect inView:(UIView *)view constrainedToView:(UIView *)constrainedView permittedArrowDirections:(AFCalloutArrowDirection)arrowDirections animated:(BOOL)animated;

// Same as the view-based presentation, but inserts the callout into a CALayer hierarchy instead. Be aware that you'll have to direct
// your own touches to any accessory views, since CALayer doesn't relay touch events.
- (void)presentCalloutFromRect:(CGRect)rect inLayer:(CALayer *)layer constrainedToLayer:(CALayer *)constrainedLayer permittedArrowDirections:(AFCalloutArrowDirection)arrowDirections animated:(BOOL)animated;

- (void)dismissCalloutAnimated:(BOOL)animated;

@end

@protocol AFCalloutViewDelegate <NSObject>
@optional

// Called when the callout view detects that it will be outside the constrained view when it appears,
// or if the target rect was already outside the constrained view. You can implement this selector to
// respond to this situation by repositioning your content first in order to make everything visible. The
// CGSize passed is the calculated offset necessary to make everything visible (plus a nice margin).
// It expects you to return the amount of time you need to reposition things so the popup can be delayed.
// Typically you would return kAFCalloutViewRepositionDelayForUIScrollView if you're repositioning by
// calling [UIScrollView setContentOffset:animated:].
- (NSTimeInterval)calloutView:(AFCalloutView *)calloutView delayForRepositionWithSize:(CGSize)offset;

// Called after the callout view appears on screen, or after the appearance animation is complete.
- (void)calloutViewDidAppear:(AFCalloutView *)calloutView;

// Called after the callout view is removed from the screen, or after the disappearance animation is complete.
- (void)calloutViewDidDisappear:(AFCalloutView *)calloutView;

@end