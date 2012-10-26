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
#import "uBoardViewController.h"
#import "uBoard.h"

@interface uBoardMenuController ()

@end

@implementation uBoardMenuController

@synthesize uboard;
@synthesize availableuBoards;
@synthesize onOffSetting;
@synthesize speedSetting;
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
        NSError* error;
        
        // JSON is NSArray:
        NSArray *uBoardJSON = [NSJSONSerialization JSONObjectWithData:responseData
                                                              options:NSJSONReadingMutableContainers
                                                                error:&error];
        
        if(!uBoardJSON || ![uBoardJSON count]) {
            NSLog(@"Waiting for glow events info...");
        }
        else {
            NSLog(@"%@",uBoardJSON);
        }
    }
}

-(void) requestFailed:(ASIHTTPRequest *) request
{
    NSError *error = [request error];
    NSLog(@"Error: %@", error.localizedDescription);
    
//    [self changeuBoardSetting];
}

#pragma mark - change uBoard mode

- (void) changeuBoardSetting
{
    // Debug: http://192.168.1.103/~jimclermonts/uBoardwebboard.json
    NSURL *url = [NSURL URLWithString:@"http://145.93.88.208/~jimclermonts/uBoardwebboard.json"];
    ASIHTTPRequest *request = [ASIFormDataRequest requestWithURL:url];
    [request addRequestHeader:@"Referer" value:uBoardNewSetting];
    [request setTag:1];
    [request setDelegate:self];
    [request startAsynchronous];
}

#pragma mark - buttons on screen

- (IBAction)onoffpressed:(id)sender
{
    //    [self getJSONfromuBoard];
    
    
    // Toggle on/off
    if (onOffSetting == true)
    {
        onOffSetting = false;
//        uBoardNewSetting = @"uBoard leds off";
        [self changeuBoardSetting];
    }
    else
    {
        onOffSetting = true;
        uBoardNewSetting = @"uBoard leds on";
        [self changeuBoardSetting];
    }
    
}

- (IBAction)adjustspeedpressed:(id)sender {
    uBoardNewSetting = @"";
}
@end
