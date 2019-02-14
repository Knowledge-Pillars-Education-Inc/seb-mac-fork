//
//  PrefsExamViewController.h
//  SafeExamBrowser
//
//  Created by Daniel R. Schneider on 15.11.12.
//  Copyright (c) 2010-2019 Daniel R. Schneider, ETH Zurich,
//  Educational Development and Technology (LET),
//  based on the original idea of Safe Exam Browser
//  by Stefan Schneider, University of Giessen
//  Project concept: Thomas Piendl, Daniel R. Schneider, Damian Buechel,
//  Dirk Bauer, Kai Reuter, Tobias Halbherr, Karsten Burger, Marco Lehre,
//  Brigitte Schmucki, Oliver Rahs. French localization: Nicolas Dunand
//
//  ``The contents of this file are subject to the Mozilla Public License
//  Version 1.1 (the "License"); you may not use this file except in
//  compliance with the License. You may obtain a copy of the License at
//  http://www.mozilla.org/MPL/
//
//  Software distributed under the License is distributed on an "AS IS"
//  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
//  License for the specific language governing rights and limitations
//  under the License.
//
//  The Original Code is Safe Exam Browser for Mac OS X.
//
//  The Initial Developer of the Original Code is Daniel R. Schneider.
//  Portions created by Daniel R. Schneider are Copyright
//  (c) 2010-2019 Daniel R. Schneider, ETH Zurich, Educational Development
//  and Technology (LET), based on the original idea of Safe Exam Browser
//  by Stefan Schneider, University of Giessen. All Rights Reserved.
//
//  Contributor(s): ______________________________________.
//


#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#import "MBPreferencesController.h"

@interface PrefsExamViewController : NSViewController <MBPreferencesModule, NSTextFieldDelegate> {
    IBOutlet NSTextField *examKey;
	IBOutlet NSTextField *quitURL;
    __weak IBOutlet NSTextField *restartExamURLTextField;

    IBOutlet NSObjectController *controller;
    
    @private
    NSString *_quitLinkBeforeEditing;
}

@property (strong, nonatomic) IBOutlet NSTextField *examKey;

- (BOOL) usingPrivateDefaults;
- (IBAction) generateBrowserExamKey:(id)sender;
- (IBAction) restartExamUseStartURL:(NSButton *)sender;
- (IBAction) restartExamPasswordProtected:(id)sender;
- (void) displayBrowserExamKey;

@end
