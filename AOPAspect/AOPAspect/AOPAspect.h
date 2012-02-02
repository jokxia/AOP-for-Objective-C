//
//  AOPAspect.h
//  AOPAspect
//
//  Created by Andras Koczka on 1/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^aspect_block_t)(NSInvocation *invocation);

@interface AOPAspect : NSObject

// Intercept methods return an identifier that can be used for deregistration with the removeInterceptorWithIdentifier method
// Only instance methods can be intercepted
- (NSString *)interceptClass:(Class)aClass beforeExecutingSelector:(SEL)selector usingBlock:(aspect_block_t)block;
- (NSString *)interceptClass:(Class)aClass afterExecutingSelector:(SEL)selector usingBlock:(aspect_block_t)block;
- (NSString *)interceptClass:(Class)aClass insteadExecutingSelector:(SEL)selector usingBlock:(aspect_block_t)block;

// Removes an interceptor block
- (void)removeInterceptorWithIdentifier:(NSString *)identifier;

// Use this method to get the AOPAspect instance. Don't use alloc/init.
+ (AOPAspect *)instance;

@end
