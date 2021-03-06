/*
	IKThumbnailProvider.h

	IconKit thumbnail provider class which permits to obtain and store thumbnails  
	with a standard architecture available for the GNUstep applications (it is 
	possible to store custom thumbnails)
	IKThumbnailProvider is Freedesktop compatible
	
	Copyright (C) 2004 Nicolas Roard <nicolas@roard.com>
	                   Quentin Mathe <qmathe@club-internet.fr>	                   

	Author:   Nicolas Roard <nicolas@roard.com>
	          Quentin Mathe <qmathe@club-internet.fr>
	Date:  August 2004

    This application is free software; you can redistribute it and/or 
    modify it under the terms of the 3-clause BSD license. See COPYING.
*/

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

typedef enum _IKThumbnailSize
{
  IKThumbnailSizeNormal,
  IKThumbnailSizeLarge
} IKThumbnailSize;

@interface IKThumbnailProvider : NSObject
{

}

+ (IKThumbnailProvider *) sharedInstance;

/*
 * Thumbnails are stored in ~/GNUstep/Library/Caches/IconKit/Thumbnails.
 * For Freedesktop compatibility, we add ~/.thumbnails soft link to the default
 * path.
 * The directory structure is
 * Thumbnails/normal which contains thumbnails with 128*128 size
 * Thumbnails/large which contains thumbnails with 256*256 size
 * Thumbnails/fail which tracks thumbnails creation errors.
 * Each thumbnail name is a MD5 hash of the original file URL.
 * Delete not valid thumbnails is the job of the user Workspace application.
 */

- (NSImage *) thumbnailForURL: (NSURL *)url 
                         size: (IKThumbnailSize)thumbnailSize;
- (NSImage *) thumbnailForPath: (NSString *)path 
                          size: (IKThumbnailSize) thumbnailSize;

- (void) setThumbnail: (NSImage *)thumbnail forURL: (NSURL *)url;
- (void) setThumbnail: (NSImage *)thumbnail forPath: (NSString *)path;

- (void) recacheForURL: (NSURL *)url;
- (void) recacheForPath: (NSString *)path;
- (void) invalidCacheForURL: (NSURL *)url;
- (void) invalidCacheForPath: (NSString *)path;
- (void) invalidCacheAll;

@end
