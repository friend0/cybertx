#include "nanopbSerial.h"
#include <Print.h>
#include <Stream.h>

static bool pb_print_write(pb_ostream_t *stream, const pb_byte_t *buf, size_t count)
{
    Print *p = reinterpret_cast<Print *>(stream->state);
    size_t written = p->write(buf, count);
    return written == count;
};

pb_ostream_s pb_ostream_from_serial(Print &p)
{
    return {pb_print_write, &p, SIZE_MAX, 0};
};

static bool pb_stream_read(pb_istream_t *stream, pb_byte_t *buf, size_t count)
{
    Stream *s = reinterpret_cast<Stream *>(stream->state);
    size_t read = s->readBytes(buf, count);
    if (read == 0) {
        stream->bytes_left = 0;
        return false;
    }
    // stream->bytes_left-=read; 
    return read == count;
};

pb_istream_s pb_istream_from_serial(Stream &s, size_t msglen)
{
s.setTimeout(0);
#ifndef PB_NO_ERRMSG
    return {pb_stream_read, &s, msglen, 0};
#else
    return {pb_stream_read, &s, msglen};
#endif
};