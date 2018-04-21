/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <WCDB/WCTDatabase.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^WCTTableMigratedBlock)(WCTMigrationInfo *);

typedef BOOL (^WCTMigrationSteppedBlock)(WCTMigrationInfo *, BOOL);

typedef void (^WCTMigrationCompletedBlock)(BOOL);

@interface WCTMigrationDatabase : WCTDatabase

- (nullable instancetype)initWithPath:(NSString *)path
                              andInfo:(WCTMigrationInfo *)info;

- (nullable instancetype)initWithPath:(NSString *)path
                             andInfos:(NSArray<WCTMigrationInfo *> *)infos;

- (nullable instancetype)initWithExistingPath:(NSString *)path;

- (BOOL)stepMigration:(BOOL &)done;

- (BOOL)stepMigration:(BOOL &)done
      onTableMigrated:(nullable WCTTableMigratedBlock)block;

- (void)asyncMigration:(double)interval
       onTableMigrated:(nullable WCTTableMigratedBlock)onTableMigrated
           onCompleted:(nullable WCTMigrationCompletedBlock)onMigrationCompleted;

- (void)asyncMigrationOnStepped:(nullable WCTMigrationSteppedBlock)onStepped
                onTableMigrated:(nullable WCTTableMigratedBlock)onTableMigrated
                    onCompleted:(nullable WCTMigrationCompletedBlock)onMigrationCompleted;

@end

NS_ASSUME_NONNULL_END
