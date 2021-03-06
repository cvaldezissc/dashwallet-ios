//
//  Created by Andrew Podkovyrin
//  Copyright © 2019 Dash Core Group. All rights reserved.
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

NS_ASSUME_NONNULL_BEGIN

@class DWAmountViewController;
@class DSPaymentProtocolDetails;

@protocol DWAmountViewControllerDelegate <NSObject>

- (void)amountViewControllerDidCancel:(DWAmountViewController *)controller;

@optional
- (void)amountViewController:(DWAmountViewController *)controller didInputAmount:(uint64_t)amount;
- (void)amountViewController:(DWAmountViewController *)controller didInputAmount:(uint64_t)amount wasProposedToUseInstantSend:(BOOL)wasProposedInstantSend usedInstantSend:(BOOL)usedInstantSend;

@end

@interface DWAmountViewController : KVOUIViewController

@property (nullable, weak, nonatomic) id<DWAmountViewControllerDelegate> delegate;

+ (instancetype)requestController;
+ (instancetype)sendControllerWithDestination:(NSString *)sendingDestination
                               paymentDetails:(nullable DSPaymentProtocolDetails *)paymentDetails;

- (void)setInstantSendEnabled;

@end

NS_ASSUME_NONNULL_END
