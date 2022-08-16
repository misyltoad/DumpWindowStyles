/* This code was shamelessly stolen from the Wine project,
 * licensed under LGPL v2.1.
 */

#include <windows.h>
#include <stdio.h>

#define WS_EX_DRAGDETECT       __MSABI_LONG(0x00000002) /* Undocumented */

#define TRACE printf

/***********************************************************************
 *           dump_window_styles
 */
static void dump_window_styles( DWORD style, DWORD exstyle )
{
    TRACE( "style:" );
    if(style & WS_POPUP) TRACE(" | WS_POPUP");
    if(style & WS_CHILD) TRACE(" | WS_CHILD");
    if(style & WS_MINIMIZE) TRACE(" | WS_MINIMIZE");
    if(style & WS_VISIBLE) TRACE(" | WS_VISIBLE");
    if(style & WS_DISABLED) TRACE(" | WS_DISABLED");
    if(style & WS_CLIPSIBLINGS) TRACE(" | WS_CLIPSIBLINGS");
    if(style & WS_CLIPCHILDREN) TRACE(" | WS_CLIPCHILDREN");
    if(style & WS_MAXIMIZE) TRACE(" | WS_MAXIMIZE");
    if((style & WS_CAPTION) == WS_CAPTION) TRACE(" | WS_CAPTION");
    else
    {
        if(style & WS_BORDER) TRACE(" | WS_BORDER");
        if(style & WS_DLGFRAME) TRACE(" | WS_DLGFRAME");
    }
    if(style & WS_VSCROLL) TRACE(" | WS_VSCROLL");
    if(style & WS_HSCROLL) TRACE(" | WS_HSCROLL");
    if(style & WS_SYSMENU) TRACE(" | WS_SYSMENU");
    if(style & WS_THICKFRAME) TRACE(" | WS_THICKFRAME");
    if (style & WS_CHILD)
    {
        if(style & WS_GROUP) TRACE(" | WS_GROUP");
        if(style & WS_TABSTOP) TRACE(" | WS_TABSTOP");
    }
    else
    {
        if(style & WS_MINIMIZEBOX) TRACE(" | WS_MINIMIZEBOX");
        if(style & WS_MAXIMIZEBOX) TRACE(" | WS_MAXIMIZEBOX");
    }

    /* FIXME: Add dumping of BS_/ES_/SBS_/LBS_/CBS_/DS_/etc. styles */
#define DUMPED_STYLES \
    ((DWORD)(WS_POPUP | \
     WS_CHILD | \
     WS_MINIMIZE | \
     WS_VISIBLE | \
     WS_DISABLED | \
     WS_CLIPSIBLINGS | \
     WS_CLIPCHILDREN | \
     WS_MAXIMIZE | \
     WS_BORDER | \
     WS_DLGFRAME | \
     WS_VSCROLL | \
     WS_HSCROLL | \
     WS_SYSMENU | \
     WS_THICKFRAME | \
     WS_GROUP | \
     WS_TABSTOP | \
     WS_MINIMIZEBOX | \
     WS_MAXIMIZEBOX))

    if(style & ~DUMPED_STYLES) TRACE(" | %08lx", style & ~DUMPED_STYLES);
    TRACE("\n");
#undef DUMPED_STYLES

    TRACE( "exstyle:" );
    if(exstyle & WS_EX_DLGMODALFRAME) TRACE(" | WS_EX_DLGMODALFRAME");
    if(exstyle & WS_EX_DRAGDETECT) TRACE(" | WS_EX_DRAGDETECT");
    if(exstyle & WS_EX_NOPARENTNOTIFY) TRACE(" | WS_EX_NOPARENTNOTIFY");
    if(exstyle & WS_EX_TOPMOST) TRACE(" | WS_EX_TOPMOST");
    if(exstyle & WS_EX_ACCEPTFILES) TRACE(" | WS_EX_ACCEPTFILES");
    if(exstyle & WS_EX_TRANSPARENT) TRACE(" | WS_EX_TRANSPARENT");
    if(exstyle & WS_EX_MDICHILD) TRACE(" | WS_EX_MDICHILD");
    if(exstyle & WS_EX_TOOLWINDOW) TRACE(" | WS_EX_TOOLWINDOW");
    if(exstyle & WS_EX_WINDOWEDGE) TRACE(" | WS_EX_WINDOWEDGE");
    if(exstyle & WS_EX_CLIENTEDGE) TRACE(" | WS_EX_CLIENTEDGE");
    if(exstyle & WS_EX_CONTEXTHELP) TRACE(" | WS_EX_CONTEXTHELP");
    if(exstyle & WS_EX_RIGHT) TRACE(" | WS_EX_RIGHT");
    if(exstyle & WS_EX_RTLREADING) TRACE(" | WS_EX_RTLREADING");
    if(exstyle & WS_EX_LEFTSCROLLBAR) TRACE(" | WS_EX_LEFTSCROLLBAR");
    if(exstyle & WS_EX_CONTROLPARENT) TRACE(" | WS_EX_CONTROLPARENT");
    if(exstyle & WS_EX_STATICEDGE) TRACE(" | WS_EX_STATICEDGE");
    if(exstyle & WS_EX_APPWINDOW) TRACE(" | WS_EX_APPWINDOW");
    if(exstyle & WS_EX_LAYERED) TRACE(" | WS_EX_LAYERED");
    if(exstyle & WS_EX_NOINHERITLAYOUT) TRACE(" | WS_EX_NOINHERITLAYOUT");
    if(exstyle & WS_EX_LAYOUTRTL) TRACE(" | WS_EX_LAYOUTRTL");
    if(exstyle & WS_EX_COMPOSITED) TRACE(" | WS_EX_COMPOSITED");
    if(exstyle & WS_EX_NOACTIVATE) TRACE(" | WS_EX_NOACTIVATE");

#define DUMPED_EX_STYLES \
    ((DWORD)(WS_EX_DLGMODALFRAME | \
     WS_EX_DRAGDETECT | \
     WS_EX_NOPARENTNOTIFY | \
     WS_EX_TOPMOST | \
     WS_EX_ACCEPTFILES | \
     WS_EX_TRANSPARENT | \
     WS_EX_MDICHILD | \
     WS_EX_TOOLWINDOW | \
     WS_EX_WINDOWEDGE | \
     WS_EX_CLIENTEDGE | \
     WS_EX_CONTEXTHELP | \
     WS_EX_RIGHT | \
     WS_EX_RTLREADING | \
     WS_EX_LEFTSCROLLBAR | \
     WS_EX_CONTROLPARENT | \
     WS_EX_STATICEDGE | \
     WS_EX_APPWINDOW | \
     WS_EX_LAYERED | \
     WS_EX_NOINHERITLAYOUT | \
     WS_EX_LAYOUTRTL | \
     WS_EX_COMPOSITED |\
     WS_EX_NOACTIVATE))

    if(exstyle & ~DUMPED_EX_STYLES) TRACE(" | %08lx", exstyle & ~DUMPED_EX_STYLES);
    TRACE("\n");
#undef DUMPED_EX_STYLES
}

int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("dump_styles: [styles] [styles_ex]\n");
        return 1;
    }

    dump_window_styles((DWORD)atoll(argv[1]), (DWORD)atoll(argv[2]));
    return 0;
}
