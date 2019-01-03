//
//  Created by Andrew Podkovyrin
//  Copyright © 2018 Dash Core Group. All rights reserved.
//
//  Licensed under the MIT License (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  https://opensource.org/licenses/MIT
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <KVO-MVVM/KVOUIViewController.h>

#import "DWAlertViewControllerKeyboardSupport.h"
#import "DWUpholdOTPProvider.h"

NS_ASSUME_NONNULL_BEGIN

@class DWUpholdCardObject;
@class DWUpholdTransactionObject;
@class DWUpholdConfirmTransferViewController;

@protocol DWUpholdConfirmTransferViewControllerDelegate <NSObject>

- (void)upholdConfirmTransferViewControllerDidCancel:(DWUpholdConfirmTransferViewController *)controller;
- (void)upholdConfirmTransferViewControllerDidFinish:(DWUpholdConfirmTransferViewController *)controller
                                         transaction:(DWUpholdTransactionObject *)transaction;

@end

@interface DWUpholdConfirmTransferViewController : KVOUIViewController <DWAlertViewControllerKeyboardSupport>

@property (nullable, weak, nonatomic) id<DWUpholdConfirmTransferViewControllerDelegate> delegate;
@property (nullable, weak, nonatomic) id<DWUpholdOTPProvider> otpProvider;

+ (instancetype)controllerWithCard:(DWUpholdCardObject *)card transaction:(DWUpholdTransactionObject *)transaction;

@end

NS_ASSUME_NONNULL_END