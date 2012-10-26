//
//  uBoard.h
//  uBoard web board
//
//  Created by Jim Clermonts on 17-10-12.
//
//

#import <Foundation/Foundation.h>

@interface uBoard : NSObject
{
}

@property (nonatomic, copy) NSString *identifier, *name, *ipaddr, *subnetmask, *gateway, *adjustSpeedOfPattern, *turnLedsOnOff;

@end
