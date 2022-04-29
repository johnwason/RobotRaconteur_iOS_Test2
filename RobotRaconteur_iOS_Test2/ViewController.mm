//
//  ViewController.m
//  RobotRaconteur_iOS_Test2
//
//  Created by John Wason on 4/27/22.
//

#import "ViewController.h"
#include "RRTest.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    rr_init();
}

- (IBAction)runTest:(id)sender {
    UIAlertController * alert = [UIAlertController
                    alertControllerWithTitle:@"Title"
                                     message:@"Tests Complete!"
                              preferredStyle:UIAlertControllerStyleAlert];



    UIAlertAction* yesButton = [UIAlertAction
                        actionWithTitle:@"Close"
                                  style:UIAlertActionStyleDefault
                                handler:^(UIAlertAction * action) {
                                    //Handle your yes please button action here
                                }];
    
    [alert addAction:yesButton];
    
    
    rr_runtest();

    [self presentViewController:alert animated:YES completion:nil];}

@end
