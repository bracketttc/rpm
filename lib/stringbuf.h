#ifndef _STRINGBUF_H_
#define _STRINGBUF_H_

/** \file lib/stringbuf.h
 *
 */

/**
 */
typedef struct StringBufRec *StringBuf;

#ifdef __cplusplus
extern "C" {
#endif

/**
 */
StringBuf newStringBuf(void);

/**
 */
StringBuf freeStringBuf( StringBuf sb);

/**
 */
void truncStringBuf(StringBuf sb);

/**
 */
char * getStringBuf(StringBuf sb);

/**
 */
void stripTrailingBlanksStringBuf(StringBuf sb);

/**
 */
#define appendStringBuf(sb, s)     appendStringBufAux(sb, s, 0)

/**
 */
#define appendLineStringBuf(sb, s) appendStringBufAux(sb, s, 1)

/**
 */
void appendStringBufAux(StringBuf sb, const char * s, int nl);

#ifdef __cplusplus
}
#endif

#endif	/* _STRINGBUF_H_ */
