#ifndef TINYLIB_RTSP_SERVER_H
#define TINYLIB_RTSP_SERVER_H

struct rtsp_server;
typedef struct rtsp_server rtsp_server_t;

#include "tinylib/rtsp/rtsp_session.h"
#ifdef WIN32
  #include "tinylib/windows/net/loop.h"
#else
  #include "tinylib/linux/net/loop.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

rtsp_server_t* rtsp_server_new
(
    loop_t *loop, 
    rtsp_session_handler_f session_handler, 
    rtsp_session_interleaved_packet_f interleaved_sink, 
    void *userdata,
    unsigned short port, 
    const char* ip
);

void rtsp_server_destroy(rtsp_server_t *server);

void rtsp_server_start(rtsp_server_t *server);

void rtsp_server_stop(rtsp_server_t *server);

#ifdef __cplusplus
}
#endif

#endif /* !TINYLIB_RTSP_SERVER_H */

