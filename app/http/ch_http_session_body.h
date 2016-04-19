/*
 * =====================================================================================
 *
 *       Filename:  ch_http_session_body.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年02月24日 10时42分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  shajf (), csp001314@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef CH_HTTP_SESSION_BODY_H
#define CH_HTTP_SESSION_BODY_H

#include "ch_file.h"

typedef struct {
    ch_file_t file; /*the file innernest used to store body*/


    /*file name used to store body*/
    const char * fname; 
    
    /*if the body content has been chunk code,
     * then,this @chunk will poniter to a instance 
     * of ch_http_body_chunk_t ,used to store chunk state parsed*/
    ch_http_body_chunk_t *chunk; 
    
    /*if can known the body len from HTTP's header
     * ,then this @body_len value set to it's value*/
    size_t body_len;
    
    /*current body length has been accepted*/
    size_t body_len_accepted;

} ch_http_session_body_t;

/*Create an instance of session body
 * @mp,the memory pool instance used to create session body instance
 * @fname,the file name used to store body
 * @body_len,the total size of session body
 * return: if ok,return the instance of session body,otherwise return NULL*/
extern ch_http_session_body_t * ch_http_session_body_create(apr_pool_t *mp,const char *fname,size_t body_len);

/*Destroy an instance of session body
 * @body,the instance to destroy*/
extern void ch_http_session_body_destroy(ch_http_session_body_t *body);


/*Write data into body's file
 * @body,the instance of session body
 * @data,the data start address writting
 * @data_len,the data length writting
 * return: if ok,return CH_OK,otherwise return CH_ERROR*/
extern int ch_http_session_body_append(ch_http_session_body_t *body,void *data,size_t data_len);

#endif /* CH_HTTP_SESSION_BODY_H */

