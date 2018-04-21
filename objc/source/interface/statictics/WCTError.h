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

#import <WCDB/Error.hpp>
#import <WCDB/WCTCommon.h>

/**
 It indicates the error type for WCTError. You can see Error::report method in the source code as a practical handling way.
 */
typedef NS_ENUM(int, WCTErrorType) {
    WCTErrorTypeError = 1,
    WCTErrorTypeSQLite = 2,
    WCTErrorTypeHandle = 3,
    WCTErrorTypeCore = 4,
    WCTErrorTypeFile = 5,
};

typedef NS_ENUM(NSUInteger, WCTErrorLevel) {
    WCTErrorLevelIgnore = 1,
    WCTErrorLevelDebug = 2,
    WCTErrorLevelWarning = 3,
    WCTErrorLevelError = 4,
    WCTErrorLevelFatal = 5,
};

NS_ASSUME_NONNULL_BEGIN

/**
 Detailed error
 */
@interface WCTError : NSError

- (WCTErrorType)type;

@property(nonatomic, readonly) WCTErrorLevel level;

@property(nonatomic, readonly) NSString *message;

@end

NS_ASSUME_NONNULL_END
