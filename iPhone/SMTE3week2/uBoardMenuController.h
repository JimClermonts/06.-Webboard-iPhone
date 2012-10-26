//
//  uBoardMenuController.h
//  uBoard web board
//
//  Created by Jim Clermonts on 07-09-12.
//
//

#import <UIKit/UIKit.h>
#import "uBoard.h"

@interface uBoardMenuController : UIViewController
{
//    __weak IBOutlet UIButton *adjustspeedbtn;
    __weak IBOutlet UIButton *onoffbtn;
}

- (IBAction)onoffpressed:(id)sender;
//- (IBAction)adjustspeedpressed:(id)sender;
- (IBAction)adjustspeedpressed:(id)sender;

@property (nonatomic, strong) uBoard *uboard;
@property (nonatomic, strong) NSMutableArray * availableuBoards;
@property (nonatomic) bool onOffSetting;
@property (nonatomic, strong) NSString * speedSetting;
@property (nonatomic, strong) NSString * uBoardNewSetting;

@end
