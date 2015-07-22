//
//  UIView+XY.h
//  TWP_SkyBookShelf
//
//  Created by Heaven on 13-7-31.
//
//

#import <UIKit/UIKit.h>

#define UIView_shadeTag 26601
#define UIView_activityIndicatorViewTag 26602

#define UIView_animation_instant 0.15

typedef void(^UIViewCategoryNormalBlock)(UIView *view);
typedef void(^UIViewCategoryAnimationBlock)(void);
@interface UIView (XY)

// 增加手势
- (void)uxy_addTapGestureWithTarget:(id)target action:(SEL)action;
- (void)uxy_addTapGestureWithBlock:(UIViewCategoryNormalBlock)aBlock;
- (void)uxy_removeTapGesture;

- (void)uxy_addLongPressGestureWithBlock:(UIViewCategoryNormalBlock)aBlock;
- (void)uxy_removeLongPressGesture;

// 增加背景阴影
- (void)uxy_addShadeWithTarget:(id)target action:(SEL)action color:(UIColor *)aColor alpha:(float)aAlpha;
- (void)uxy_addShadeWithBlock:(UIViewCategoryNormalBlock)aBlock color:(UIColor *)aColor alpha:(float)aAlpha;
// 增加毛玻璃背景
- (void)uxy_addBlurWithTarget:(id)target action:(SEL)action;
- (void)uxy_addBlurWithTarget:(id)target action:(SEL)action level:(int)lv;
- (void)uxy_addBlurWithBlock:(UIViewCategoryNormalBlock)aBlock;
- (void)uxy_addBlurWithBlock:(UIViewCategoryNormalBlock)aBlock level:(int)lv;

- (void)uxy_removeShade;
- (UIView *)uxy_shadeView;

// 设置背景
- (instancetype)uxy_bg:(NSString *)str;

// 旋转 1.0:顺时针180度
- (instancetype)uxy_rotate:(CGFloat)angle;

// 圆形
- (instancetype)uxy_rounded;
- (instancetype)uxy_rounded2;
// 圆角矩形, corners:一个矩形的四个角。
- (instancetype)uxy_roundedRectWith:(CGFloat)radius;
- (instancetype)uxy_roundedRectWith:(CGFloat)radius byRoundingCorners:(UIRectCorner)corners;

// 边框大小,颜色
- (instancetype)uxy_borderWidth:(CGFloat)width color:(UIColor *)color;

// 活动指示器
- (UIActivityIndicatorView *)uxy_activityIndicatorViewShow;
- (void)uxy_activityIndicatorViewHidden;

// 截屏
- (UIImage *)uxy_snapshot;

// 淡出,然后移除
- (void)uxy_removeFromSuperviewWithCrossfade;

- (void)uxy_removeAllSubviews;
- (void)uxy_removeSubviewWithTag:(NSInteger)tag;
- (void)uxy_removeSubviewExceptTag:(NSInteger)tag;

// 是否显示在屏幕上
- (BOOL)uxy_isDisplayedInScreen;

#pragma mark -todo attribute
- (void)uxy_showDataWithDic:(NSDictionary *)dic;

// 子类需要重新此方法
//+ (void)setupDataBind:(NSMutableDictionary *)dic;

#pragma mark - animation
// 淡入淡出
- (void)uxy_animationCrossfadeWithDuration:(NSTimeInterval)duration;
- (void)uxy_animationCrossfadeWithDuration:(NSTimeInterval)duration completion:(UIViewCategoryAnimationBlock)completion;

/** 立方体翻转
 *kCATransitionFromRight, kCATransitionFromLeft, kCATransitionFromTop, kCATransitionFromBottom
 */
- (void)uxy_animationCubeWithDuration:(NSTimeInterval)duration direction:(NSString *)direction;
- (void)uxy_animationCubeWithDuration:(NSTimeInterval)duration direction:(NSString *)direction completion:(UIViewCategoryAnimationBlock)completion;

/** 翻转
 *kCATransitionFromRight, kCATransitionFromLeft, kCATransitionFromTop, kCATransitionFromBottom
 */
- (void)uxy_animationOglFlipWithDuration:(NSTimeInterval)duration direction:(NSString *)direction;
- (void)uxy_animationOglFlipWithDuration:(NSTimeInterval)duration direction:(NSString *)direction completion:(UIViewCategoryAnimationBlock)completion;

/** 覆盖
 *kCATransitionFromRight, kCATransitionFromLeft, kCATransitionFromTop, kCATransitionFromBottom
 */
- (void)uxy_animationMoveInWithDuration:(NSTimeInterval)duration direction:(NSString *)direction;
- (void)uxy_animationMoveInWithDuration:(NSTimeInterval)duration direction:(NSString *)direction completion:(UIViewCategoryAnimationBlock)completion;

// 抖动
- (void)uxy_animationShake;

// 返回所在的vc
- (UIViewController *)uxy_currentViewController;

@end






