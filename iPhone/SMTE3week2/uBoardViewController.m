//
//  uBoardViewController.m
//  uBoard web board
//
//  Created by Jim Clermonts on 26-09-12.
//
//

#import "ASIHTTPRequest.h"
#import "ASIFormDataRequest.h"
#import "uBoard.h"
#import "uBoardViewController.h"
#import "uBoardMenuController.h"

@interface uBoardViewController ()

@end

@implementation uBoardViewController

@synthesize availableuBoards;

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    availableuBoards = [[NSMutableArray alloc]init];

    [self getJSONfromuBoard];
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

- (void) getJSONfromuBoard
{
    //Format NSURL
    // Debug: http://192.168.1.103/~jimclermonts/uBoardwebboard.json
    NSURL *url = [NSURL URLWithString:@"http://145.93.88.208/~jimclermonts/uBoardwebboard.json"];
    ASIHTTPRequest *request = [ASIFormDataRequest requestWithURL:url];
    [request setTag:1];
    [request setDelegate:self];
    [request startAsynchronous];
}

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
            NSLog(@"Waiting for JSON object...");
        }
        else {
            for(int i = 0; i <[uBoardJSON count]; i++)
            {
                uBoard *uboard = [[uBoard alloc]init];
                uboard.identifier = [[uBoardJSON objectAtIndex:i] objectForKey:@"id"];
                uboard.name = [[uBoardJSON objectAtIndex:i] objectForKey:@"name"];
                uboard.ipaddr = [[uBoardJSON objectAtIndex:i] objectForKey:@"ipaddr"];
                uboard.subnetmask = [[uBoardJSON objectAtIndex:i] objectForKey:@"subnetmask"];
                uboard.gateway = [[uBoardJSON objectAtIndex:i] objectForKey:@"gateway"];
                uboard.adjustSpeedOfPattern = [[uBoardJSON objectAtIndex:i] objectForKey:@"adjustSpeedOfPattern"];
                uboard.turnLedsOnOff = [[uBoardJSON objectAtIndex:i] objectForKey:@"turnLedsOnOff"];
                
                [availableuBoards addObject:uboard];
            }
            }
            [self.tableView reloadData];
        }
}

-(void) requestFailed:(ASIHTTPRequest *) request
{
    NSError *error = [request error];
    NSLog(@"Error: %@", error.localizedDescription);
    
    [self getJSONfromuBoard];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    return [availableuBoards count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"uBoardCell"];
    uBoard *uboard = [availableuBoards objectAtIndex:indexPath.row];
    cell.textLabel.text = uboard.name;
    cell.detailTextLabel.text = uboard.ipaddr;
    
    return cell;
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if([[segue identifier] isEqualToString:@"listtodetailview"])
    {
        NSIndexPath *indexPath  = [self.tableView indexPathForSelectedRow];
        uBoardMenuController *detailinfo = segue.destinationViewController;
        uBoard *uboard = [availableuBoards objectAtIndex:[indexPath row]];
        detailinfo.uboard = uboard;
    }
}

@end
