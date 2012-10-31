//
//  uBoardMenuController.m
//  uBoard web board
//
//  Created by Jim Clermonts on 07-09-12.
//
//

#import "ASIHTTPRequest.h"
#import "ASIFormDataRequest.h"
#import "uBoardMenuController.h"
#import "uBoard.h"

@interface uBoardMenuController ()

@end

@implementation uBoardMenuController

@synthesize uboard;
@synthesize availableuBoards;
@synthesize onOffSetting;
@synthesize uBoardNewSetting;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    onOffSetting = false;
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark - ASIHTTP functions

- (void) requestFinished:(ASIHTTPRequest *) request
{
    if(request.tag == 1) {
        NSData *responseData = [request responseData];
    }
}

-(void) requestFailed:(ASIHTTPRequest *) request
{
    NSError *error = [request error];
}

#pragma mark - change uBoard mode

- (void) changeuBoardSetting
{
    NSURL *url = [NSURL URLWithString:@"http://192.168.1.130"];
    ASIHTTPRequest *request = [ASIFormDataRequest requestWithURL:url];
    [request addRequestHeader:@"Referer" value:uBoardNewSetting];
    [request setTag:1];
    [request setTimeOutSeconds:1];
    [request setDelegate:self];
    [request startAsynchronous];
}
    
#pragma mark - buttons on screen
    
- (IBAction)onoffpressed:(id)sender
{
    //    // Toggle on/off
    //    if (onOffSetting == true)
    //    {
    //        onOffSetting = false;
    uBoardNewSetting = @"uBoard leds off";
    [self changeuBoardSetting];
    //    }
    //    else
    //    {
    //        onOffSetting = true;
    //        uBoardNewSetting = @"uBoard leds on";
    //        [self changeuBoardSetting];
    //    }
}
@end
