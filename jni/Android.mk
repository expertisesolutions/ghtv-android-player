# (c) Copyright 2010,2011 Felipe Magno de Almeida
#
# This work is licensed under the Creative Commons
# Attribution-NonCommercial-NoDerivs 3.0 License.
# To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/3.0/
# or send a letter to:
#      Creative Commons
#      171 2nd Street, Suite 300
#      San Francisco, California, USA.

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := ghtv-ncl-player
LOCAL_CFLAGS    := -Werror -I$(GHTV_GNTL_PATH)/include -I$(BOOST_ROOT) -D_BIG_ENDIAN -I$(LOCAL_PATH)/include
LOCAL_SRC_FILES := main.cpp
LOCAL_LDLIBS    := -lGLESv2 -llog
#LOCAL_STATIC_LIBRARIES := android_native_app_glue

include $(BUILD_SHARED_LIBRARY)

#$(call import-module,android/native_app_glue)
