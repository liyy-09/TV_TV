//
//  NestSegmentTitleView.h
//  TV_TV
//
//  Created by liyy on 2017/10/31.
//  Copyright © 2017年 ccdc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PointSegmentTitleView;

@protocol NestSegmentTitleViewDelegate <NSObject>

@optional

/**
 切换标题
 
 @param titleView PointSegmentTitleView
 @param startIndex 切换前标题索引
 @param endIndex 切换后标题索引
 */
- (void)NestSegmentTitleView:(PointSegmentTitleView *)titleView startIndex:(NSInteger)startIndex endIndex:(NSInteger)endIndex;

@end

typedef enum : NSUInteger {
    FSIndicatorTypeDefault,     // 默认与按钮长度相同
    FSIndicatorTypeEqualTitle,  // 与文字长度相同
    FSIndicatorTypeCustom,      // 自定义文字边缘延伸宽度
    FSIndicatorTypeNone,
} FSIndicatorType;// 指示器类型枚举


/**
 标题栏的配置View
 */
@interface PointSegmentTitleView : UIView

@property (nonatomic, weak) id<NestSegmentTitleViewDelegate> delegate;

@property (nonatomic, retain) UIView *contentView;

/**
 标题文字间距，默认20
 */
@property (nonatomic, assign) CGFloat itemMargin;

/**
 当前选中标题索引，默认0
 */
@property (nonatomic, assign) NSInteger selectIndex;

/**
 标题字体大小，默认15
 */
@property (nonatomic, strong) UIFont *titleFont;

/**
 标题选中字体大小，默认15
 */
@property (nonatomic, strong) UIFont *titleSelectFont;

/**
 标题正常颜色，默认black
 */
@property (nonatomic, strong) UIColor *titleNormalColor;

/**
 标题选中颜色
 */
@property (nonatomic, strong) UIColor *titleSelectColor;

/**
 指示器颜色，默认与titleSelectColor一样,在FSIndicatorTypeNone下无效
 */
@property (nonatomic, strong) UIColor *indicatorColor;

/**
 在FSIndicatorTypeCustom时可自定义此属性，为指示器一端延伸长度，默认5
 */
@property (nonatomic, assign) CGFloat indicatorExtension;

/**
 对象方法创建FSSegmentTitleView
 
 @param frame frame
 @param titlesArr 标题数组
 @param delegate delegate
 @param incatorType 指示器类型
 @return FSSegmentTitleView
 */
- (instancetype)initWithFrame:(CGRect)frame titles:(NSArray *)titlesArr delegate:(id<NestSegmentTitleViewDelegate>)delegate indicatorType:(FSIndicatorType)incatorType;

/**
 滑动的进度

 @param progress 进度
 */
- (void) moveIndicatorViewProgress:(CGFloat)progress;

@end
