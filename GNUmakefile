# GNUmakefile for SmallPaint (Linux/GNUstep)
#
# Simple pixel editor similar to Windows Paint. Uses SmallStepLib for app
# lifecycle, menus, window style, and file dialogs. No extra libraries.
#
# Build SmallStepLib first: cd ../SmallStepLib && make && make install
# Then: make

include $(GNUSTEP_MAKEFILES)/common.make

# Guard: always build the app by default. An explicit .DEFAULT_GOAL makes
# plain 'make' immune to reordering of rules below (e.g. a before-all::
# block before the application.make include would otherwise become the
# default goal and silently skip the app build).
.DEFAULT_GOAL := all

APP_NAME = SmallPaint

SmallPaint_OBJC_FILES = \
	main.m \
	App/AppDelegate.m \
	UI/PaintWindow.m

SmallPaint_HEADER_FILES = \
	App/AppDelegate.h \
	UI/PaintWindow.h

SmallPaint_INCLUDE_DIRS = \
	-I. \
	-IApp \
	-IUI \
	$(SMALLSTEP_INCLUDE_DIRS)

# SmallStep framework (shared discovery - SmallStepLib/GNUmakefile.include)
-include ../SmallStepLib/GNUmakefile.include

SmallPaint_LIBRARIES_DEPEND_UPON = -lobjc -lgnustep-gui -lgnustep-base
SmallPaint_LDFLAGS = $(SMALLSTEP_LIB_PATH) $(SMALLSTEP_LDFLAGS) -Wl,--allow-shlib-undefined
SmallPaint_ADDITIONAL_LDFLAGS = $(SMALLSTEP_LIB_PATH) $(SMALLSTEP_LDFLAGS) -lSmallStep
SmallPaint_TOOL_LIBS = -lSmallStep -lobjc

SmallPaint_RESOURCE_FILES = \
	Resources/SmallPaint.png \
	Resources/logo.png
# Application icon (bare filename; copied into the bundle Resources dir)
SmallPaint_APPLICATION_ICON = SmallPaint.png


include $(GNUSTEP_MAKEFILES)/application.make

# Copy the shared logo into Resources before the build (defined after
# the application.make include so it is not the makefile default goal)
before-all::
	mkdir -p Resources && cp -f ../SmallStepLib/Resources/logo.png Resources/logo.png 2>/dev/null || true

