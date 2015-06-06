// (c) Copyright 2010,2011 Felipe Magno de Almeida
//
// This work is licensed under the Creative Commons
// Attribution-NonCommercial-NoDerivs 3.0 License.
// To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/3.0/
// or send a letter to:
//      Creative Commons
//      171 2nd Street, Suite 300
//      San Francisco, California, USA.

// #include <jni.h>
// #include <errno.h>

// #include <EGL/egl.h>
// #include <GLES/gl.h>

// #include <cstdio>

// #include <android/sensor.h>
// #include <android/log.h>
// #include <android_native_app_glue.h>

// #include <ghtv/main_state.hpp>

// #define GHTV_LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-activity", __VA_ARGS__))
// #define GHTV_LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "native-activity", __VA_ARGS__))

// namespace {

// int32_t handle_input(android_app* app, AInputEvent* event)
// {
//   GHTV_LOGI("input event");
//   return 0;
// }

// void init_display(ghtv::main_state* state, android_app* app)
// {
//   const EGLint attribs[] =
//   {
//     EGL_SURFACE_TYPE, EGL_WINDOW_BIT
//     , EGL_BLUE_SIZE, 8
//     , EGL_GREEN_SIZE, 8
//     , EGL_RED_SIZE, 8
//     , EGL_NONE
//   };
//   EGLint w, h, dummy, format;
//   EGLint numConfigs;
//   EGLConfig config;
//   EGLSurface surface;
//   EGLContext context;

//   EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
//   eglInitialize(display, 0, 0);

//   eglChooseConfig(display, attribs, &config, 1, &numConfigs);
  
//   eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &format);

//   ANativeWindow_setBuffersGeometry(app->window, 0, 0, format);

//   surface = eglCreateWindowSurface(display, config, app->window, NULL);

//   EGLint attribute_list[] = 
//     {EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE};

//   context = eglCreateContext(display, config, NULL, attribute_list);

//   if (eglMakeCurrent(display, surface, surface, context) == EGL_FALSE)
//   {
//     GHTV_LOGW("Unable to eglMakeCurrent");
//     return;
//   }

//   eglQuerySurface(display, surface, EGL_WIDTH, &w);
//   eglQuerySurface(display, surface, EGL_HEIGHT, &h);  

//   GHTV_LOGI("%d x %d", w, h);

//   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
//   //glEnable(GL_CULL_FACE);
//   glDisable(GL_CULL_FACE);
//   glShadeModel(GL_SMOOTH);
//   glDisable(GL_DEPTH_TEST);

//   GHTV_LOGI("Clearing color buffer");

//   //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//   float triangle[9] = {0.0f, 300.0f, 1.0f
//                        , 200.0f, 0.0f, 1.0f
//                        , -200.0f, 0.0f, 1.0f};

//   glMatrixMode(GL_PROJECTION);

//   float matrix[16] = 
//     {  -2.0f/w, 0.0f, 0.0f, 0.0f
//      , 0.0f, -2.0f/h, 0.0f, 0.0f
//      , 0.0f, 0.0f, 1.0f, 0.0f
//      , 0.0f, 0.0f, 0.0f, 1.0f };
//   glLoadMatrixf(matrix);

//   glMatrixMode(GL_MODELVIEW);
//   glLoadIdentity();

//   glViewport(0, 0, w, h);

//   glEnableClientState(GL_VERTEX_ARRAY);
//   glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
//   glVertexPointer(3, GL_FLOAT, 0, triangle);
//   glDrawArrays(GL_TRIANGLES, 0, 9);
//   glDisableClientState(GL_VERTEX_ARRAY);

//   glFlush();
//   glFinish();
//   eglSwapBuffers(display, surface);
// }

// void handle_cmd(android_app* app, int32_t cmd)
// {
//   ghtv::main_state* state = static_cast<ghtv::main_state*>(app->userData);
//   GHTV_LOGI("handle_cmd");
//   switch(cmd)
//   {
//   case APP_CMD_SAVE_STATE:
//     break;
//   case APP_CMD_INIT_WINDOW:
//     if(app->window)
//       init_display(state, app);
//     break;
//   case APP_CMD_TERM_WINDOW:
//     break;
//   case APP_CMD_GAINED_FOCUS:
//     break;
//   case APP_CMD_LOST_FOCUS:
//     break;
//   }
// }

// }

// void android_main(android_app* state)
// {
//   ghtv::main_state m_state;

//   app_dummy();

//   GHTV_LOGI("Started!");

//   state->onAppCmd = &handle_cmd;
//   state->onInputEvent = &handle_input;
//   state->userData = &m_state;

//   ASensorEventQueue* event_queue = ASensorManager_createEventQueue
//     (ASensorManager_getInstance(), state->looper, LOOPER_ID_USER, 0, 0);

//   int events, ident;
//   android_poll_source* source;

//   while(ident = ALooper_pollAll(-1, 0, &events, reinterpret_cast<void**>(&source)) >= 0)
//   {
//     GHTV_LOGI("Loop");

//     if(source)
//       source->process(state, source);

//     if(state->destroyRequested)
//       return;
//   }
// }

