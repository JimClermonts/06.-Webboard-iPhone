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

@synthesize uBoardNewColor;

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
    uBoardNewColor = @"uBoard new color";
    [self changeuBoardColor];
    NSLog(@"shake detected!\n");
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

- (void) changeuBoardColor
{
    NSURL *url = [NSURL URLWithString:@"http://192.168.1.130"];
    ASIHTTPRequest *request = [ASIFormDataRequest requestWithURL:url];
    [request addRequestHeader:@"Referer" value:uBoardNewColor];
    [request setTag:1];
    [request setTimeOutSeconds:1];
    [request setDelegate:self];
    [request startAsynchronous];
}

@end
