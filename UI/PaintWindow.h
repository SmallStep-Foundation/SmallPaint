//
//  PaintWindow.h
//  SmallPaint
//
//  Main window: canvas in scroll view, tool strip, color. Handles New/Open/Save via SSFileDialog.
//

#import <AppKit/AppKit.h>

@class CanvasView;

@interface PaintWindow : NSWindow
{
#if defined(GNUSTEP) && !__has_feature(objc_arc)
    NSScrollView *_scrollView;
    CanvasView *_canvasView;
    NSView *_toolStrip;
    NSButton *_pencilButton;
    NSButton *_eraserButton;
    NSButton *_colorButton;
    NSView *_colorSwatch;
    NSString *_documentPath;  /* nil if unsaved */
    BOOL _documentDirty;
#endif
}

- (void)newDocument;
- (void)openDocument;
- (void)saveDocument;
- (void)saveDocumentAs;
- (void)clearDocument;

@end
