//
//  PatternControllerViewController.m
//  uBoard web board
//
//  Created by Jim Clermonts on 17-10-12.
//
//

#import "ASIHTTPRequest.h"
#import "ASIFormDataRequest.h"
#import "PatternControllerViewController.h"

@interface PatternControllerViewController ()

@end

@implementation PatternControllerViewController

@synthesize uBoardNewSet;

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

    uBoardNewSet = @"";
}

- (void)viewDidAppear:(BOOL)animated
{
    [self becomeFirstResponder];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [self becomeFirstResponder];    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)canBecomeFirstResponder
{
    return YES;
}

- (void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent *)event
{
    uBoardNewSet = @"uBoard new color";
    [self changeuBoardSet];
    NSLog(@"shake detected!\n");
    
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
    
    [self changeuBoardSet];
}

- (void) changeuBoardSet
{
    // Debug: http://192.168.1.103/~jimclermonts/uBoardwebboard.json
    NSURL *url = [NSURL URLWithString:@"http://192.168.1.130"];
    ASIHTTPRequest *request = [ASIFormDataRequest requestWithURL:url];
    [request addRequestHeader:@"Referer" value:uBoardNewSet];
    [request setTag:1];
    [request setDelegate:self];
    [request startAsynchronous];
}

#pragma mark - change uBoard mode

@end
