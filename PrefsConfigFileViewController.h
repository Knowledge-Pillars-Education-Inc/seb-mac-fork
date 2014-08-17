//
//  PrefsExamViewController.h
//  SafeExamBrowser
//
//  Created by Daniel R. Schneider on 15.11.12.
//  Copyright (c) 2010-2014 Daniel R. Schneider, ETH Zurich,
//  Educational Development and Technology (LET),
//  based on the original idea of Safe Exam Browser
//  by Stefan Schneider, University of Giessen
//  Project concept: Thomas Piendl, Daniel R. Schneider,
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
//  (c) 2010-2014 Daniel R. Schneider, ETH Zurich, Educational Development
//  and Technology (LET), based on the original idea of Safe Exam Browser
//  by Stefan Schneider, University of Giessen. All Rights Reserved.
//
//  Contributor(s): ______________________________________.
//


#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#import "MBPreferencesController.h"
#import "PreferencesController.h"
#import "SEBKeychainManager.h"
#import "Constants.h"

@class PreferencesController;

@interface PrefsConfigFileViewController : NSViewController <MBPreferencesModule> {
    IBOutlet NSPopUpButton *chooseIdentity;

	//IBOutlet NSButtonCell *sebStartsExam;
	//IBOutlet NSButtonCell *sebConfiguresClient;
	IBOutlet NSButton *saveSEBPrefsButton;
    IBOutlet NSObjectController *controller;

    @private
    NSMutableString *settingsPassword;
	NSMutableString *confirmSettingsPassword;
	IBOutlet NSMatrix *sebPurpose;
    IBOutlet NSSecureTextField *settingsPasswordField;
    IBOutlet NSSecureTextField *confirmSettingsPasswordField;
}

@property (weak, nonatomic) PreferencesController *preferencesController;
@property (strong, nonatomic) SEBKeychainManager *keychainManager;

@property (strong, nonatomic) NSMutableArray *identitiesNames;
@property (strong, nonatomic) NSArray *identities;

@property BOOL configPasswordIsHash;
@property (readonly) BOOL usingPrivateDefaults;

// Write-only properties
@property (nonatomic) NSString *currentConfigFilePassword;
@property (nonatomic) SecKeyRef currentConfigFileKeyRef;


// To make the getter unavailable
- (SecKeyRef)currentConfigFileKeyRef UNAVAILABLE_ATTRIBUTE;

- (BOOL) usingPrivateDefaults;

- (void) resetSettingsPasswordFields;
- (void) resetSettingsIdentity;
- (void) setSettingsPassword:(NSString *)password isHash:(BOOL)passwordIsHash;
- (void) selectSettingsIdentity:(SecKeyRef)settingsPrivateKeyRef;
- (SecIdentityRef) getSelectedIdentity;
- (sebConfigPurposes) getSelectedConfigPurpose;
- (NSData *) encryptSEBSettingsWithSelectedCredentials;

- (IBAction) changeConfigFilePurpose:(id)sender;

//- (IBAction) saveSEBPrefs:(id)sender;
//- (IBAction) saveSEBPrefsAs:(id)sender;
//- (IBAction) openSEBPrefs:(id)sender;

@end