#ifndef __BASIC_QUEUE_DRIVER_H__
#define __BASIC_QUEUE_DRIVER_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <util.h>

typedef enum { NULL_DRIVER  = 0,
               LSF_DRIVER   = 1,
               LOCAL_DRIVER = 2,
               RSH_DRIVER   = 3} job_driver_type;


typedef enum {JOB_QUEUE_NOT_ACTIVE    =  0 ,   /* This value is used in external query routines - for jobs which are not active. */
              JOB_QUEUE_LOADING       =  1 ,   /* This value is used by external routines. Not used in the libjob_queue implementation. */
              JOB_QUEUE_NULL          =  2 ,   /* For a queue node which has been allocated - but not (yet) "added" with a job_queue_add_job() call. */
	      JOB_QUEUE_WAITING       =  3 ,   /* A node which is waiting in the internal queue. */
	      JOB_QUEUE_PENDING       =  4 ,   /* A node which is pending - a status returned by the external system. I.e LSF */
	      JOB_QUEUE_RUNNING       =  5 ,   /* The job is running */
	      JOB_QUEUE_DONE          =  6 ,   /* The job is done - but we have not yet checked if the target file is produced */
	      JOB_QUEUE_EXIT          =  7 ,   /* The job has exited - check attempts to determine if we retry or go to complete_fail   */
	      JOB_QUEUE_RUN_OK        =  8 ,   /* The job has completed - and all checks performed by the queue layer indicate success. */
	      JOB_QUEUE_RUN_FAIL      =  9 ,   /* The job has completed - but the queue system has detected that it has failed.         */
              JOB_QUEUE_ALL_OK        = 10 ,   /* The job has loaded OK - observe that it is the calling scope which will set the status to this. */
              JOB_QUEUE_ALL_FAIL      = 11 ,   /* The job has failed completely - the calling scope must set this status. */
              JOB_QUEUE_USER_KILLED   = 12 ,   /* The job has been killed by the user. */
	      JOB_QUEUE_MAX_STATE     = 13 } job_status_type;





typedef struct basic_queue_driver_struct basic_queue_driver_type;
typedef struct basic_queue_job_struct    basic_queue_job_type;

typedef basic_queue_job_type * (submit_job_ftype)  	    (void * , int , const char * , const char * , const char * , const void *);
typedef void                   (kill_job_ftype)   	    (void * , basic_queue_job_type * );
typedef job_status_type        (get_status_ftype)  	    (void * , basic_queue_job_type * );
typedef void                   (free_job_ftype)    	    (void * , basic_queue_job_type * );
typedef void                   (free_queue_driver_ftype)    (void *);
typedef void                   (display_info_ftype)         (void * , basic_queue_job_type * );


struct basic_queue_job_struct {
  int __id;
};


#define QUEUE_DRIVER_FUNCTIONS                      \
submit_job_ftype  	   * submit;        	    \
free_job_ftype    	   * free_job;      	    \
kill_job_ftype   	   * kill_job;              \
get_status_ftype  	   * get_status;    	    \
free_queue_driver_ftype    * free_driver;   	    \
display_info_ftype         * display_info;          \
job_driver_type              driver_type;


struct basic_queue_driver_struct {
  UTIL_TYPE_ID_DECLARATION
  QUEUE_DRIVER_FUNCTIONS
};



void basic_queue_job_init(basic_queue_job_type * queue_job);


#ifdef __cplusplus
}
#endif
#endif
