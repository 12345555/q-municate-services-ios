//
//  QMContactsService.h
//  Q-municate
//
//  Created by Ivanov A.V on 14/02/2014.
//  Copyright (c) 2014 Quickblox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QMBaseService.h"

@class QBGeneralResponsePage;
@protocol QMContactsServiceDelegate;

@interface QMContactListService : QMBaseService 

@property (strong, nonatomic, readonly) NSMutableArray *contactList;
@property (strong, nonatomic, readonly) NSMutableSet *confirmRequestUsersIDs;

/**
 *  <#Description#>
 *
 *  @param delegate <#delegate description#>
 */
- (void)addDelegate:(id <QMContactsServiceDelegate>)delegate;

/**
 *  <#Description#>
 *
 *  @param delegate <#delegate description#>
 */
- (void)removeDelegate:(id <QMContactsServiceDelegate>)delegate;

- (NSArray *)friends;
- (void)addUsers:(NSArray *)users;
- (NSArray *)idsWithUsers:(NSArray *)users;
- (NSArray *)usersWithIDs:(NSArray *)ids;
- (void)addUser:(QBUUser *)user;
- (QBUUser *)userWithID:(NSUInteger)userID;
- (NSArray *)checkExistIds:(NSArray *)ids;
- (NSArray *)idsFromContactListItems;
- (NSArray *)contactRequestUsers;
- (QBContactListItem *)contactItemWithUserID:(NSUInteger)userID;
- (NSArray *)usersHistory;

- (void)retrieveUsersWithIDs:(NSArray *)idsToFetch
                  completion:(void(^)(QBResponse *responce, QBGeneralResponsePage *page, NSArray * users))completion;

- (void)addUserToContactListRequest:(QBUUser *)user
                         completion:(void(^)(BOOL success))completion;

- (void)removeUserFromContactListWithUserID:(NSUInteger)userID
                                 completion:(void(^)(BOOL success))completion;

- (void)confirmAddContactRequest:(NSUInteger)userID
                      completion:(void (^)(BOOL success))completion;

- (void)rejectAddContactRequest:(NSUInteger)userID
                     completion:(void(^)(BOOL success))completion;

@end

@protocol QMContactsServiceDelegate <NSObject>
@optional
- (void)contactsServiceContactListDidUpdate;
- (void)contactsServiceContactRequestUsersListChanged;
- (void)contactsServiceUsersHistoryUpdated;
@end